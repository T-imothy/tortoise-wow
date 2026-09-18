/*
 * SOAP remote-command interface (re-added). See MaNGOSsoap.h.
 */

#include "MaNGOSsoap.h"

#include <any>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <thread>

namespace
{
    int (*s_defaultParse)(struct soap*) = nullptr;

    int Authenticate(struct soap* soap)
    {
        soap->user = nullptr;

        if (!soap->userid || !soap->passwd)
            return 401;

        uint32 const accountId = sAccountMgr.GetId(soap->userid);
        if (!accountId || !sAccountMgr.CheckPassword(accountId, soap->passwd))
            return 401;

        if (sAccountMgr.IsAccountBannedInDatabase(accountId))
        {
            sLog.outBasic("SOAP: banned account '%s' from %s refused", soap->userid, soap->host);
            return 403;
        }

        if (sAccountMgr.GetSecurityFromDatabase(accountId) < SOAPThread::MinLevel)
            return 403;

        soap->user = reinterpret_cast<void*>(static_cast<uintptr_t>(accountId));
        return SOAP_OK;
    }
}

SOAPThread::SOAPThread(const std::string& host, int port)
    : m_host(host), m_port(port), m_workerThread(&SOAPThread::Work, this)
{
}

SOAPThread::~SOAPThread()
{
    m_stopRequested.store(true, std::memory_order_release);
    if (m_workerThread.joinable())
        m_workerThread.join();
}

int SOAPThread::ParseAndAuthenticate(struct soap* soap)
{
    if (int const error = s_defaultParse(soap))
        return error;

    if (World::IsStopped())
        return soap->error = 503;

    soap->authrealm = "MaNGOS";
    int status = Authenticate(soap);
    if (status == SOAP_OK && soap->length > MaxRequestBytes)
        status = 413;

    return soap->error = status;
}

void SOAPThread::Work()
{
    struct soap soap;
    soap_init(&soap);
    soap_set_imode(&soap, SOAP_C_UTFSTRING);
    soap_set_omode(&soap, SOAP_C_UTFSTRING);

    soap.accept_timeout = AcceptTimeout;
    soap.recv_timeout = DataTimeout;
    soap.send_timeout = DataTimeout;
    soap.transfer_timeout = DataTimeout;
    soap.recv_maxlength = MaxRequestBytes;

    s_defaultParse = soap.fparse;
    soap.fparse = &SOAPThread::ParseAndAuthenticate;

    if (soap_bind(&soap, m_host.c_str(), m_port, BackLogSize) < 0)
    {
        sLog.outError("SOAP: could not bind to %s:%d - remote command interface disabled", m_host.c_str(), m_port);
        soap_done(&soap);
        return;
    }

    sLog.outString("SOAP: remote command interface bound to http://%s:%d", m_host.c_str(), m_port);

    while (!IsStopping())
    {
        if (soap_accept(&soap) == SOAP_INVALID_SOCKET)
            continue;

        struct soap* connection = soap_copy(&soap);
        if (!connection)
        {
            soap_closesock(&soap);
            continue;
        }

        soap_serve(connection);
        soap_destroy(connection);
        soap_end(connection);
        soap_free(connection);
    }

    soap_destroy(&soap);
    soap_end(&soap);
    soap_done(&soap);
}

namespace
{
    struct SoapCommandState
    {
        std::string output;
        std::atomic<bool> finished{false};
        bool success = false;
    };
    using SoapCommandStatePtr = std::shared_ptr<SoapCommandState>;

    void SoapPrint(std::any arg, const char* text)
    {
        auto const state = std::any_cast<SoapCommandStatePtr>(arg);
        if (state && text)
            state->output += text;
    }

    void SoapCommandFinished(std::any arg, bool success)
    {
        auto const state = std::any_cast<SoapCommandStatePtr>(arg);
        if (state)
        {
            state->success = success;
            state->finished.store(true, std::memory_order_release);
        }
    }
}

int ns1__executeCommand(struct soap* soap, char* command, char** result)
{
    uint32 const accountId = static_cast<uint32>(reinterpret_cast<uintptr_t>(soap->user));
    if (!accountId)
        return 401;

    AccountTypes const security = sAccountMgr.GetSecurityFromDatabase(accountId);
    if (security < SOAPThread::MinLevel)
        return 403;

    if (!command || !*command)
        return soap_sender_fault(soap, "Command must not be empty", "The supplied command was an empty string");

    auto const state = std::make_shared<SoapCommandState>();
    sWorld.QueueCliCommand(new CliCommandHolder(accountId, security, state, command, &SoapPrint, &SoapCommandFinished));

    while (!state->finished.load(std::memory_order_acquire))
    {
        if (World::IsStopped())
            return soap_receiver_fault(soap, "Server is shutting down", "The command may not have been executed");
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    char* const out = soap_strdup(soap, state->output.c_str());
    if (!state->success)
        return soap_sender_fault(soap, out, out);

    *result = out;
    return SOAP_OK;
}

////////////////////////////////////////////////////////////////////////////////
// XML namespace table - ns1 must be urn:MaNGOS for CMaNGOS-compatible clients.
////////////////////////////////////////////////////////////////////////////////
SOAP_NMAC struct Namespace namespaces[] =
{
    { "SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL },
    { "SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL },
    { "xsi",      "http://www.w3.org/2001/XMLSchema-instance",  "http://www.w3.org/*/XMLSchema-instance", NULL },
    { "xsd",      "http://www.w3.org/2001/XMLSchema",           "http://www.w3.org/*/XMLSchema", NULL },
    { "ns1",      "urn:MaNGOS", NULL, NULL },
    { NULL, NULL, NULL, NULL }
};
