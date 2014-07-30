#ifndef KTP_PROXY_SVC_PROXY_SERVICE_HEADER
#define KTP_PROXY_SVC_PROXY_SERVICE_HEADER

/*
 * This file contains D-Bus adaptor classes generated by qt-svc-gen.py.
 *
 * This file can be distributed under the same terms as the specification from
 * which it was generated.
 */

#include <TelepathyQt/AbstractAdaptor>
#include <TelepathyQt/Global>
#include <TelepathyQt/Types>

#include <QObject>
#include <QtDBus>


namespace Tp
{
namespace Service
{

/**
 * \class ProxyServiceAdaptor
 * \headerfile TelepathyQt/_gen/svc-proxy-service.h <TelepathyQt/_gen/svc-proxy-service.h>
 * \ingroup serviceproxyservice
 *
 * Adaptor class providing a 1:1 mapping of the D-Bus interface "org.kde.TelepathyProxy.ProxyService".
 */
class TP_QT_EXPORT ProxyServiceAdaptor : public Tp::AbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.TelepathyProxy.ProxyService")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.kde.TelepathyProxy.ProxyService\">\n"
"    <property access=\"readwrite\" type=\"u\" name=\"PolicySettings\"/>\n"
"    <method name=\"GeneratePrivateKey\">\n"
"      <arg direction=\"in\" type=\"o\" name=\"account\"/>\n"
"    </method>\n"
"    <signal name=\"ProxyConnected\">\n"
"      <arg type=\"o\" name=\"proxy\"/>\n"
"    </signal>\n"
"    <signal name=\"ProxyDisconnected\">\n"
"      <arg type=\"o\" name=\"proxy\"/>\n"
"    </signal>\n"
"    <signal name=\"KeyGenerationStarted\">\n"
"      <arg type=\"o\" name=\"account\"/>\n"
"    </signal>\n"
"    <signal name=\"KeyGenerationFinished\">\n"
"      <arg type=\"o\" name=\"account\"/>\n"
"      <arg type=\"b\" name=\"error\"/>\n"
"    </signal>\n"
"  </interface>\n"
"")
    Q_PROPERTY(uint PolicySettings READ PolicySettings WRITE SetPolicySettings)

public:
    ProxyServiceAdaptor(const QDBusConnection& dbusConnection, QObject* adaptee, QObject* parent);
    virtual ~ProxyServiceAdaptor();

    typedef Tp::MethodInvocationContextPtr<  > GeneratePrivateKeyContextPtr;

public: // PROPERTIES
    /**
     * Return the value of the exported D-Bus object property \c PolicySettings of type \c uint.
     *
     * Adaptees should export this property as a Qt property named
     * 'policySettings' with type uint.
     *
     *
     * \htmlonly
     * <p>Set the OTR policy how you like it</p>
     * \endhtmlonly
     *
     * \return The value of exported property \c PolicySettings.
     */
    uint PolicySettings() const;
    /**
     * Set the value of the exported D-Bus object property \c PolicySettings of type \c uint.
     *
     * Adaptees should export this property as a writable Qt property named
     * 'policySettings' with type uint.
     *
     *
     * \htmlonly
     * <p>Set the OTR policy how you like it</p>
     * \endhtmlonly
     */
    void SetPolicySettings(const uint &newValue);

public Q_SLOTS: // METHODS
    /**
     * Begins a call to the exported D-Bus method \c GeneratePrivateKey on this object.
     *
     * Adaptees should export this method as a Qt slot with the following signature:
     * void generatePrivateKey(const QDBusObjectPath& account, const Tp::Service::ProxyServiceAdaptor::GeneratePrivateKeyContextPtr &context);
     *
     * Implementations should call MethodInvocationContext::setFinished (or setFinishedWithError
     * accordingly) on the received \a context object once the method has finished processing.
     *
     *
     * \htmlonly
     * <p> Generate new private key for given account. </p>
     * \endhtmlonly
     *
     */
    void GeneratePrivateKey(const QDBusObjectPath& account, const QDBusMessage& dbusMessage);

Q_SIGNALS: // SIGNALS
    /**
     * Represents the exported D-Bus signal \c ProxyConnected on this object.
     *
     * Adaptees should export this signal as a Qt signal with the following signature:
     * void proxyConnected(const QDBusObjectPath& proxy);
     *
     * The adaptee signal will be automatically relayed as a D-Bus signal once emitted.
     *
     * \param proxy
     *
     *     The object path of the connected proxy
     */
    void ProxyConnected(const QDBusObjectPath& proxy);
    /**
     * Represents the exported D-Bus signal \c ProxyDisconnected on this object.
     *
     * Adaptees should export this signal as a Qt signal with the following signature:
     * void proxyDisconnected(const QDBusObjectPath& proxy);
     *
     * The adaptee signal will be automatically relayed as a D-Bus signal once emitted.
     *
     * \param proxy
     *
     *     The object path of the disconnectd proxy type
     */
    void ProxyDisconnected(const QDBusObjectPath& proxy);
    /**
     * Represents the exported D-Bus signal \c KeyGenerationStarted on this object.
     *
     * Adaptees should export this signal as a Qt signal with the following signature:
     * void keyGenerationStarted(const QDBusObjectPath& account);
     *
     * The adaptee signal will be automatically relayed as a D-Bus signal once emitted.
     *
     * \param account
     *
     *     The account the new key is generated for
     */
    void KeyGenerationStarted(const QDBusObjectPath& account);
    /**
     * Represents the exported D-Bus signal \c KeyGenerationFinished on this object.
     *
     * Adaptees should export this signal as a Qt signal with the following signature:
     * void keyGenerationFinished(const QDBusObjectPath& account, bool error);
     *
     * The adaptee signal will be automatically relayed as a D-Bus signal once emitted.
     *
     * \param account
     *
     *     The account the new key has been generated for
     * \param error
     *
     *     %TRUE if error occured during generation
     */
    void KeyGenerationFinished(const QDBusObjectPath& account, bool error);
};

}
}

#endif
