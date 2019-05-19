#ifndef DFSTRUCTURE_WINDOW_H
#define DFSTRUCTURE_WINDOW_H

#include <QMainWindow>
#include <QTreeView>

namespace Ui {
class DFStructure_Window;
}

class DFStructure_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit DFStructure_Window(QWidget *parent = 0);
    ~DFStructure_Window();
    QTreeView* get_treeview();
private Q_SLOTS:
    void on_treeView_expanded(const QModelIndex& p_index);
    void on_actionOpen_in_new_window_triggered();
    void on_actionOpen_in_hex_viewer_triggered();
    void on_actionOpenPointer_in_hex_viewer_triggered();
private:
    Ui::DFStructure_Window *ui;
};

#endif // DFSTRUCTURE_WINDOW_H
