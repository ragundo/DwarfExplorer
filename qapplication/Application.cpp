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

#include "Application.h"

#include <QWidget>

#include <QtDebug>

using namespace qapplication;

Application::Application(int &argc, char **argv)
	: QApplication(argc, argv)
{
	qRegisterMetaType<WidgetFactory>();

	setApplicationName("DFHack");
	setOrganizationName("DFHack");

	setQuitOnLastWindowClosed(false);
}

Application::~Application()
{
}

void Application::addTopLevelWidget(WidgetFactory factory)
{
	auto widget = factory();
    widget->setAttribute(Qt::WA_DeleteOnClose);
	qDebug() << "Created Widget with type:" << widget->metaObject()->className();
	widget->show();
}

