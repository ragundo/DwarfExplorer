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

#ifndef QT_UTILS_H
#define QT_UTILS_H

#include <QString>

#include "MiscUtils.h"

inline QString DF2QT(const std::string &str)
{
    return QString::fromStdString(DF2UTF(str));
}

inline std::string QT2DF(const QString &str)
{
    return UTF2DF(str.toStdString());
}

#endif
