#ifndef QMEMORYBUFFER_H
#define QMEMORYBUFFER_H

#include "qhexbuffer.h"

class QMemoryBuffer : public QHexBuffer
{
    Q_OBJECT

    public:
        explicit QMemoryBuffer(QObject *parent = nullptr);

        uchar      at(uint64_t idx) override;
        uint64_t   length() const override;
        void       insert(uint64_t offset, const QByteArray& data) override;
        void       remove(uint64_t offset, uint64_t length) override;
        QByteArray read(uint64_t offset, uint64_t length) override;
        void       read(QIODevice* device) override;
        void       write(QIODevice* device) override;

    private:
        QByteArray m_buffer;
};

#endif // QMEMORYBUFFER_H
