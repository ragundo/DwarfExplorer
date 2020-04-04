#ifndef QHEXDOCUMENT_H
#define QHEXDOCUMENT_H

#include "buffer/qhexbuffer.h"
#include "qhexcursor.h"
#include "qhexmetadata.h"
#include <QFile>
#include <QUndoStack>
#include <cctype>

class QHexDocument : public QObject
{
    Q_OBJECT

  private:
    explicit QHexDocument(QHexBuffer* buffer, QObject* parent = nullptr);

  public:
    bool          isEmpty() const;
    bool          atEnd() const;
    bool          canUndo() const;
    bool          canRedo() const;
    uint64_t      length() const;
    uint64_t      baseAddress() const;
    QHexCursor*   cursor() const;
    QHexMetadata* metadata() const;

  public:
    void       removeSelection();
    QByteArray read(uint64_t offset, uint64_t len = 0);
    QByteArray selectedBytes() const;
    char       at(uint64_t offset) const;
    void       setBaseAddress(uint64_t baseaddress);
    void       sync();

  public slots:
    void       undo();
    void       redo();
    void       cut(bool hex = false);
    void       copy(bool hex = false);
    void       paste(bool hex = false);
    void       insert(uint64_t offset, uchar b);
    void       replace(uint64_t offset, uchar b);
    void       insert(uint64_t offset, const QByteArray& data);
    void       replace(uint64_t offset, const QByteArray& data);
    void       remove(uint64_t offset, uint64_t len);
    QByteArray read(uint64_t offset, uint64_t len) const;
    bool       saveTo(QIODevice* device);

  public:
    template<typename T>
    static QHexDocument* fromDevice(QIODevice* iodevice, QObject* parent = nullptr);
    template<typename T>
    static QHexDocument* fromFile(QString filename, QObject* parent = nullptr);
    template<typename T>
    static QHexDocument* fromMemory(char* data, uint64_t size, QObject* parent = nullptr);
    template<typename T>
    static QHexDocument* fromMemory(const QByteArray& ba, QObject* parent = nullptr);

  signals:
    void canUndoChanged();
    void canRedoChanged();
    void documentChanged();
    void lineChanged(int line);

  private:
    QHexBuffer*   m_buffer;
    QHexMetadata* m_metadata;
    QUndoStack    m_undostack;
    QHexCursor*   m_cursor;
    uint64_t      m_baseaddress;
};

template<typename T>
QHexDocument* QHexDocument::fromDevice(QIODevice* iodevice, QObject* parent)
{
    bool needsclose = false;

    if (!iodevice->isOpen())
    {
        needsclose = true;
        iodevice->open(QIODevice::ReadWrite);
    }

    QHexBuffer* hexbuffer = new T();
    hexbuffer->read(iodevice);

    if (needsclose)
        iodevice->close();

    return new QHexDocument(hexbuffer, parent);
}

template<typename T>
QHexDocument* QHexDocument::fromFile(QString filename, QObject* parent)
{
    QFile f(filename);
    f.open(QFile::ReadOnly);

    QHexDocument* doc = QHexDocument::fromDevice<T>(&f, parent);
    f.close();
    return doc;
}

template<typename T>
QHexDocument* QHexDocument::fromMemory(char* p_data, uint64_t p_size, QObject* p_parent)
{
    QHexBuffer* hexbuffer = new T();
    hexbuffer->read(p_data, p_size);
    return new QHexDocument(hexbuffer, p_parent);
}

template<typename T>
QHexDocument* QHexDocument::fromMemory(const QByteArray& ba, QObject* parent)
{
    QHexBuffer* hexbuffer = new T();
    hexbuffer->read(ba);
    return new QHexDocument(hexbuffer, parent);
}

#endif // QHEXEDITDATA_H
