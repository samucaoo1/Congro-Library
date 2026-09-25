# Network

Network provides portable address, socket, connection, listener, datagram,
polling, and name-resolution APIs.

**Root:** `Codespace/Congro/Modules/Network`

The public API keeps native constants such as `AF_INET` and `SOCK_STREAM`
behind Congro types and enums.

On strict POSIX C11 builds, define `_POSIX_C_SOURCE=200809L` in the compiler
command line before any system header is parsed.

## Address and endpoint

**Header:** `Address/Address.h`

Main types: `TNetwork_Address`, `TNetwork_Endpoint`.

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `NETWORK_ADDRESS_FUNC(IPv4_Create)(&a,A,B,C,D)` | `Network_Address_IPv4_Create(...)` | Constructs an IPv4 address. |
| `NETWORK_ADDRESS_FUNC(IPv4_Any)(&a)` | `Network_Address_IPv4_Any(&a)` | 0.0.0.0. |
| `NETWORK_ADDRESS_FUNC(IPv4_Loopback)(&a)` | `Network_Address_IPv4_Loopback(&a)` | 127.0.0.1. |
| `NETWORK_ADDRESS_FUNC(IPv6_Any)(&a)` | `Network_Address_IPv6_Any(&a)` | IPv6 unspecified address. |
| `NETWORK_ADDRESS_FUNC(IPv6_Loopback)(&a)` | `Network_Address_IPv6_Loopback(&a)` | IPv6 loopback. |
| `NETWORK_ADDRESS_FUNC(Endpoint_Create)(&ep,&a,port)` | `Network_Address_Endpoint_Create(...)` | Combines an address and port. |
| `NETWORK_ADDRESS_FUNC(Equal)(&a,&b)` | `Network_Address_Equal(&a,&b)` | Address equality. |

Example:

```c
TNetwork_Address address;
TNetwork_Endpoint endpoint;

NETWORK_ADDRESS_FUNC(IPv4_Loopback)(&address);
NETWORK_ADDRESS_FUNC(Endpoint_Create)(&endpoint, &address, 8080);
```

Direct:

```c
Network_Address_IPv4_Loopback(&address);
Network_Address_Endpoint_Create(&endpoint, &address, 8080);
```

## Socket

**Header:** `Socket/Socket.h`

Types include `TSocket`, `TSocket_Family`, `TSocket_Kind`,
`TSocket_Protocol`, and `TSocket_Shutdown`.

| Indirect | Direct |
| --- | --- |
| `SOCKET_FUNC(Init)(&s)` | `Network_Socket_Init(&s)` |
| `SOCKET_FUNC(Create)(&s,family,kind,protocol,&err)` | `Network_Socket_Create(...)` |
| `SOCKET_FUNC(Close)(&s)` | `Network_Socket_Close(&s)` |
| `SOCKET_FUNC(Bind)(&s,&ep,&err)` | `Network_Socket_Bind(...)` |
| `SOCKET_FUNC(Listen)(&s,backlog,&err)` | `Network_Socket_Listen(...)` |
| `SOCKET_FUNC(Accept)(&s,&client,&peer,&err)` | `Network_Socket_Accept(...)` |
| `SOCKET_FUNC(Connect)(&s,&ep,&err)` | `Network_Socket_Connect(...)` |
| `SOCKET_FUNC(Send)(&s,data,n,&sent,&err)` | `Network_Socket_Send(...)` |
| `SOCKET_FUNC(Receive)(&s,buf,cap,&got,&err)` | `Network_Socket_Receive(...)` |
| `SOCKET_FUNC(SendTo)(...)` | `Network_Socket_SendTo(...)` |
| `SOCKET_FUNC(ReceiveFrom)(...)` | `Network_Socket_ReceiveFrom(...)` |
| `SOCKET_FUNC(Shutdown)(&s,direction,&err)` | `Network_Socket_Shutdown(...)` |
| `SOCKET_FUNC(SetBlocking)(&s,on,&err)` | `Network_Socket_SetBlocking(...)` |
| `SOCKET_FUNC(SetReuseAddress)(&s,on,&err)` | `Network_Socket_SetReuseAddress(...)` |
| `SOCKET_FUNC(SetKeepAlive)(&s,on,&err)` | `Network_Socket_SetKeepAlive(...)` |
| `SOCKET_FUNC(SetNoDelay)(&s,on,&err)` | `Network_Socket_SetNoDelay(...)` |

The optional `TNetwork_Error *` output provides the networking-domain error in
addition to the general `OPSTATUS`.

## Connection

**Header:** `Connection/Connection.h`

This is the higher-level stream connection API.

- `NETWORK_CONNECTION_FUNC(Init)` → `Network_Connection_Init`
- `Connect` → `Network_Connection_Connect`
- `ConnectFor` → `Network_Connection_ConnectFor`
- `Reconnect` → `Network_Connection_Reconnect`
- `Read`, `ReadExact` → `Network_Connection_Read`, `ReadExact`
- `Write`, `WriteAll`
- `Shutdown`, `SetBlocking`, `Close`, `Destroy`
- observers: `State`, `LastError`, `LocalEndpoint`, `RemoteEndpoint`

Example:

```c
TNetwork_Connection connection;
TNetwork_Error error;

NETWORK_CONNECTION_FUNC(Init)(&connection);

if (NETWORK_CONNECTION_FUNC(Connect)(
        &connection, "example.com", 80, &error) == STATUS_CONST(SUCCESS)) {
    static const char request[] =
        "GET / HTTP/1.0\r\nHost: example.com\r\n\r\n";

    NETWORK_CONNECTION_FUNC(WriteAll)(
        &connection, request, sizeof(request) - 1, &error);
}

NETWORK_CONNECTION_FUNC(Destroy)(&connection);
```

Direct form uses `Network_Connection_Init`, `Network_Connection_Connect`,
`Network_Connection_WriteAll`, and `Network_Connection_Destroy`.

## Listener

**Header:** `Listener/Listener.h`

- `NETWORK_LISTENER_FUNC(Init)` → `Network_Listener_Init`
- `Listen(port)` → `Network_Listener_Listen`
- `ListenAt(endpoint)` → `Network_Listener_ListenAt`
- `Accept` → `Network_Listener_Accept`
- `Close` → `Network_Listener_Close`
- `LastError`, `LocalEndpoint` observers.

Example:

```c
TNetwork_Listener server;
TNetwork_Connection client;
TNetwork_Error error;

NETWORK_LISTENER_FUNC(Init)(&server);
NETWORK_LISTENER_FUNC(Listen)(&server, 9000, &error);
NETWORK_LISTENER_FUNC(Accept)(&server, &client, &error);
```

Direct: `Network_Listener_Init`, `Network_Listener_Listen`,
`Network_Listener_Accept`.

## Datagram

**Header:** `Datagram/Datagram.h`

UDP-style datagram lifecycle and IO:

`Init`, `Open`, `Bind`, `SetPeer`, `SendTo`, `ReceiveFrom`, `Send`,
`Receive`, `SetBlocking`, `ClearPeer`, `Close`.

Observers: `HasPeer`, `LastError`, `LocalEndpoint`, `PeerEndpoint`.

All expand from `NETWORK_DATAGRAM_FUNC(Name)` to
`Network_Datagram_Name`.

## Resolve

**Header:** `Resolve/Resolve.h`

Name resolution fills a `TNetwork_Address_Vector`.

```c
TNetwork_Address_Vector addresses;
TNetwork_Error error;

NETWORK_RESOLVE_FUNC(Address)(&addresses, "example.com", &error);
```

The default expanded symbol is `Network_Resolve_Address`.

The vector can contain multiple results; callers should not assume one hostname
maps to one address.

## Poller

**Header:** `Poll/Poll.h`

The poller tracks Connections, Listeners, and Datagrams with event-interest
flags and returns `TNetwork_Event` objects.

Lifecycle and registration:

- `NETWORK_POLLER_FUNC(Init)` → `Network_Poller_Init`
- `Destroy`
- `AddConnection`, `AddListener`, `AddDatagram`
- `Remove`
- `Watch`

Waiting:

- `Wait` → `Network_Poller_Wait`
- `WaitFor` → `Network_Poller_WaitFor` using a Chronometry duration.

Event helpers:

- `Event_Has`
- `Event_UserData`
- `Event_Connection`
- `Event_Listener`
- `Event_Datagram`

Example:

```c
TNetwork_Poller poller;
TNetwork_Poll_Handle handle;

NETWORK_POLLER_FUNC(Init)(&poller);
NETWORK_POLLER_FUNC(AddConnection)(
    &poller, &connection, interests, context, &handle, &error);
```

Direct: `Network_Poller_Init` and `Network_Poller_AddConnection`.

## Error model

**Header:** `Error/Error.h`

Network maintains a domain-specific `TNetwork_Error` in addition to
`OPSTATUS`. Higher-level objects retain their most recent network error where
the API exposes `LastError`.

## Zero-link design

Native OS details are kept behind the Network implementation. The public
contract is designed so users do not manually pass Winsock's `-lws2_32` as a
normal Congro usage requirement.
