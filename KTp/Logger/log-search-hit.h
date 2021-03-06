/*
 * Copyright (C) 2013  Daniel Vrátil <dvratil@redhat.com>
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
 *
 */

#ifndef KTP_LOGSEARCHHIT_H
#define KTP_LOGSEARCHHIT_H

#include <TelepathyQt/Types>
#include <KTp/ktpcommoninternals_export.h>

namespace KTp {

class LogEntity;

/**
 * @brief LogSearchHit is a result of PendingLoggerSearch operation.
 *
 * It describes a log that contains at least one message that matched the given
 * search term.
 *
 * @since 0.7
 * @author Daniel Vrátil <dvratil@redhat.com>
 */
class KTPCOMMONINTERNALS_EXPORT LogSearchHit
{
  public:
    /**
     * Constructor.
     *
     * @param account Matching account.
     * @param entity Matching entity.
     * @param date Matching date.
     */
    LogSearchHit(const Tp::AccountPtr &account, const KTp::LogEntity &entity,
                 const QDate &date);

    /**
     * Copy constructor.
     */
    LogSearchHit(const LogSearchHit &other);

    /**
     * Destructor.
     */
    ~LogSearchHit();

    /**
     * Assignment operator.
     */
    LogSearchHit& operator=(const KTp::LogSearchHit &other);

    /**
     * Returns account that contains the matching log message.
     */
    Tp::AccountPtr account() const;

    /**
     * Returns entity that contains the matching log messages.
     */
    KTp::LogEntity entity() const;

    /**
     * Returns date of the log that contains the matching message(s).
     */
    QDate date() const;

  private:
    class Private;
    QSharedDataPointer<Private> d;
};

} // namespace KTp

#endif // KTP_LOGSEARCHHIT_H
