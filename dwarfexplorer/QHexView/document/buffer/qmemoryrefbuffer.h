#ifndef QMEMORYREFBUFFER_H
#define QMEMORYREFBUFFER_H

#include "qhexbuffer.h"
#include "qbuffer.h"

class QMemoryRefBuffer : public QHexBuffer
{
    Q_OBJECT

    public:
        explicit   QMemoryRefBuffer(QObject *parent = nullptr);
        uint64_t   length() const override;
        void       insert(uint64_t, const QByteArray&) override;
        void       remove(uint64_t offset, uint64_t length) override;
        QByteArray read(uint64_t offset, uint64_t length) override;
        void       read(QIODevice* device) override;
        void       write(QIODevice* device) override;

    private:
        QBuffer* m_buffer;
};

#endif // QMEMORYREFBUFFER_H
