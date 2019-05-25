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

#include "Core.h"
#include "DataDefs.h"
#include "PluginManager.h"

#include <memory>
#include <future>

#include <QDebug>
#include <QMessageBox>
#include <QResource>
#include <QFile>

#include "tinythread.h"

#include "Application.h"
#include "Log.h"
#include "LogWindow.h"

#include "TopLevelWidget.h"

using namespace DFHack;
using namespace qapplication;

DFHACK_PLUGIN("qapplication");
DFHACK_PLUGIN_IS_ENABLED(is_enabled);

static QString style_name;
static QString icon_theme_name;
static std::vector<std::pair<QString, QString>> resources;

// Commands
class QtInfoBoxFactory
{
public:
	QWidget *operator() () const
	{
		qDebug() << "Factory called";
		auto message_box = new QMessageBox;
		message_box->setWindowTitle("Qt Informations");
		message_box->setInformativeText(QString("Qt Build Version: %1<br/>Qt Runtime Version: %2")
				.arg(QT_VERSION_STR)
				.arg(qVersion()));
		message_box->addButton(QMessageBox::Close);
		return message_box;
	}
};

static command_result info_cmd(color_ostream &out, std::vector<std::string> &parameters)
{
	qDebug() << "In qt_info";
	return addTopLevelWidget(QtInfoBoxFactory(), &out) ? CR_OK : CR_FAILURE;
}

static command_result log_cmd(color_ostream &out, std::vector<std::string> &parameters)
{
    return addTopLevelWidget(SimpleWidgetFactory<LogWindow>(), &out) ? CR_OK : CR_FAILURE;
}

static command_result set_style(color_ostream &out, std::vector<std::string> &parameters)
{
    if (parameters.size() != 1)
        return CR_WRONG_USAGE;
    style_name = QString::fromStdString(parameters[0]);
    return CR_OK;
}

static command_result set_icon_theme(color_ostream &out, std::vector<std::string> &parameters)
{
    if (parameters.size() != 1)
        return CR_WRONG_USAGE;
    icon_theme_name = QString::fromStdString(parameters[0]);
    return CR_OK;
}

static command_result register_resource(color_ostream &out, std::vector<std::string> &parameters)
{
    if (parameters.size() < 1 || parameters.size() > 2)
        return CR_WRONG_USAGE;
    resources.emplace_back();
    auto &r = resources.back();
    r.first = QString::fromStdString(parameters[0]);
    if (parameters.size() == 2)
        r.second = QString::fromStdString(parameters[1]);
    return CR_OK;
}

void apply_style_sheet(QApplication& p_application)
{
    QFile f(":qdarkstyle/style.qss");

    if (f.exists())
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        p_application.setStyleSheet(ts.readAll());
    }
}


// main QApplication thread
static std::unique_ptr<tthread::thread> thread;

static void app_exec(void *arg)
{
    std::promise<void> promise(std::move(*static_cast<std::promise<void> *>(arg)));
    int argc = 1;
    char command_name[] = "dfhack";
    char *argv[] = { command_name, nullptr };

    Log::init();
    Log::message(QtInfoMsg, QMessageLogContext(), "Qt Init");

    for (const auto &p: resources)
        QResource::registerResource(p.first, p.second);
    if (!style_name.isEmpty())
        QApplication::setStyle(style_name);
    if (!icon_theme_name.isEmpty())
        QIcon::setThemeName(icon_theme_name);

    Application app(argc, argv);
    //apply_style_sheet(app);
    promise.set_value();
    app.exec();

    Log::message(QtInfoMsg, QMessageLogContext(), "Qt Shutdown");
    Log::shutdown();
}

// Plugin functions
DFhackCExport command_result plugin_enable(color_ostream &out, bool enable)
{
    if (enable == is_enabled)
        return CR_OK;
    if (enable) {
        std::promise<void> promise; // promise for QApplication initialization
        auto future = promise.get_future();
        thread.reset(new tthread::thread(app_exec, &promise));
        future.get();
    }
    else if (thread) {
        if (auto app = QCoreApplication::instance())
            app->quit();
        thread->join();
        thread.reset();
    }
    is_enabled = (bool)thread;
    return CR_OK;
}

DFhackCExport command_result plugin_init(color_ostream &out, std::vector<PluginCommand> &commands)
{
    commands.push_back(PluginCommand("qt-info",
                                     "Display a Qt dialog with Qt informations",
                                     info_cmd,
                                     false,
                                     ""));
    commands.push_back(PluginCommand("qt-log",
                                     "Display a Qt dialog with Qt log messages",
                                     log_cmd,
                                     false,
                                     ""));
    commands.push_back(PluginCommand("qt-set-style",
                                     "Set the style used by Qt widgets",
                                     set_style,
                                     false,
                                     "qt-set-style <name>\n"
                                     "It must be called before enabling qapplication."));
    commands.push_back(PluginCommand("qt-set-icon-theme",
                                     "Set the icon theme used by Qt widgets",
                                     set_icon_theme,
                                     false,
                                     "qt-set-icon-them <name>\n"
                                     "It must be called before enabling qapplication."));
    commands.push_back(PluginCommand("qt-register-resource",
                                     "Register the resource file to use with Qt Widgets",
                                     register_resource,
                                     false,
                                     "qt-register-resource <rcc-filename> [mapped-root]\n"
                                     "It must be called before enabling qapplication."));
    return CR_OK;
}

DFhackCExport command_result plugin_shutdown(color_ostream &out)
{
    if (is_enabled)
        plugin_enable(out, false);
    return CR_OK;
}
