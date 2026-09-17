---
layout: default
title: SOAP Remote-Command Interface
---

# SOAP Remote-Command Interface

`mangosd` can expose a SOAP endpoint using the classic MaNGOS `urn:MaNGOS`
`executeCommand` interface. External tools can run one server command per
request and read the command output back.

SOAP support is off by default at build time and at run time.

## Build

Build SOAP support into `mangosd` with:

```sh
cmake -S . -B build -DENABLE_SOAP=ON
```

This compiles the bundled gSOAP runtime (`dep/src/gsoap`, version 2.8.135) and
links it into `mangosd`. Without `-DENABLE_SOAP=ON`, no SOAP-related code is
built.

## Configuration

After building with SOAP support, enable the endpoint in `mangosd.conf`:

```ini
SOAP.Enabled = 1
SOAP.IP = 127.0.0.1
SOAP.Port = 7878
```

Keep `SOAP.IP` on `127.0.0.1` unless the port is otherwise protected. The SOAP
interface does not provide encryption, so HTTP Basic auth credentials are sent
in cleartext.

## Access

Requests use HTTP Basic auth with a game account of at least administrator rank
(`account.rank` 4). Banned accounts and lower ranks are refused.

Each request runs one command through the world command queue. The command output
comes back in `<result>`. A failed command returns a SOAP fault carrying the same
text.

HTTP status meanings:

| Status | Meaning |
| --- | --- |
| `401` | Credentials were missing or not accepted. |
| `403` | The account is banned or below administrator rank. |
| `413` | The request is larger than the SOAP request limit. |
| `503` | The world server is shutting down. |

## Example

```sh
curl -u ADMIN:PASSWORD -H 'Content-Type: text/xml' --data \
  '<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" xmlns:ns1="urn:MaNGOS"><SOAP-ENV:Body><ns1:executeCommand><command>server info</command></ns1:executeCommand></SOAP-ENV:Body></SOAP-ENV:Envelope>' \
  http://127.0.0.1:7878/
```
