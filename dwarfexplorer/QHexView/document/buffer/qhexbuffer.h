#ifndef QHEXBUFFER_H
#define QHEXBUFFER_H

#include <QObject>
#include <QIODevice>

class QHexBuffer : public QObject
{
    Q_OBJECT

    public:
        explicit QHexBuffer(QObject *parent = nullptr);
        bool isEmpty() const;

    public:
        virtual uchar at(uint64_t idx);
        virtual void  replace(uint64_t offset, const QByteArray& data);
        virtual void  read(char* data, uint64_t size);
        virtual void  read(const QByteArray& ba);

    public:
        virtual uint64_t   length() const = 0;
        virtual void       insert(uint64_t offset, const QByteArray& data) = 0;
        virtual void       remove(uint64_t offset, uint64_t length) = 0;
        virtual QByteArray read(uint64_t offset, uint64_t length) = 0;
        virtual void       read(QIODevice* iodevice) = 0;
        virtual void       write(QIODevice* iodevice) = 0;
};

#endif // QHEXBUFFER_H
