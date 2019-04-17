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

#ifndef QT_QAPPLICATION_LOG_H
#define QT_QAPPLICATION_LOG_H

#include <QtGlobal>
#include <QAbstractTableModel>
#include <QDateTime>

#include <fstream>
#include <memory>
#include <vector>

namespace qapplication
{

class Log: public QAbstractTableModel
{
    Q_OBJECT
public:
	static void init();
	static void shutdown();

	static void message(QtMsgType, const QMessageLogContext &, const QString &);

    static Log *model();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
	static std::ofstream file;
    static std::unique_ptr<Log> instance;

    struct Message
    {
        QDateTime datetime;
        QtMsgType type;
        QString msg;
        QString location;

        Message(const QDateTime &, QtMsgType, const QMessageLogContext &, const QString &);
    };
    std::vector<Message> messages;
};

}

#endif
