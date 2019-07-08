#include "qhexbuffer.h"
#include <QBuffer>

QHexBuffer::QHexBuffer(QObject *parent) : QObject(parent) { }

uchar QHexBuffer::at(uint64_t idx)
{
        return this->read(idx, 1)[0];
}

bool QHexBuffer::isEmpty() const
{
    return this->length() <= 0;
}

void QHexBuffer::replace(uint64_t offset, const QByteArray &data)
{
    this->remove(offset, data.length());
    this->insert(offset, data);
}

void QHexBuffer::read(char *data, uint64_t size)
{
    QBuffer* buffer = new QBuffer(this);
    buffer->setData(data, size);

    if(!buffer->isOpen())
        buffer->open(QBuffer::ReadWrite);

    this->read(buffer);
}

void QHexBuffer::read(const QByteArray &ba)
{
    QBuffer* buffer = new QBuffer(this);

    if(!buffer->isOpen())
        buffer->open(QBuffer::ReadWrite);

    buffer->setData(ba);
    this->read(buffer);
}