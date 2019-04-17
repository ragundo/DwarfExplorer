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

#ifndef QT_QAPPLICATION_APPLICATION_H
#define QT_QAPPLICATION_APPLICATION_H

#include <QApplication>

#include "TopLevelWidget.h"

namespace qapplication
{

class Application: public QApplication
{
	Q_OBJECT
public:
	Application(int &argc, char **argv);
	~Application() override;

public slots:
	void addTopLevelWidget(WidgetFactory factory);
};

}

#endif
