/*
 * Start chat dialog
 *
 * Copyright (C) 2013 Anant Kamath <kamathanant@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef STARTCHATDIALOG_H
#define STARTCHATDIALOG_H

#include <QDialog>

#include <TelepathyQt/Types>

#include <KTp/ktpcommoninternals_export.h>

namespace Tp {
    class PendingOperation;
}

namespace KTp
{
class KTPCOMMONINTERNALS_EXPORT StartChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartChatDialog(const Tp::AccountManagerPtr &accountManager, QWidget *parent = nullptr);
    ~StartChatDialog() override;

    void accept() override;

protected:
    void closeEvent(QCloseEvent *e) override;

private Q_SLOTS:
    KTPCOMMONINTERNALS_NO_EXPORT void _k_onStartChatFinished(Tp::PendingOperation *op);
    KTPCOMMONINTERNALS_NO_EXPORT void _k_onPendingContactFinished(Tp::PendingOperation *op);

private:
    KTPCOMMONINTERNALS_NO_EXPORT void setInProgress(bool inProgress);

    struct Private;
    Private * const d;
};
}

#endif // STARTCHATDIALOG_H
