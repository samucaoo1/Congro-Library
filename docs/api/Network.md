# Network: referência de API

[Guia de uso](../modules/Network.md) · [Índice](../INDEX.md)

Catálogo gerado por `docs/tools/generate_api.py`. As assinaturas preservam
as macros TYPE/FUNC e os parâmetros de geração: TYPE e SUFFIX não são tipos
literais para copiar. Consulte o guia para instâncias prontas, ownership,
erros e exemplos compiláveis. Declarações condicionais continuam sujeitas
ao compilador e às opções do header de origem.

Os links de arquivo incluem tipos, enums, constantes, macros geradoras e
tabelas completas. Headers de VTable são suporte dos pseudo-métodos;
não precisam ser incluídos separadamente pelo usuário.

## Arquivos e configuração

| Arquivo | Assinaturas extraídas |
|---|---|
| [Address/Address.h](../../Codespace/Congro/Modules/Network/Address/Address.h) | 7 |
| [Connection/Connection.h](../../Codespace/Congro/Modules/Network/Connection/Connection.h) | 16 |
| [Datagram/Datagram.h](../../Codespace/Congro/Modules/Network/Datagram/Datagram.h) | 15 |
| [Error/Error.h](../../Codespace/Congro/Modules/Network/Error/Error.h) | 0 |
| [Listener/Listener.h](../../Codespace/Congro/Modules/Network/Listener/Listener.h) | 7 |
| [Network.space](../../Codespace/Congro/Modules/Network/Network.space) | 0 |
| [Poll/Poll.h](../../Codespace/Congro/Modules/Network/Poll/Poll.h) | 14 |
| [Resolve/Resolve.h](../../Codespace/Congro/Modules/Network/Resolve/Resolve.h) | 1 |
| [Socket/Socket.h](../../Codespace/Congro/Modules/Network/Socket/Socket.h) | 16 |

## Address/Address.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Address/Address.h)

```c
void NETWORK_ADDRESS_FUNC(IPv4_Create)( TNetwork_Address *address, uint8_t a, uint8_t b, uint8_t
    c, uint8_t d);

void NETWORK_ADDRESS_FUNC(IPv4_Any)(TNetwork_Address *address);

void NETWORK_ADDRESS_FUNC(IPv4_Loopback)(TNetwork_Address *address);

void NETWORK_ADDRESS_FUNC(IPv6_Any)(TNetwork_Address *address);

void NETWORK_ADDRESS_FUNC(IPv6_Loopback)(TNetwork_Address *address);

void NETWORK_ADDRESS_FUNC(Endpoint_Create)( TNetwork_Endpoint *endpoint, const TNetwork_Address
    *address, uint16_t port);

bool NETWORK_ADDRESS_FUNC(Equal)( const TNetwork_Address *left, const TNetwork_Address *right);

```

## Connection/Connection.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Connection/Connection.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `NETWORK_CONNECTION_DEFAULT_TIMEOUT_SECONDS`

```c
void NETWORK_CONNECTION_FUNC(Init)(TNetwork_Connection *connection);

OPSTATUS NETWORK_CONNECTION_FUNC(Connect)( TNetwork_Connection *connection, const char *host,
    uint16_t port, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(ConnectFor)( TNetwork_Connection *connection, const char *host,
    uint16_t port, CHRONOMETRY_TYPE(Duration) timeout, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(Reconnect)( TNetwork_Connection *connection, TNetwork_Error
    *error);

OPSTATUS NETWORK_CONNECTION_FUNC(Read)( TNetwork_Connection *connection, void *buffer, size_t
    capacity, size_t *bytesRead, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(ReadExact)( TNetwork_Connection *connection, void *buffer,
    size_t size, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(Write)( TNetwork_Connection *connection, const void *data,
    size_t size, size_t *bytesWritten, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(WriteAll)( TNetwork_Connection *connection, const void *data,
    size_t size, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(Shutdown)( TNetwork_Connection *connection, TSocket_Shutdown
    direction, TNetwork_Error *error);

OPSTATUS NETWORK_CONNECTION_FUNC(SetBlocking)( TNetwork_Connection *connection, bool blocking,
    TNetwork_Error *error);

void NETWORK_CONNECTION_FUNC(Close)(TNetwork_Connection *connection);

void NETWORK_CONNECTION_FUNC(Destroy)(TNetwork_Connection *connection);

TNetwork_Connection_State NETWORK_CONNECTION_FUNC(State)(const TNetwork_Connection *connection);

TNetwork_Error NETWORK_CONNECTION_FUNC(LastError)(const TNetwork_Connection *connection);

const TNetwork_Endpoint * NETWORK_CONNECTION_FUNC(LocalEndpoint)(const TNetwork_Connection
    *connection);

const TNetwork_Endpoint * NETWORK_CONNECTION_FUNC(RemoteEndpoint)(const TNetwork_Connection
    *connection);

```

## Datagram/Datagram.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Datagram/Datagram.h)

```c
void NETWORK_DATAGRAM_FUNC(Init)(TNetwork_Datagram *datagram);

OPSTATUS NETWORK_DATAGRAM_FUNC(Open)( TNetwork_Datagram *datagram, TSocket_Family family,
    TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(Bind)( TNetwork_Datagram *datagram, const TNetwork_Endpoint
    *endpoint, TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(SetPeer)( TNetwork_Datagram *datagram, const TNetwork_Endpoint
    *endpoint, TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(SendTo)( TNetwork_Datagram *datagram, const TNetwork_Endpoint
    *endpoint, const void *data, size_t size, size_t *sent, TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(ReceiveFrom)( TNetwork_Datagram *datagram, void *buffer, size_t
    capacity, TNetwork_Endpoint *sender, size_t *received, TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(Send)( TNetwork_Datagram *datagram, const void *data, size_t
    size, size_t *sent, TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(Receive)( TNetwork_Datagram *datagram, void *buffer, size_t
    capacity, size_t *received, TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(SetBlocking)( TNetwork_Datagram *datagram, bool blocking,
    TNetwork_Error *error);

OPSTATUS NETWORK_DATAGRAM_FUNC(ClearPeer)( TNetwork_Datagram *datagram, TNetwork_Error *error);

void NETWORK_DATAGRAM_FUNC(Close)(TNetwork_Datagram *datagram);

bool NETWORK_DATAGRAM_FUNC(HasPeer)(const TNetwork_Datagram *datagram);

TNetwork_Error NETWORK_DATAGRAM_FUNC(LastError)(const TNetwork_Datagram *datagram);

const TNetwork_Endpoint * NETWORK_DATAGRAM_FUNC(LocalEndpoint)(const TNetwork_Datagram
    *datagram);

const TNetwork_Endpoint * NETWORK_DATAGRAM_FUNC(PeerEndpoint)(const TNetwork_Datagram
    *datagram);

```

## Listener/Listener.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Listener/Listener.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `NETWORK_LISTENER_DEFAULT_BACKLOG`

```c
void NETWORK_LISTENER_FUNC(Init)(TNetwork_Listener *listener);

OPSTATUS NETWORK_LISTENER_FUNC(Listen)( TNetwork_Listener *listener, uint16_t port,
    TNetwork_Error *error);

OPSTATUS NETWORK_LISTENER_FUNC(ListenAt)( TNetwork_Listener *listener, const TNetwork_Endpoint
    *endpoint, TNetwork_Error *error);

OPSTATUS NETWORK_LISTENER_FUNC(Accept)( TNetwork_Listener *listener, TNetwork_Connection
    *connection, TNetwork_Error *error);

void NETWORK_LISTENER_FUNC(Close)(TNetwork_Listener *listener);

TNetwork_Error NETWORK_LISTENER_FUNC(LastError)(const TNetwork_Listener *listener);

const TNetwork_Endpoint * NETWORK_LISTENER_FUNC(LocalEndpoint)(const TNetwork_Listener
    *listener);

```

## Network.space

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Network.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `NETWORK_MOD(NAME)`
- `NETWORK_TYPE(NAME)`
- `NETWORK_FUNC(NAME)`
- `NETWORK_CONST(NAME)`
- `NETWORK_CONST_FINAL(NAME)`
- `NETWORK_ERROR_CONST(NAME)`
- `NETWORK_EVENT_CONST(NAME)`
- `NETWORK_POLLER_SOURCE_CONST(NAME)`
- `NETWORK_ADDRESS_TYPE(NAME)`
- `NETWORK_ADDRESS_FUNC(NAME)`
- `NETWORK_CONNECTION_TYPE(NAME)`
- `NETWORK_CONNECTION_FUNC(NAME)`
- `NETWORK_LISTENER_TYPE(NAME)`
- `NETWORK_LISTENER_FUNC(NAME)`
- `NETWORK_DATAGRAM_TYPE(NAME)`
- `NETWORK_DATAGRAM_FUNC(NAME)`
- `NETWORK_POLLER_TYPE(NAME)`
- `NETWORK_POLLER_FUNC(NAME)`
- `NETWORK_POLLER_CONST(NAME)`
- `SOCKET_NS`
- `SOCKET_TYPE(NAME)`
- `SOCKET_FUNC(NAME)`


## Poll/Poll.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Poll/Poll.h)

```c
void NETWORK_POLLER_FUNC(Init)(TNetwork_Poller *poller);

void NETWORK_POLLER_FUNC(Destroy)(TNetwork_Poller *poller);

OPSTATUS NETWORK_POLLER_FUNC(AddConnection)( TNetwork_Poller *poller, TNetwork_Connection
    *connection, TNetwork_Event_Flags interests, void *userdata, TNetwork_Poll_Handle *handle,
    TNetwork_Error *error);

OPSTATUS NETWORK_POLLER_FUNC(AddListener)( TNetwork_Poller *poller, TNetwork_Listener *listener,
    TNetwork_Event_Flags interests, void *userdata, TNetwork_Poll_Handle *handle, TNetwork_Error
    *error);

OPSTATUS NETWORK_POLLER_FUNC(AddDatagram)( TNetwork_Poller *poller, TNetwork_Datagram *datagram,
    TNetwork_Event_Flags interests, void *userdata, TNetwork_Poll_Handle *handle, TNetwork_Error
    *error);

OPSTATUS NETWORK_POLLER_FUNC(Remove)( TNetwork_Poller *poller, TNetwork_Poll_Handle handle,
    TNetwork_Error *error);

OPSTATUS NETWORK_POLLER_FUNC(Watch)( TNetwork_Poller *poller, TNetwork_Poll_Handle handle,
    TNetwork_Event_Flags interests, TNetwork_Error *error);

OPSTATUS NETWORK_POLLER_FUNC(Wait)( TNetwork_Poller *poller, TNetwork_Event_Vector *events,
    TNetwork_Error *error);

OPSTATUS NETWORK_POLLER_FUNC(WaitFor)( TNetwork_Poller *poller, TNetwork_Event_Vector *events,
    CHRONOMETRY_TYPE(Duration) timeout, TNetwork_Error *error);

bool NETWORK_POLLER_FUNC(Event_Has)( const TNetwork_Event *event, TNetwork_Event_Flags flags);

void *NETWORK_POLLER_FUNC(Event_UserData)( const TNetwork_Event *event);

TNetwork_Connection *NETWORK_POLLER_FUNC(Event_Connection)( const TNetwork_Event *event);

TNetwork_Listener *NETWORK_POLLER_FUNC(Event_Listener)( const TNetwork_Event *event);

TNetwork_Datagram *NETWORK_POLLER_FUNC(Event_Datagram)( const TNetwork_Event *event);

```

## Resolve/Resolve.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Resolve/Resolve.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `WIN32_LEAN_AND_MEAN`
- `NETWORK_RESOLVE_TYPE(NAME)`
- `NETWORK_RESOLVE_FUNC(NAME)`

```c
OPSTATUS NETWORK_RESOLVE_FUNC(Address)( TNetwork_Address_Vector *addresses, const char *host,
    TNetwork_Error *error);

```

## Socket/Socket.h

[Declarações e implementação](../../Codespace/Congro/Modules/Network/Socket/Socket.h)

```c
void SOCKET_FUNC(Init)(TSocket *socket);

OPSTATUS SOCKET_FUNC(Create)( TSocket *socket, TSocket_Family family, TSocket_Kind kind,
    TSocket_Protocol protocol, TNetwork_Error *error);

void SOCKET_FUNC(Close)(TSocket *socket);

OPSTATUS SOCKET_FUNC(Bind)( TSocket *socket, const TNetwork_Endpoint *endpoint, TNetwork_Error
    *error);

OPSTATUS SOCKET_FUNC(Listen)( TSocket *socket, int backlog, TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(Accept)( TSocket *socket, TSocket *client, TNetwork_Endpoint *peer,
    TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(Connect)( TSocket *socket, const TNetwork_Endpoint *endpoint,
    TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(Send)( TSocket *socket, const void *data, size_t size, size_t *sent,
    TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(Receive)( TSocket *socket, void *data, size_t capacity, size_t *received,
    TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(SendTo)( TSocket *socket, const void *data, size_t size, const
    TNetwork_Endpoint *endpoint, size_t *sent, TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(ReceiveFrom)( TSocket *socket, void *data, size_t capacity,
    TNetwork_Endpoint *sender, size_t *received, TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(Shutdown)( TSocket *socket, TSocket_Shutdown direction, TNetwork_Error
    *error);

OPSTATUS SOCKET_FUNC(SetBlocking)( TSocket *socket, bool blocking, TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(SetReuseAddress)( TSocket *socket, bool enabled, TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(SetKeepAlive)( TSocket *socket, bool enabled, TNetwork_Error *error);

OPSTATUS SOCKET_FUNC(SetNoDelay)( TSocket *socket, bool enabled, TNetwork_Error *error);

```
