/*
 * Copyright 2019 Rafael Agundo
 *
 * This file is part of dwarfexplorer plugin for DFHack
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef DFSTRUCTURE_WINDOW_H
#define DFSTRUCTURE_WINDOW_H

#include <QCloseEvent>
#include <QMainWindow>
#include <QTreeView>

namespace Ui
{
class DFStructure_Window;
}

class DFStructure_Window : public QMainWindow
{
    Q_OBJECT

  public:
    explicit DFStructure_Window(QWidget* parent = 0);
    ~DFStructure_Window();
    QTreeView* get_treeview();
    void       set_outdated();

  private Q_SLOTS:
    void on_treeView_expanded(const QModelIndex& p_index);
    void on_actionOpen_in_new_window_triggered();
    void on_actionOpen_in_hex_viewer_triggered();
    void on_actionOpenPointer_in_hex_viewer_triggered();
    void on_actionLocate_in_fortress();
    void on_actionLocate_building_in_fortress();
  public slots:
    void on_MainWindow_resumed();

  protected:
    void closeEvent(QCloseEvent* p_close_event);

  private:
    Ui::DFStructure_Window* ui;
    bool                    m_outdated;
};

#endif // DFSTRUCTURE_WINDOW_H
