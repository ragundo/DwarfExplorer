/*
 * Copyright 2019 Clement Vuchener
 *
 * This file is part of qtlabors plugin for DFHack
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
#include "PluginManager.h"

#include "DataDefs.h"
#include "df/world.h"
#include "df/viewscreen_setupdwarfgamest.h"

#include "modules/Gui.h"

#include "TopLevelWidget.h"

#include "EventProxy.h"
#include "MainWindow.h"

using namespace DFHack;
using namespace dwarfexplorer;

DFHACK_PLUGIN("dwarfexplorer");

static std::weak_ptr<EventProxy> event_proxy;

// Commands
static command_result dwarfexplorer_cmd(color_ostream &out, std::vector<std::string> &parameters)
{
	if (addTopLevelWidget([&](){
                auto ptr = event_proxy.lock();
                if (!ptr) {
                    ptr.reset(new EventProxy);
                    event_proxy = ptr;
                }
                return new MainWindow(std::move(ptr));
            }, &out))
        return CR_OK;
    else
        return CR_FAILURE;
}

// Plugin functions
DFhackCExport command_result plugin_init(color_ostream &out, std::vector<PluginCommand> &commands)
{
    commands.push_back(PluginCommand("dwarfexplorer",
                                     "View DF Internals",
                                     dwarfexplorer_cmd,
                                     false,
                                     ""));
    return CR_OK;
}

DFhackCExport command_result plugin_shutdown(color_ostream &out)
{
    return CR_OK;
}

DFhackCExport command_result plugin_onstatechange(color_ostream &out, state_change_event event)
{
    static bool in_embark_screen = false;
    auto proxy = event_proxy.lock();
    if (!proxy)
        return CR_OK;
    switch (event) {
    case SC_MAP_LOADED:
        proxy->mapLoaded();
        break;
    case SC_MAP_UNLOADED:
        proxy->mapUnloaded();
        break;
    case SC_VIEWSCREEN_CHANGED: {
        auto embark_viewscreen = Gui::getViewscreenByType<df::viewscreen_setupdwarfgamest>();
        if (in_embark_screen != bool(embark_viewscreen)) {
            if (embark_viewscreen)
                proxy->embarkScreenOpened();
            else
                proxy->embarkScreenClosed();
            in_embark_screen = embark_viewscreen;
        }
        break;
    }
    default:
        break;
    }
    return CR_OK;
}
