/***************************************************************************
 *   Copyright (C) 2014 Marcin Ziemiński <zieminn@gmail.com>
 *                                                                         *
 * This library is free software; you can redistribute it and/or           *
 * modify it under the terms of the GNU Lesser General Public		   *
 * License as published by the Free Software Foundation; either		   *
 * version 2.1 of the License, or (at your option) any later version.	   *
 * 									   *
 * This library is distributed in the hope that it will be useful,	   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU	   *
 * Lesser General Public License for more details.			   *
 * 									   *
 * You should have received a copy of the GNU Lesser General Public	   *
 * License along with this library; if not, write to the Free Software	   *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA*
 ***************************************************************************/

#include "types.h"

#include <QDBusArgument>
#include <QDBusMetaType>

namespace KTp
{

// ---------- generated by TpQt ----------------------------------------------------------------
TP_QT_EXPORT bool operator==(const FingerprintInfo& v1, const FingerprintInfo& v2)
{
    return ((v1.contactName == v2.contactName)
            && (v1.fingerprint == v2.fingerprint)
            && (v1.isVerified == v2.isVerified)
            && (v1.inUse == v2.inUse)
           );
}

TP_QT_EXPORT QDBusArgument& operator<<(QDBusArgument& arg, const FingerprintInfo& val)
{
    arg.beginStructure();
    arg << val.contactName << val.fingerprint << val.isVerified << val.inUse;
    arg.endStructure();
    return arg;
}

TP_QT_EXPORT const QDBusArgument& operator>>(const QDBusArgument& arg, FingerprintInfo& val)
{
    arg.beginStructure();
    arg >> val.contactName >> val.fingerprint >> val.isVerified >> val.inUse;
    arg.endStructure();
    return arg;
}
// ---------- \generated by TpQt ----------------------------------------------------------------

void registerOtrTypes()
{
    static bool registered = false;
    if(registered) {
        return;
    }
    registered = true;

    qDBusRegisterMetaType<KTp::FingerprintInfo>();
    qDBusRegisterMetaType<KTp::FingerprintInfoList>();
}

}
