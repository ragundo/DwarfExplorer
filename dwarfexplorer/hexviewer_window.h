#ifndef HEXVIEWER_WINDOW_H
#define HEXVIEWER_WINDOW_H

#include <QMainWindow>
#include "QHexView/QHexView.h"

class QHexViewer_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit QHexViewer_Window(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    //~QHexViewer_Window();
    QHexView* get_hexview();
protected:
    QHexView* m_hexview;    
private Q_SLOTS:

};

#endif // HEXVIEWER_WINDOW_H