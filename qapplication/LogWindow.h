/*
 * Copyright 2019 Clement Vuchener
 *
 * This file is part of qapplication plugin for DFHack
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

#ifndef QT_QAPPLICATION_LOG_WINDOW_H
#define QT_QAPPLICATION_LOG_WINDOW_H

#include <QMainWindow>

#include <memory>

namespace qapplication
{

namespace Ui { class LogWindow; }

class LogWindow: public QMainWindow
{
    Q_OBJECT
public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow() override;

private:
    std::unique_ptr<Ui::LogWindow> ui;
};

}

#endif
