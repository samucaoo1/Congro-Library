# Concurrency

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Concurrency.md)

Inclua `Congro/Modules/Concurrency/Concurrency.h` ou um pacote específico.
Os backends usam pthreads em POSIX e primitivas Windows. Veja o
[contrato de compilação](../GettingStarted.md) antes de incluir headers do sistema.

## Pacotes

| Pacote | API principal | Contrato |
|---|---|---|
| Atomic | `TAtomicU32`, `TAtomicU64`, `TAtomicPtr`, `TAtomicBool`; `Load`, `Store`, `Exchange`, `CompareExchange`, `FetchAdd/Sub/And/Or/Xor` | Verifique as macros `CONCURRENCY_HAS_ATOMIC_*`; U64 é condicional. Escolha ordens de memória válidas. |
| Thread | `Create`, `Join`, `Detach`, `Yield`, `Current`, `Equal` | Callback `void (*)(void *)`; cada thread criada deve ser unida ou destacada. |
| Sleep | `SleepFor`, `SleepUntil` | Recebem Duration e ClockTimePoint de Chronometry. |
| Mutex | `Init`, `Destroy`, `Lock`, `TryLock`, `Unlock` | Exclusão mútua; `TryLock` também informa `acquired`. |
| RWLock | `ReadLock`, `WriteLock`, variantes `Try*`, `ReadUnlock`, `WriteUnlock` | Emparelhe a liberação com o modo adquirido. |
| Condition | `Wait`, `NotifyOne`, `NotifyAll` | Espere com mutex adquirido e reavalie o predicado em um laço. |
| Once | `ONCE_INIT`, `Call` | Inicialização única por objeto `TOnce`. |
| Semaphore | `Init`, `Wait`, `TryWait`, `Post`, `Destroy` | Contador de permissões; `TryWait` informa se adquiriu. |
| Barrier | `Init`, `Wait`, `Destroy` | Sincronização por gerações com número fixo de participantes. |
| Task | `Create`, `IsValid`, `Run` | Descritor de callback e argumento; `Run` executa na thread atual. |
| Future | `Init`, `Complete`, `IsReady`, `Wait`, `Get`, `Task`, `Destroy` | Resultado por `void *`, com status da tarefa separado do status da consulta. |
| ThreadPool | `Init`, `Submit`, `TrySubmit`, `Shutdown`, `Destroy` | Workers e fila fornecidos pelo chamador. |
| Coroutine | `Init`, `Resume`, `Reset`, `GetState`, consultas `Is*` | Execução cooperativa sem pilha própria. |

## Ciclo de vida e propriedade

Inicialize objetos antes do uso. Não copie mutexes, condições, threads ou pools
ativos por atribuição. Mantenha argumentos de callbacks e buffers vivos até o
fim das tarefas. Destrua primitivas somente depois de cessar seu uso por outras
threads. `Join` recebe apenas o ponteiro da thread; o callback não retorna um
valor. Use dados compartilhados sincronizados ou Future para resultados.

O pool não aloca os arrays `TThread[]` e `TTask[]`: o chamador fornece capacidade
não nula para ambos. `Submit` pode esperar por espaço. `TrySubmit` retorna
`WOULD_BLOCK` se a fila estiver cheia. `Shutdown` interrompe novas submissões e
permite consumir tarefas enfileiradas; `Destroy` faz shutdown e join dos workers.
Não chame `Destroy` de um worker do próprio pool: retorna `BUSY`.

Future não libera automaticamente a memória apontada pelo resultado. O
`TFutureTask`, seu argumento e o Future devem existir até terminar a execução.
`Get(future, &result, &resultStatus)` distingue falha ao obter o resultado da
falha reportada pela função executada.

## Coroutines

Use `COROUTINE_BEGIN`, `COROUTINE_YIELD` e `COROUTINE_END` dentro do callback.
Cada yield precisa de uma linha própria: a continuação usa `__LINE__`. Variáveis
automáticas não são preservadas entre resumes; guarde estado persistente no
argumento/contexto. Não faça yield dentro de outro `switch` que capture os
rótulos da macro. `Resume` executa na thread chamadora; não cria paralelismo nem
um escalonador. `Reset` reinicia a continuação, não os dados do seu contexto.

## Atomics

As macros `ATOMIC_*_INIT` inicializam os objetos. `Fetch*` retorna o valor
anterior. Em `CompareExchange`, `expected` também é saída quando a comparação
falha. A ordem de falha não deve ser RELEASE ou ACQ_REL; use uma combinação
válida para o backend. Uma operação atômica isolada não torna um objeto composto
inteiro seguro para acesso concorrente.

## Exemplos

<!-- example: Concurrency.c -->

[Concurrency.c](../examples/Concurrency.c)

```c
#include <assert.h>
#include "Congro/Modules/Concurrency/Thread/Thread.h"

static void Work(void *argument) {
  int *result = argument;
  *result = 42;
}

int main(void) {
  TThread thread = {0};
  int result = 0;
  if (THREAD_FUNC(Create)(&thread, Work, &result) != STATUS_CONST(SUCCESS))
    return 1;
  if (THREAD_FUNC(Join)(&thread) != STATUS_CONST(SUCCESS))
    return 2;
  assert(result == 42);
  return 0;
}
```

<!-- example: Coroutine.c -->

[Coroutine.c](../examples/Coroutine.c)

```c
#include <assert.h>
#include "Congro/Modules/Concurrency/Coroutine/Coroutine.h"

static void Count(TCoroutine *coroutine, void *argument) {
  int *value = argument;
  COROUTINE_BEGIN(coroutine);
  ++*value;
  COROUTINE_YIELD(coroutine);
  ++*value;
  COROUTINE_END(coroutine);
}

int main(void) {
  int value = 0;
  TCoroutine coroutine = COROUTINE_INIT(Count, &value);
  if (COROUTINE_FUNC(Resume)(&coroutine) != STATUS_CONST(SUCCESS))
    return 1;
  assert(value == 1 && COROUTINE_FUNC(IsSuspended)(&coroutine));
  if (COROUTINE_FUNC(Resume)(&coroutine) != STATUS_CONST(SUCCESS))
    return 2;
  assert(value == 2 && COROUTINE_FUNC(IsFinished)(&coroutine));
  return 0;
}
```

[Testes de threads, sincronização, futures e coroutines](../../Codespace/Tests/Concurrency).
