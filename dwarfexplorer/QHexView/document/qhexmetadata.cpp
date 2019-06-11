#include "qhexmetadata.h"

QHexMetadata::QHexMetadata(QObject *parent) : QObject(parent) { }

const QHexLineMetadata &QHexMetadata::get(uint64_t line) const
{
    auto it = m_metadata.find(line);
    return it.value();
}

QString QHexMetadata::comments(uint64_t line) const
{
    if(!this->hasMetadata(line))
        return QString();

    QString s;

    const auto& linemetadata = this->get(line);

    for(auto& mi : linemetadata)
    {
        if(mi.comment.isEmpty())
            continue;

        if(!s.isEmpty())
            s += "\n";

        s += mi.comment;
    }

    return s;
}

bool QHexMetadata::hasMetadata(uint64_t line) const { return m_metadata.contains(line); }

void QHexMetadata::clear(uint64_t line)
{
    auto it = m_metadata.find(line);

    if(it == m_metadata.end())
        return;

    m_metadata.erase(it);
    emit metadataChanged(line);
}

void QHexMetadata::clear()
{
    m_metadata.clear();
    emit metadataCleared();
}

void QHexMetadata::metadata(uint64_t line, uint64_t start, uint64_t length, const QColor &fgcolor, const QColor &bgcolor, const QString &comment)
{
    this->setMetadata({ line, start, length, fgcolor, bgcolor, comment});
}

void QHexMetadata::color(uint64_t line, uint64_t start, uint64_t length, const QColor &fgcolor, const QColor &bgcolor)
{
    this->metadata(line, start, length, fgcolor, bgcolor, QString());
}

void QHexMetadata::foreground(uint64_t line, uint64_t start, uint64_t length, const QColor &fgcolor)
{
    this->color(line, start, length, fgcolor, QColor());
}

void QHexMetadata::background(uint64_t line, uint64_t start, uint64_t length, const QColor &bgcolor)
{
    this->color(line, start, length, QColor(), bgcolor);
}

void QHexMetadata::comment(uint64_t line, uint64_t start, uint64_t length, const QString &comment)
{
    this->metadata(line, start, length, QColor(), QColor(), comment);
}

void QHexMetadata::setMetadata(const QHexMetadataItem &mi)
{
    if(!m_metadata.contains(mi.line))
    {
        QHexLineMetadata linemetadata;
        linemetadata << mi;
        m_metadata[mi.line] = linemetadata;
    }
    else
    {
        QHexLineMetadata& linemetadata = m_metadata[mi.line];
        linemetadata << mi;
    }

    emit metadataChanged(mi.line);
}
