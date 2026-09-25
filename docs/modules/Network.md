# Network

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Network.md)

Network oferece Socket para operações de baixo nível e Connection, Listener e
Datagram para ciclos de uso mais diretos. Inclua o header do pacote; não há
`Network.h` agregador. As enumerações públicas selecionam famílias e protocolos
sem exigir `AF_*` ou `SOCK_*` no código chamador.

## Pacotes e ciclos de vida

| Pacote | Fluxo | Recursos |
|---|---|---|
| Address | `IPv4_Create`, `IPv4_Any/Loopback`, `IPv6_Any/Loopback`, `Endpoint_Create`, `Equal` | Valores IPv4/IPv6 e endpoint com porta. |
| Resolve | Inicializar vetor → `Address` → destruir vetor | Resolve host e preenche `TNetwork_Address_Vector`, removendo duplicatas. |
| Socket | `Init` → `Create` → configurar/bind/connect → I/O → `Close` | `TSocket` possui o handle nativo. |
| Connection | `Init` → `Connect`/`ConnectFor` → `Read`/`Write` → `Close` → `Destroy` | TCP, estado observável, host retido para `Reconnect`. |
| Listener | `Init` → `Listen`/`ListenAt` → `Accept` → `Close` | Cada conexão aceita tem vida própria. |
| Datagram | `Init` → `Open` → `Bind`/`SetPeer` → I/O → `Close` | UDP, com ou sem peer padrão. |
| Poll | `Init` → `Add*` → `Watch`/`Wait` → `Remove` → `Destroy` | Registros de objetos e vetor de eventos, sem thread automática. |
| Error/Runtime | Mapeamento de erros e inicialização interna | `TNetwork_Error`, carregamento do backend Windows. |

## Erros, estados e propriedade

A maioria das operações falíveis retorna `OPSTATUS` e aceita
`TNetwork_Error *error` para o motivo de rede. Os objetos também têm consultas
`LastError`. Verifique primeiro o status operacional; nem toda falha é um erro
do sistema de rede. Os erros do domínio usam `NETWORK_ERROR_CONST`.

Inicialize todos os objetos antes de usar. Não copie sockets/conexões vivos por
valor: isso duplica o número do handle, não o recurso do sistema. `Close` de uma
Connection fecha o socket, enquanto `Destroy` também libera o host retido.
Destrua Connection mesmo quando o connect falhar após sua inicialização.

Resolve recebe vetor já inicializado, limpa resultados anteriores e pode alocar.
Destrua-o com `FLAT_VECTOR_FUNC(Network_Address, Destroy)` depois do uso.
Address armazena bytes do endereço; não é um parser de strings nem representa
um nome DNS. As funções de construção de Address exigem ponteiros válidos.

## TCP e UDP

Socket expõe `Bind`, `Listen`, `Accept`, `Connect`, `Send`, `Receive`, `SendTo`,
`ReceiveFrom`, `Shutdown` e ajustes de blocking, reuse-address, keep-alive e
no-delay. TCP é um fluxo: uma escrita não define uma mensagem, e as contagens
`sent`/`received` podem ser menores que o pedido.

Connection oferece `ReadExact` e `WriteAll` para completar uma quantidade.
Use essas conveniências com fluxo bloqueante; em código não bloqueante,
controle o progresso com `Read`/`Write` e suas contagens. `ConnectFor` recebe
Duration; seu timeout não deve ser entendido como limite de tempo de toda
operação futura nem como um resolvedor DNS assíncrono.

Listener aceita para um `TNetwork_Connection` inicializado. A aplicação mantém
o laço de aceitação e a coleção de clientes. Datagram oferece `SendTo` e
`ReceiveFrom` para endpoints explícitos; `SetPeer` habilita `Send` e `Receive`,
e `ClearPeer` remove esse peer. UDP não garante entrega ou ordenação.

## Polling

`AddConnection`, `AddListener` e `AddDatagram` recebem interesses, userdata e
retornam handle de registro. `Watch` altera interesses. `Wait` preenche um vetor
de eventos inicializado pelo chamador e aceita um timeout. Flags incluem READ,
WRITE, ACCEPT, CLOSE e ERROR via `NETWORK_EVENT_CONST`.

O poller referencia os objetos: mantenha-os vivos e em endereço estável enquanto
registrados. Remova o registro antes de destruir o objeto. Use
`Event_Connection`, `Event_Listener` e `Event_Datagram` para verificar o tipo.
Prontidão não significa que todo o buffer possa ser transferido. Não existe um
escalonador, TLS, HTTP ou reconexão automática em segundo plano.

## Portabilidade

Em C11 estrito sobre POSIX, defina `_POSIX_C_SOURCE=200809L` antes dos headers.
O backend Windows carrega Winsock dinamicamente, sem `-lws2_32` no comando do
usuário. Isso ainda depende de APIs do sistema operacional em execução.

## Exemplo sem acesso externo

<!-- example: Network.c -->

[Network.c](../examples/Network.c)

```c
#include <assert.h>
#include "Congro/Modules/Network/Address/Address.h"

int main(void) {
  TNetwork_Address address;
  TNetwork_Address other;
  TNetwork_Endpoint endpoint;
  NETWORK_ADDRESS_FUNC(IPv4_Loopback)(&address);
  NETWORK_ADDRESS_FUNC(IPv4_Create)(&other, 127, 0, 0, 1);
  NETWORK_ADDRESS_FUNC(Endpoint_Create)(&endpoint, &address, 8080);
  assert(NETWORK_ADDRESS_FUNC(Equal)(&address, &other));
  assert(endpoint.port == 8080);
  return 0;
}
```

Para I/O completo, veja [TCP.c](../../Codespace/Tests/Network/TCP.c),
[UDP.c](../../Codespace/Tests/Network/UDP.c) e
[Poller.c](../../Codespace/Tests/Network/Poller.c). Esses testes usam sockets locais.
