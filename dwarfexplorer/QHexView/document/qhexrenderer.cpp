#include "qhexrenderer.h"
#include <QApplication>
#include <QTextCursor>
#include <QWidget>
#include <cctype>
#include <cmath>

#define HEX_UNPRINTABLE_CHAR     '.'

QHexRenderer::QHexRenderer(QHexDocument* document, const QFontMetrics &fontmetrics, QObject *parent) : QObject(parent), m_document(document), m_fontmetrics(fontmetrics)
{
    m_selectedarea = QHexRenderer::HexArea;
    m_cursorenabled = false;
}

void QHexRenderer::renderFrame(QPainter *painter)
{
    QWidget* widget = dynamic_cast<QWidget*>(painter->device());

    if(!widget)
        return;

    QRect rect = widget->rect();
    uint64_t hexx = this->getHexColumnX();
    uint64_t asciix = this->getAsciiColumnX();
    uint64_t endx = this->getEndColumnX();

    painter->drawLine(rect.x() + hexx,
                      rect.top(),
                      rect.x() + hexx,
                      rect.bottom());

    painter->drawLine(rect.x() + asciix,
                      rect.top(),
                      rect.x() + asciix,
                      rect.bottom());

    painter->drawLine(rect.x() + endx,
                      rect.top(),
                      rect.x() + endx,
                      rect.bottom());
}

void QHexRenderer::render(QPainter *painter, uint64_t p_start, uint64_t p_count, uint64_t p_firstline)
{
    uint64_t end = p_start + p_count;
    QPalette palette = qApp->palette();

    for(uint64_t line = p_start; line < std::min(end, this->documentLines()); line++)
    {
        QRect linerect = this->getLineRect(line, p_firstline);

        if(line % 2)
            painter->fillRect(linerect, palette.brush(QPalette::Window));
        else
            painter->fillRect(linerect, palette.brush(QPalette::Base));

        this->drawAddress(painter, palette, linerect, line);
        this->drawHex(painter, palette, linerect, line);
        this->drawAscii(painter, palette, linerect, line);
    }
}

void QHexRenderer::enableCursor(bool b) { m_cursorenabled = b; }

void QHexRenderer::selectArea(const QPoint &pt)
{
    uint64_t area = this->hitTestArea(pt);

    if (area == QHexRenderer::AddressArea)
        return;

    m_selectedarea = area;
}

bool QHexRenderer::hitTest(const QPoint &p_pt, QHexPosition* p_position, uint64_t p_firstline) const
{
    uint64_t area = this->hitTestArea(p_pt);

    if (area == QHexRenderer::AddressArea)
        return false;

    p_position->line = std::min(p_firstline + (p_pt.y() / this->lineHeight()), this->documentLastLine());

    if(area == QHexRenderer::HexArea)
    {
        uint64_t relx = p_pt.x() - this->getHexColumnX();
        p_position->column = relx / (this->getCellWidth() * 3);
        p_position->nibbleindex = this->getNibbleIndex(p_position->line, relx);
    }
    else
    {
        uint64_t relx = p_pt.x() - this->getAsciiColumnX() - this->getCellWidth();
        p_position->column = relx / this->getCellWidth();
        p_position->nibbleindex = 1;
    }

    if(p_position->line == this->documentLastLine()) // Check last line's columns
    {
        QByteArray ba = this->getLine(p_position->line);
        p_position->column = std::min(p_position->column, uint64_t(ba.length()));
    }
    else
        p_position->column = std::min(p_position->column, uint64_t(HEX_LINE_LAST_COLUMN));

    return true;
}

uint64_t QHexRenderer::hitTestArea(const QPoint &pt) const
{
    if((pt.x() >= 0) && (pt.x() <= this->getHexColumnX()))
        return QHexRenderer::AddressArea;

    if((pt.x() > this->getHexColumnX()) && (pt.x() < this->getAsciiColumnX()))
        return QHexRenderer::HexArea;

    if((pt.x() > this->getAsciiColumnX()) && (pt.x() < this->getEndColumnX()))
        return QHexRenderer::AsciiArea;

    return QHexRenderer::ExtraArea;
}

uint64_t QHexRenderer::selectedArea() const                                 { return m_selectedarea; }
uint64_t QHexRenderer::documentLastLine() const                             { return this->documentLines() - 1; }
uint64_t QHexRenderer::documentLastColumn() const                           { return this->getLine(this->documentLastLine()).length(); }
uint64_t QHexRenderer::documentLines() const                                { return std::ceil(this->rendererLength() / static_cast<float>(HEX_LINE_LENGTH));  }
uint64_t QHexRenderer::documentWidth() const                                { return this->getAsciiColumnX() + (this->getCellWidth() * (HEX_LINE_LENGTH + 1)); }
uint64_t QHexRenderer::lineHeight() const                                   { return m_fontmetrics.height(); }
QRect    QHexRenderer::getLineRect(uint64_t line, uint64_t firstline) const { return QRect(0, (line - firstline) * m_fontmetrics.height(), this->getEndColumnX(), m_fontmetrics.height()); }

QString QHexRenderer::hexString(uint64_t p_line, QByteArray* p_rawline) const
{
    QByteArray lrawline = this->getLine(p_line);

    if(p_rawline)
        *p_rawline = lrawline;

    return lrawline.toHex(' ').toUpper() + " ";
}

QString QHexRenderer::asciiString(uint64_t p_line, QByteArray* p_rawline) const
{
    QByteArray lrawline = this->getLine(p_line);

    if(p_rawline)
        *p_rawline = lrawline;

    QByteArray ascii = lrawline;
    this->unprintableChars(ascii);
    return ascii;
}

QByteArray QHexRenderer::getLine(uint64_t p_line) const { return m_document->read(p_line * HEX_LINE_LENGTH, HEX_LINE_LENGTH); }
void       QHexRenderer::blinkCursor() { m_cursorenabled = !m_cursorenabled; }
uint64_t   QHexRenderer::rendererLength() const { return m_document->length() + 1; }

uint64_t QHexRenderer::getAddressWidth() const
{
    uint64_t adjusted_length = m_document->baseAddress() + this->rendererLength();
/*
    if (adjusted_length <= 0xFFFF)
        return 8;

    if (adjusted_length) <= 0xFFFFFFFF)
        return 16;
*/
    return QString::number(adjusted_length, 16).length();
}

uint64_t QHexRenderer::getHexColumnX() const   { return this->getCellWidth() * (this->getAddressWidth() + 1); }
uint64_t QHexRenderer::getAsciiColumnX() const { return this->getHexColumnX() + (this->getCellWidth() * (HEX_LINE_LENGTH * 3 + 3)); }
uint64_t QHexRenderer::getEndColumnX() const   { return this->getAsciiColumnX() + (this->getCellWidth() * (HEX_LINE_LENGTH + 1 + 3)); }

uint64_t QHexRenderer::getCellWidth() const
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
    return m_fontmetrics.horizontalAdvance(" ");
#else
    return m_fontmetrics.width(" ");
#endif
}

uint64_t QHexRenderer::getNibbleIndex(uint64_t p_line, uint64_t p_relx) const
{
    p_relx -= this->getCellWidth(); // Remove padding
    QString hexstring = this->hexString(p_line);

    for(auto i = 0; i < hexstring.size(); i++)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
        uint64_t x = m_fontmetrics.horizontalAdvance(hexstring, i + 1);
#else
        uint64_t x = m_fontmetrics.width(hexstring, i + 1);
#endif
        if(x < p_relx)
            continue;

        if((i == (hexstring.size() - 1)) || (hexstring[i + 1] == ' '))
            return 0;

        break;
    }

    return 1;
}

void QHexRenderer::unprintableChars(QByteArray &ascii) const
{
    for(char& ch : ascii)
    {
        if(std::isprint(ch))
            continue;

        ch = HEX_UNPRINTABLE_CHAR;
    }
}

void QHexRenderer::applyDocumentStyles(QPainter *painter, QTextDocument* textdocument) const
{
    textdocument->setDocumentMargin(0);
    textdocument->setUndoRedoEnabled(false);
    textdocument->setDefaultFont(painter->font());
}

void QHexRenderer::applyBasicStyle(QTextCursor &textcursor, const QByteArray &rawline, uint64_t factor) const
{
    QPalette palette = qApp->palette();
    QColor color = palette.color(QPalette::WindowText);

    if(color.lightness() < 50)
    {
        if(color == Qt::black)
            color = Qt::gray;
        else
            color = color.lighter();
    }
    else
        color = color.darker();

    QTextCharFormat charformat;
    charformat.setForeground(color);

    for(auto i = 0; i < rawline.length(); i++)
    {
//        if((rawline[i] != 0x00) && (static_cast<uchar>(rawline[i]) != 0xFF))
        if(rawline[i] != 0x00)
            continue;

        textcursor.setPosition(i * factor);
        textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, factor);
        textcursor.setCharFormat(charformat);
    }
}

void QHexRenderer::applyMetadata(QTextCursor &textcursor, uint64_t p_line, uint64_t p_factor) const
{
    QHexMetadata* metadata = m_document->metadata();

    if(!metadata->hasMetadata(p_line))
        return;

    const QHexLineMetadata& linemetadata = metadata->get(p_line);

    for(const QHexMetadataItem& mi : linemetadata)
    {
        QTextCharFormat charformat;

        if(mi.background.isValid())
            charformat.setBackground(mi.background);

        if(mi.foreground.isValid())
            charformat.setForeground(mi.foreground);

        if(!mi.comment.isEmpty())
            charformat.setUnderlineStyle(QTextCharFormat::SingleUnderline);

        textcursor.setPosition(mi.start * p_factor);
        textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, (mi.length * p_factor) - (p_factor > 1 ? 1 : 0));
        textcursor.setCharFormat(charformat);
    }
}

void QHexRenderer::applySelection(QTextCursor &textcursor, uint64_t p_line, uint64_t p_factor) const
{
    QHexCursor* cursor = m_document->cursor();

    if(!cursor->isLineSelected(p_line))
        return;

    const QHexPosition& startsel = cursor->selectionStart();
    const QHexPosition& endsel = cursor->selectionEnd();

    if(startsel.line == endsel.line)
    {
        textcursor.setPosition(startsel.column * p_factor);
        textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, ((endsel.column - startsel.column + 1) * p_factor) - 1);
    }
    else
    {
        if(p_line == startsel.line)
            textcursor.setPosition(startsel.column * p_factor);
        else
            textcursor.setPosition(0);

        if(p_line == endsel.line)
            textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, ((endsel.column + 1) * p_factor) - 1);
        else
            textcursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
    }

    QPalette palette = qApp->palette();

    QTextCharFormat charformat;
    charformat.setBackground(palette.color(QPalette::Highlight));
    charformat.setForeground(palette.color(QPalette::HighlightedText));
    textcursor.setCharFormat(charformat);
}

void QHexRenderer::applyCursorAscii(QTextCursor &textcursor, uint64_t p_line) const
{
    QHexCursor* cursor = m_document->cursor();

    if((p_line != cursor->currentLine()) || !m_cursorenabled)
        return;

    textcursor.clearSelection();
    textcursor.setPosition(m_document->cursor()->currentColumn());
    textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);

    QPalette palette = qApp->palette();

    QTextCharFormat charformat;

    if((cursor->insertionMode() == QHexCursor::OverwriteMode) || (m_selectedarea != QHexRenderer::AsciiArea))
    {
        charformat.setForeground(palette.color(QPalette::Window));

        if(m_selectedarea == QHexRenderer::AsciiArea)
            charformat.setBackground(palette.color(QPalette::WindowText));
        else
            charformat.setBackground(palette.color(QPalette::WindowText).lighter(250));
    }
    else
    {
        charformat.setUnderlineStyle(QTextCharFormat::UnderlineStyle::SingleUnderline);
    }

    textcursor.setCharFormat(charformat);
}

void QHexRenderer::applyCursorHex(QTextCursor &textcursor, uint64_t p_line) const
{
    QHexCursor* cursor = m_document->cursor();

    if ((p_line != cursor->currentLine()) || !m_cursorenabled)
        return;

    textcursor.clearSelection();
    textcursor.setPosition(m_document->cursor()->currentColumn() * 3);

    if((m_selectedarea == QHexRenderer::HexArea) && !m_document->cursor()->currentNibble())
        textcursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor);

    textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);

    if (m_selectedarea == QHexRenderer::AsciiArea)
        textcursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);

    QPalette palette = qApp->palette();
    QTextCharFormat charformat;

    if ((cursor->insertionMode() == QHexCursor::OverwriteMode) || (m_selectedarea != QHexRenderer::HexArea))
    {
        charformat.setForeground(palette.color(QPalette::Window));

        if (m_selectedarea == QHexRenderer::HexArea)
            charformat.setBackground(palette.color(QPalette::WindowText));
        else
            charformat.setBackground(palette.color(QPalette::WindowText).lighter(250));
    }
    else
        charformat.setUnderlineStyle(QTextCharFormat::UnderlineStyle::SingleUnderline);

    textcursor.setCharFormat(charformat);
}

void QHexRenderer::drawAddress(QPainter* painter, const QPalette& palette, const QRect& linerect, uint64_t p_line)
{
    QRect addressrect = linerect;
    addressrect.setWidth(this->getHexColumnX());

    painter->save();
    painter->setPen(palette.color(QPalette::Highlight));

    painter->drawText(addressrect, Qt::AlignHCenter | Qt::AlignVCenter, QString("%1").arg(p_line * HEX_LINE_LENGTH + m_document->baseAddress(),
                                                                                          this->getAddressWidth(), 16,
                                                                                          QLatin1Char('0')).toUpper());
    painter->restore();
}

void QHexRenderer::drawHex(QPainter *painter, const QPalette &palette, const QRect &linerect, uint64_t p_line)
{
    QTextDocument textdocument;
    QTextCursor textcursor(&textdocument);
    QByteArray rawline;

    textcursor.insertText(this->hexString(p_line, &rawline));

    if (p_line == this->documentLastLine())
        textcursor.insertText(" ");

    QRect hexrect = linerect;
    hexrect.setX(this->getHexColumnX() + this->getCellWidth());

    this->applyDocumentStyles(painter, &textdocument);
    this->applyBasicStyle(textcursor, rawline, 3);
    this->applyMetadata(textcursor, p_line, 3);
    this->applySelection(textcursor, p_line, 3);
    this->applyCursorHex(textcursor, p_line);

    painter->save();
    painter->translate(hexrect.topLeft());
    textdocument.drawContents(painter);
    painter->restore();
}

void QHexRenderer::drawAscii(QPainter *painter, const QPalette &palette, const QRect &linerect, uint64_t p_line)
{
    QTextDocument textdocument;
    QTextCursor textcursor(&textdocument);
    QByteArray rawline;
    textcursor.insertText(this->asciiString(p_line, &rawline));

    if(p_line == this->documentLastLine())
        textcursor.insertText(" ");

    QRect asciirect = linerect;
    asciirect.setX(this->getAsciiColumnX() + this->getCellWidth());

    this->applyDocumentStyles(painter, &textdocument);
    this->applyBasicStyle(textcursor, rawline);
    this->applyMetadata(textcursor, p_line);
    this->applySelection(textcursor, p_line);
    this->applyCursorAscii(textcursor, p_line);

    painter->save();
    painter->translate(asciirect.topLeft());
    textdocument.drawContents(painter);
    painter->restore();
}
