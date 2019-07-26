#include "qhexdocument.h"
#include "commands/insertcommand.h"
#include "commands/removecommand.h"
#include "commands/replacecommand.h"
#include <QApplication>
#include <QClipboard>
#include <QBuffer>
#include <QFile>


QByteArray to_hex(QByteArray& p_qbytearray, char p_separator)
{
    auto size = p_qbytearray.size();
    if ( size == 0)
        return QByteArray();

    const int length = p_separator ? (size * 3 - 1) : (size * 2);
    QByteArray hex(length, Qt::Uninitialized);
    char *hexData = hex.data();
    const uchar *data = (const uchar *)p_qbytearray.data();

    for (int i = 0, o = 0; i < size; ++i)
    {
        auto value = data[i] >> 4;
        hexData[o++] = "0123456789abcdef"[value & 0xF];
        value = data[i] & 0xf;
        hexData[o++] = "0123456789abcdef"[value & 0xF];
        if ((p_separator) && (o < length))
            hexData[o++] = p_separator;
    }
    return hex;
}

QHexDocument::QHexDocument(QHexBuffer *buffer, QObject *parent): QObject(parent), m_baseaddress(0)
{
    m_buffer = buffer;
    m_buffer->setParent(this); // Take Ownership

    m_cursor = new QHexCursor(this);
    m_metadata = new QHexMetadata(this);

    connect(m_metadata, &QHexMetadata::metadataChanged, this, &QHexDocument::lineChanged);
    connect(m_metadata, &QHexMetadata::metadataCleared, this, &QHexDocument::documentChanged);

    connect(&m_undostack, &QUndoStack::canUndoChanged, this, &QHexDocument::canUndoChanged);
    connect(&m_undostack, &QUndoStack::canRedoChanged, this, &QHexDocument::canRedoChanged);
}

bool          QHexDocument::isEmpty()     const { return m_buffer->isEmpty(); }
bool          QHexDocument::atEnd()       const { return m_cursor->position().offset() >= m_buffer->length(); }
bool          QHexDocument::canUndo()     const { return m_undostack.canUndo(); }
bool          QHexDocument::canRedo()     const { return m_undostack.canRedo(); }
uint64_t      QHexDocument::length()      const { return m_buffer->length(); }
uint64_t      QHexDocument::baseAddress() const { return m_baseaddress; }
QHexCursor*   QHexDocument::cursor()      const { return m_cursor; }
QHexMetadata* QHexDocument::metadata()    const { return m_metadata; }

QByteArray    QHexDocument::read(uint64_t offset, uint64_t len) { return m_buffer->read(offset, len); }

void QHexDocument::removeSelection()
{
    if(!m_cursor->hasSelection())
        return;

    this->remove(m_cursor->selectionStart().offset(), m_cursor->selectionLength());
    m_cursor->clearSelection();
}

QByteArray QHexDocument::selectedBytes() const
{
    if(!m_cursor->hasSelection())
        return QByteArray();

    return m_buffer->read(m_cursor->selectionStart().offset(), m_cursor->selectionLength());
}

char QHexDocument::at(uint64_t offset) const { return m_buffer->at(offset); }

void QHexDocument::setBaseAddress(uint64_t baseaddress)
{
    if(m_baseaddress == baseaddress)
        return;

    m_baseaddress = baseaddress;
    emit documentChanged();
}

void QHexDocument::sync() { emit documentChanged(); }

void QHexDocument::undo()
{
    m_undostack.undo();
    emit documentChanged();
}

void QHexDocument::redo()
{
    m_undostack.redo();
    emit documentChanged();
}

void QHexDocument::cut(bool hex)
{
    if(!m_cursor->hasSelection())
        return;

    this->copy(hex);
    this->removeSelection();
}

void QHexDocument::copy(bool hex)
{
    if(!m_cursor->hasSelection())
        return;

    QClipboard* c = qApp->clipboard();
    QByteArray bytes = this->selectedBytes();

    if(hex)
        //bytes = bytes.toHex(' ').toUpper();
        bytes = to_hex(bytes, ' ').toUpper();

    c->setText(bytes);
}

void QHexDocument::paste(bool hex)
{
    QClipboard* c = qApp->clipboard();
    QByteArray data = c->text().toUtf8();

    if(data.isEmpty())
        return;

    this->removeSelection();

    if(hex)
        data = QByteArray::fromHex(data);

    if(m_cursor->insertionMode() == QHexCursor::InsertMode)
        this->insert(m_cursor->position().offset(), data);
    else
        this->replace(m_cursor->position().offset(), data);
}

void QHexDocument::insert(uint64_t offset, uchar b)
{
    this->insert(offset, QByteArray(1, b));
}

void QHexDocument::replace(uint64_t offset, uchar b)
{
    this->replace(offset, QByteArray(1, b));
}

void QHexDocument::insert(uint64_t offset, const QByteArray &data)
{
    m_undostack.push(new InsertCommand(m_buffer, offset, data));
    emit documentChanged();
}

void QHexDocument::replace(uint64_t offset, const QByteArray &data)
{
    m_undostack.push(new ReplaceCommand(m_buffer, offset, data));
    emit documentChanged();
}

void QHexDocument::remove(uint64_t offset, uint64_t len)
{
    m_undostack.push(new RemoveCommand(m_buffer, offset, len));
    emit documentChanged();
}

QByteArray QHexDocument::read(uint64_t p_offset, uint64_t p_len) const
{
    return m_buffer->read(p_offset, p_len);
}

bool QHexDocument::saveTo(QIODevice *device)
{
    if(!device->isWritable())
        return false;

    m_buffer->write(device);
    return true;
}
