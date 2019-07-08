#ifndef HEXVIEWER_WINDOW_H
#define HEXVIEWER_WINDOW_H

#include <QMainWindow>
#include "QHexView/qhexview.h"

class QHexViewer_Window : public QMainWindow
{
    Q_OBJECT

public:
    QHexViewer_Window(QWidget *parent, uint64_t p_address, char *p_data, std::size_t p_size);
    ~QHexViewer_Window()
    {
        delete m_hexview;
        m_hexview = nullptr;
    }

    QHexView *get_hexview();

protected:
    QHexView* m_hexview;
private Q_SLOTS:
    void on_MainWindow_resumed();
};
#endif // HEXVIEWER_WINDOW_H