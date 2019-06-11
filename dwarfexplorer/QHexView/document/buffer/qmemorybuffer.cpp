#include "qmemorybuffer.h"

QMemoryBuffer::QMemoryBuffer(QObject *parent) : QHexBuffer(parent)
{
}

uchar QMemoryBuffer::at(uint64_t idx)
{
    return static_cast<uchar>(m_buffer.at(idx));
}

uint64_t QMemoryBuffer::length() const
{
    return m_buffer.length();
}

void QMemoryBuffer::insert(uint64_t offset, const QByteArray &data)
{
    m_buffer.insert(offset, data);
}

void QMemoryBuffer::remove(uint64_t offset, uint64_t length)
{
    m_buffer.remove(offset, length);
}

QByteArray QMemoryBuffer::read(uint64_t offset, uint64_t length)
{
    return m_buffer.mid(offset, length);
}

void QMemoryBuffer::read(QIODevice *device)
{
    m_buffer = device->readAll();
}

void QMemoryBuffer::write(QIODevice *device)
{
    device->write(m_buffer);
}
