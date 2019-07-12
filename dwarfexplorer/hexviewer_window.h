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