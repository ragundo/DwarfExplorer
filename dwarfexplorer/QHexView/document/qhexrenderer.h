#ifndef QHEXRENDERER_H
#define QHEXRENDERER_H

/*
 * Nibble encoding:
 *           AB -> [A][B]
 * Nibble Index:    1  0
 */

#include <QTextDocument>
#include <QPainter>
#include "qhexdocument.h"

class QHexRenderer : public QObject
{
    Q_OBJECT

    public:
        enum { AddressArea, HexArea, AsciiArea, ExtraArea };

    public:
        explicit QHexRenderer(QHexDocument* document, const QFontMetrics& fontmetrics, QObject *parent = nullptr);
        void renderFrame(QPainter* painter);
        void render(QPainter* painter, uint64_t start, uint64_t count, uint64_t firstline);
        void enableCursor(bool b = true);
        void selectArea(const QPoint& pt);

    public:
        void       blinkCursor();
        bool       hitTest(const QPoint& pt, QHexPosition* position, uint64_t firstline) const;
        uint64_t   hitTestArea(const QPoint& pt) const;
        uint64_t   selectedArea() const;
        uint64_t   documentLastLine() const;
        uint64_t   documentLastColumn() const;
        uint64_t   documentLines() const;
        uint64_t   documentWidth() const;
        uint64_t   lineHeight() const;
        QRect getLineRect(uint64_t line, uint64_t firstline) const;

    private:
        QString    hexString(uint64_t line, QByteArray *rawline = nullptr) const;
        QString    asciiString(uint64_t line, QByteArray *rawline = nullptr) const;
        QByteArray getLine(uint64_t line) const;
        uint64_t   rendererLength() const;
        uint64_t   getAddressWidth() const;
        uint64_t   getHexColumnX() const;
        uint64_t   getAsciiColumnX() const;
        uint64_t   getEndColumnX() const;
        uint64_t   getCellWidth() const;
        uint64_t   getNibbleIndex(uint64_t line, uint64_t relx) const;
        void       unprintableChars(QByteArray &ascii) const;

    private:
        void applyDocumentStyles(QPainter* painter, QTextDocument *textdocument) const;
        void applyBasicStyle(QTextCursor& textcursor, const QByteArray& rawline, uint64_t factor = 1) const;
        void applyMetadata(QTextCursor& textcursor, uint64_t line, uint64_t factor = 1) const;
        void applySelection(QTextCursor& textcursor, uint64_t line, uint64_t factor = 1) const;
        void applyCursorAscii(QTextCursor& textcursor, uint64_t line) const;
        void applyCursorHex(QTextCursor& textcursor, uint64_t line) const;
        void drawAddress(QPainter *painter, const QPalette &palette, const QRect &linerect, uint64_t line);
        void drawHex(QPainter *painter, const QPalette &palette, const QRect &linerect, uint64_t line);
        void drawAscii(QPainter *painter, const QPalette &palette, const QRect &linerect, uint64_t line);

    private:
        QHexDocument* m_document;
        QFontMetrics  m_fontmetrics;
        uint64_t      m_selectedarea;
        bool          m_cursorenabled;
};

#endif // QHEXRENDERER_H
