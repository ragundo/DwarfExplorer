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

#include "Log.h"

using namespace qapplication;

void Log::init()
{
	file.open("qt_log.txt");
    instance.reset(new Log);
	qInstallMessageHandler(message);
}

void Log::shutdown()
{
    qInstallMessageHandler(nullptr);
    instance.reset();
	file.close();
}

static const char *msg_type_to_str(QtMsgType type)
{
    switch (type) {
    case QtDebugMsg:
        return "debug";
    case QtInfoMsg:
        return "info";
    case QtWarningMsg:
        return "warning";
    case QtCriticalMsg:
        return "critical";
    case QtFatalMsg:
        return "fatal";
    default:
        return "other";
    }
}

void Log::message(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    auto datetime = QDateTime::currentDateTime();
	file << datetime.toString().toLocal8Bit().data();
	file << " [" << msg_type_to_str(type) << "] " << msg.toLocal8Bit().data();
	if (context.file) {
		file << " (" << context.file << ":" << context.line;
		if (context.function)
			file << ", " << context.function;
		file << ")";
	}
	file << std::endl;
	file.flush();

    if (instance) {
        auto &messages = instance->messages;
        instance->beginInsertRows(QModelIndex(), messages.size(), messages.size());
        messages.emplace_back(datetime, type, context, msg);
        instance->endInsertRows();
    }
}

Log *Log::model()
{
    return instance.get();
}

int Log::rowCount(const QModelIndex &parent) const
{
    return messages.size();
}

int Log::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant Log::data(const QModelIndex &index, int role) const
{
    const auto &msg = messages[index.row()];
    switch (index.column()) {
    case 0: // When
        if (role == Qt::DisplayRole)
            return msg.datetime;
        else
            return QVariant();
    case 1: // Type
        if (role == Qt::DisplayRole) {
            switch (msg.type) {
            case QtDebugMsg:
                return tr("Debug");
            case QtInfoMsg:
                return tr("Info");
            case QtWarningMsg:
                return tr("Warning");
            case QtCriticalMsg:
                return tr("Critical");
            case QtFatalMsg:
                return tr("Fatal");
            default:
                return tr("Other");
            }
        }
        else
            return QVariant();
    case 2: // Message
        if (role == Qt::DisplayRole)
            return msg.msg;
        else
            return QVariant();
    case 3: // Location
        if (role == Qt::DisplayRole)
            return msg.location;
        else
            return QVariant();
    default:
        return QVariant();
    }
}

QVariant Log::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return tr("Date");
        case 1:
            return tr("Type");
        case 2:
            return tr("Message");
        case 3:
            return tr("Location");
        default:
            return QVariant();
        }
    }
    else
        return QVariant();

}

std::ofstream Log::file;
std::unique_ptr<Log> Log::instance;

Log::Message::Message(const QDateTime &datetime, QtMsgType type, const QMessageLogContext &context, const QString &msg)
    : datetime(datetime)
    , type(type)
    , msg(msg)
{
    QStringList loc;
    if (context.file)
        loc.append(QString("%1:%2").arg(context.file).arg(context.line));
    if (context.function)
        loc.append(context.function);
    location = loc.join(", ");
}
