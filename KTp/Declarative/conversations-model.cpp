/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2011  <copyright holder> <email>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "conversations-model.h"
#include "conversation-watcher.h"
#include "conversation.h"

class ConversationsModel::ConversationsModelPrivate
{
public:
    ConversationWatcher watcher;
    QList<Conversation*> data;
};

QVariant ConversationsModel::data ( const QModelIndex& index, int role ) const
{
    QVariant result();
    if(index.row() >= 0 && index.row() < d->data.count()) {
        Q_ASSERT(role == ConversationRole);
        return QVariant::fromValue<QObject*>(d->data[index.row()]);
    }
    return result;
}

int ConversationsModel::rowCount ( const QModelIndex& parent ) const
{
    return d->data.count();
}

ConversationsModel::ConversationsModel() :
    d(new ConversationsModelPrivate)
{
    QHash<int, QByteArray> roles;
    roles[ConversationRole] = "conversation";
    setRoleNames(roles);

    QObject::connect(&d->watcher, SIGNAL(newConversation(Conversation*)), SLOT(onInconmingConversation(Conversation*)));
}

void ConversationsModel::onInconmingConversation ( Conversation* convo )
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    d->data.append(convo);
    endInsertRows();
}

ConversationsModel::~ConversationsModel()
{
    delete d;
}
