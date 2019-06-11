#ifndef QHEXCURSOR_H
#define QHEXCURSOR_H

#include <QObject>

#define HEX_LINE_LENGTH      0x10
#define HEX_LINE_LAST_COLUMN (HEX_LINE_LENGTH - 1)

struct QHexPosition {
    uint64_t line, column, nibbleindex;

    QHexPosition() = default;
    QHexPosition(const QHexPosition&) = default;

    QHexPosition& operator=(const QHexPosition& rhs) {
        line = rhs.line;
        column = rhs.column;
        nibbleindex = rhs.nibbleindex;
        return *this;
    }

    uint64_t offset() const { return (line * HEX_LINE_LENGTH) + column; }
    uint64_t operator-(const QHexPosition& rhs) const { return this->offset() - rhs.offset(); }
    bool     operator==(const QHexPosition& rhs) const { return (line == rhs.line) && (column == rhs.column) && (nibbleindex == rhs.nibbleindex); }
    bool     operator!=(const QHexPosition& rhs) const { return (line != rhs.line) || (column != rhs.column) || (nibbleindex != rhs.nibbleindex); }
};

class QHexCursor : public QObject
{
    Q_OBJECT

    public:
        enum InsertionMode { OverwriteMode, InsertMode };

    public:
        explicit QHexCursor(QObject *parent = 0);

    public:
        const QHexPosition& selectionStart() const;
        const QHexPosition& selectionEnd() const;
        const QHexPosition& position() const;
        InsertionMode insertionMode() const;
        uint64_t selectionLength() const;
        uint64_t currentLine() const;
        uint64_t currentColumn() const;
        uint64_t currentNibble() const;
        uint64_t selectionLine() const;
        uint64_t selectionColumn() const;
        uint64_t selectionNibble() const;
        bool atEnd() const;
        bool isLineSelected(uint64_t line) const;
        bool hasSelection() const;
        void clearSelection();

    public:
        void moveTo(const QHexPosition& pos);
        void moveTo(uint64_t line, uint64_t column, uint64_t nibbleindex = 1);
        void moveTo(uint64_t offset);
        void select(const QHexPosition& pos);
        void select(uint64_t line, uint64_t column, uint64_t nibbleindex = 1);
        void select(uint64_t length);
        void selectOffset(uint64_t offset, uint64_t length);
        void setInsertionMode(InsertionMode mode);
        void switchInsertionMode();

    signals:
        void positionChanged();
        void insertionModeChanged();

    private:
        InsertionMode m_insertionmode;
        QHexPosition m_position, m_selection;
};

#endif // QHEXCURSOR_H
