#ifndef QHEXMETADATA_H
#define QHEXMETADATA_H

#include <QLinkedList>
#include <QObject>
#include <QColor>
#include <QHash>

struct QHexMetadataItem
{
    uint64_t line, start, length;
    QColor foreground, background;
    QString comment;
};

typedef QLinkedList<QHexMetadataItem> QHexLineMetadata;

class QHexMetadata : public QObject
{
    Q_OBJECT

    public:
        explicit QHexMetadata(QObject *parent = nullptr);
        const QHexLineMetadata& get(uint64_t line) const;
        QString                 comments(uint64_t line) const;
        bool                    hasMetadata(uint64_t line) const;
        void                    clear(uint64_t line);
        void                    clear();

    public:
        void metadata(uint64_t line, uint64_t start, uint64_t length, const QColor& fgcolor, const QColor& bgcolor, const QString& comment);
        void color(uint64_t line, uint64_t start, uint64_t length, const QColor& fgcolor, const QColor& bgcolor);
        void foreground(uint64_t line, uint64_t start, uint64_t length, const QColor& fgcolor);
        void background(uint64_t line, uint64_t start, uint64_t length, const QColor& bgcolor);
        void comment(uint64_t line, uint64_t start, uint64_t length, const QString &comment);

    private:
        void setMetadata(const QHexMetadataItem& mi);

    signals:
        void metadataChanged(uint64_t line);
        void metadataCleared();

    private:
        QHash<uint64_t, QHexLineMetadata> m_metadata;
};

#endif // QHEXMETADATA_H
