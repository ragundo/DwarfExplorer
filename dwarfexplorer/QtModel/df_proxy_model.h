/*
 * Copyright 2019 Rafael Agundo
 *
 * This file is part of dearfexplorer plugin for DFHack
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

#ifndef DF_PROXY_MODEL_H
#define DF_PROXY_MODEL_H
#include <QSortFilterProxyModel>
#include "../df_model.h"

class DF_ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

    public:
        DF_ProxyModel(QObject* parent = nullptr);

        bool hasChildren(const QModelIndex& p_parent = QModelIndex()) const;

    protected:
        bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#endif // DF_PROXY_MODEL_H