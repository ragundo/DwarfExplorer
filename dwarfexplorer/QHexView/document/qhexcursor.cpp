#include "qhexcursor.h"
#include <QWidget>

QHexCursor::QHexCursor(QObject *parent) : QObject(parent), m_insertionmode(QHexCursor::OverwriteMode)
{
    m_position.line = m_position.column = 0;
    m_position.line = m_position.column = 0;

    m_selection.line = m_selection.column = 0;
    m_selection.line = m_selection.column = 0;

    m_position.nibbleindex = m_selection.nibbleindex = 1;
}

const QHexPosition &QHexCursor::selectionStart() const
{
    if(m_position.line < m_selection.line)
        return m_position;

    if(m_position.line == m_selection.line)
    {
        if(m_position.column < m_selection.column)
            return m_position;
    }

    return m_selection;
}

const QHexPosition &QHexCursor::selectionEnd() const
{
    if(m_position.line > m_selection.line)
        return m_position;

    if(m_position.line == m_selection.line)
    {
        if(m_position.column > m_selection.column)
            return m_position;
    }

    return m_selection;
}

const QHexPosition&       QHexCursor::position()        const { return m_position; }
QHexCursor::InsertionMode QHexCursor::insertionMode()   const { return m_insertionmode; }
uint64_t                  QHexCursor::selectionLength() const { return this->selectionEnd() - this->selectionStart() + 1;  }
uint64_t                  QHexCursor::currentLine()     const { return m_position.line; }
uint64_t                  QHexCursor::currentColumn()   const { return m_position.column; }
uint64_t                  QHexCursor::currentNibble()   const { return m_position.nibbleindex; }
uint64_t                  QHexCursor::selectionLine()   const { return m_selection.line; }
uint64_t                  QHexCursor::selectionColumn() const { return m_selection.column; }
uint64_t                  QHexCursor::selectionNibble() const { return m_selection.nibbleindex;  }

bool QHexCursor::isLineSelected(uint64_t line) const
{
    if(!this->hasSelection())
        return false;

    uint64_t first = std::min(m_position.line, m_selection.line);
    uint64_t last  = std::max(m_position.line, m_selection.line);

    if((line < first) || (line > last))
        return false;

    return true;
}

bool QHexCursor::hasSelection() const
{
    return m_position != m_selection;
}

void QHexCursor::clearSelection()
{
    m_selection = m_position;
    emit positionChanged();
}

void QHexCursor::moveTo(const QHexPosition &pos) { this->moveTo(pos.line, pos.column, pos.nibbleindex); }
void QHexCursor::select(const QHexPosition &pos) { this->select(pos.line, pos.column, pos.nibbleindex); }

void QHexCursor::moveTo(uint64_t line, uint64_t column, uint64_t nibbleindex)
{
    m_selection.line = line;
    m_selection.column = column;
    m_selection.nibbleindex = nibbleindex;

    this->select(line, column, nibbleindex);
}

void QHexCursor::select(uint64_t line, uint64_t column, uint64_t nibbleindex)
{
    m_position.line = line;
    m_position.column = column;
    m_position.nibbleindex = nibbleindex;

    emit positionChanged();
}

void QHexCursor::moveTo(uint64_t offset)
{
    uint64_t line = offset / HEX_LINE_LENGTH;
    this->moveTo(line, offset - (line * HEX_LINE_LENGTH));
}

void QHexCursor::select(uint64_t p_length)
{
    this->select(m_position.line, std::min(uint64_t(HEX_LINE_LAST_COLUMN), m_position.column + p_length - 1));
}

void QHexCursor::selectOffset(uint64_t offset, uint64_t length)
{
    this->moveTo(offset);
    this->select(length);
}

void QHexCursor::setInsertionMode(QHexCursor::InsertionMode mode)
{
    bool differentmode = (m_insertionmode != mode);
    m_insertionmode = mode;

	if (differentmode)
		emit insertionModeChanged();
}

void QHexCursor::switchInsertionMode()
{
    if(m_insertionmode == QHexCursor::OverwriteMode)
        m_insertionmode = QHexCursor::InsertMode;
    else
        m_insertionmode = QHexCursor::OverwriteMode;

    emit insertionModeChanged();
}
