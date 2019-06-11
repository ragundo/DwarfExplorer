#include "qmemoryrefbuffer.h"

QMemoryRefBuffer::QMemoryRefBuffer(QObject *parent): QHexBuffer(parent) { }
uint64_t QMemoryRefBuffer::length() const
{
    return m_buffer->size();
}

void     QMemoryRefBuffer::insert(uint64_t, const QByteArray &) { /* Insertion unsupported */ }
void     QMemoryRefBuffer::remove(uint64_t offset, uint64_t length) { /* Deletion unsupported */ }

QByteArray QMemoryRefBuffer::read(uint64_t offset, uint64_t length)
{
    m_buffer->seek(offset);
    return m_buffer->read(length);
}

void QMemoryRefBuffer::read(QIODevice *device)
{
    m_buffer = dynamic_cast<QBuffer*>(device);
}

void QMemoryRefBuffer::write(QIODevice *device)
{
    m_buffer->seek(0);
    device->write(m_buffer->readAll());
}
