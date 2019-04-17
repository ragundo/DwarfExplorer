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

#ifndef DFHACK_QT_TOP_LEVEL_WIDGET_H
#define DFHACK_QT_TOP_LEVEL_WIDGET_H

#include <QApplication>

#include <functional>

#include "ColorText.h"

using WidgetFactory = std::function<QWidget *()>;
Q_DECLARE_METATYPE(WidgetFactory);

template<typename T>
class SimpleWidgetFactory
{
public:
	QWidget *operator() () const
	{
		return new T();
	}
};

template<typename Callable>
inline bool addTopLevelWidget(Callable &&widget_factory, DFHack::color_ostream *out = nullptr)
{
	if (auto app = QCoreApplication::instance()) {
		if (QMetaObject::invokeMethod(app, "addTopLevelWidget", Qt::QueuedConnection,
                    Q_ARG(WidgetFactory, WidgetFactory(std::forward<Callable>(widget_factory))))) {
            return true;
        }
        else {
            if (out)
                out->printerr("Failed to invoke addTopLevelWidget method\n");
            return false;
        }
    }
	else {
        if (out)
            out->printerr("QApplication not started\n");
		return false;
    }
}

#endif
