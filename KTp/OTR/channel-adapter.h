/*
    Copyright (C) 2014  Marcin Ziemiński   <zieminn@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OTR_CHANNEL_ADAPTER_HEADER
#define OTR_CHANNEL_ADAPTER_HEADER

#include "types.h"
#include "constants.h"

#include "ktpotr_export.h"

#include <QObject>

#include <TelepathyQt/Types>
#include <TelepathyQt/TextChannel>
#include <TelepathyQt/PendingOperation>
#include <TelepathyQt/RefCounted>

namespace KTp {

class KTPOTR_EXPORT ChannelAdapter : public QObject, public Tp::RefCounted
{
    Q_OBJECT

    public:
        ChannelAdapter(const Tp::TextChannelPtr &textChannel, QObject *parent = nullptr);
        ~ChannelAdapter() override;

        Tp::TextChannelPtr textChannel();

        KTp::OTRTrustLevel otrTrustLevel() const;
        bool isOTRsuppored() const;
        QString remoteFingerprint() const;
        QDBusPendingReply<> trustFingerprint(const QString &fingerprint, bool trust);

        bool isValid() const;

        void initializeOTR();
        void stopOTR();
        /** question answer peer authentication */
        void startPeerAuthenticationQA(const QString &question, const QString &answer);
        /** shared secret peer authentication*/
        void startPeerAuthenticationSS(const QString &secret);
        void respondPeerAuthentication(const QString &secret);
        void abortPeerAuthentication();

        void acknowledge(const QList<Tp::ReceivedMessage> &messages);
        void send(const QString& text,
                Tp::ChannelTextMessageType type = Tp::ChannelTextMessageTypeNormal,
                Tp::MessageSendingFlags flags = nullptr);

        bool supportsMessageType(Tp::ChannelTextMessageType messageType) const;
        QList<Tp::ChannelTextMessageType> supportedMessageTypes() const;
        QStringList supportedContentTypes() const;
        Tp::MessagePartSupportFlags messagePartSupport() const;
        Tp::DeliveryReportingSupportFlags deliveryReportingSupport() const;

        QList<Tp::ReceivedMessage> messageQueue() const;

    private:
        void setChannel(const Tp::TextChannelPtr &textChannel);
        void setupOTRChannel();
        void setupTextChannel();

    private Q_SLOTS:
        void onTrustLevelPropertyGet(Tp::PendingOperation *op);
        void onPendingMessagesPropertyGet(Tp::PendingOperation *op);
        void onRemoteFingerprintPropertyGet(Tp::PendingOperation *op);
        void onMessageReceived(const Tp::MessagePartList &message);
        void onPendingMessagesRemoved(const Tp::UIntList &messageIDs);
        void onMessageSent(const Tp::MessagePartList &content, uint flags, const QString &messageToken);
        void onTrustLevelChanged(uint trustLevel);
        void onPeerAuthenticationRequested(const QString &question);

    Q_SIGNALS:
        void messageSent(const Tp::Message &message,
                Tp::MessageSendingFlags flags,
                const QString &sentMessageToken);
        void messageReceived(const Tp::ReceivedMessage &message);
        void pendingMessageRemoved( const Tp::ReceivedMessage &message);

        void otrTrustLevelChanged(KTp::OTRTrustLevel newStatus, KTp::OTRTrustLevel oldStatus);
        void sessionRefreshed();
        void peerAuthenticationRequestedQA(const QString &question);
        void peerAuthenticationRequestedSS();
        void peerAuthenticationConcluded(bool authenticated);
        void peerAuthenticationInProgress();
        void peerAuthenticationAborted();
        void peerAuthenticationError();
        void peerAuthenticationCheated();

    private:
        struct Private;
        friend struct Private;
        Private *d;
};

typedef Tp::SharedPtr<ChannelAdapter> ChannelAdapterPtr;

} /* namespace KTp */

#endif
