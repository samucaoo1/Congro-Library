# Concurrency: referência de API

[Guia de uso](../modules/Concurrency.md) · [Índice](../INDEX.md)

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
| [Atomic/Atomic.h](../../Codespace/Congro/Modules/Concurrency/Atomic/Atomic.h) | 17 |
| [Concurrency.h](../../Codespace/Congro/Modules/Concurrency/Concurrency.h) | 0 |
| [Concurrency.space](../../Codespace/Congro/Modules/Concurrency/Concurrency.space) | 0 |
| [Coroutine/Coroutine.h](../../Codespace/Congro/Modules/Concurrency/Coroutine/Coroutine.h) | 8 |
| [Synchronization/Barrier.h](../../Codespace/Congro/Modules/Concurrency/Synchronization/Barrier.h) | 3 |
| [Synchronization/Condition.h](../../Codespace/Congro/Modules/Concurrency/Synchronization/Condition.h) | 5 |
| [Synchronization/Mutex.h](../../Codespace/Congro/Modules/Concurrency/Synchronization/Mutex.h) | 5 |
| [Synchronization/Once.h](../../Codespace/Congro/Modules/Concurrency/Synchronization/Once.h) | 1 |
| [Synchronization/RWLock.h](../../Codespace/Congro/Modules/Concurrency/Synchronization/RWLock.h) | 8 |
| [Synchronization/Semaphore.h](../../Codespace/Congro/Modules/Concurrency/Synchronization/Semaphore.h) | 5 |
| [Task/Future.h](../../Codespace/Congro/Modules/Concurrency/Task/Future.h) | 7 |
| [Task/Task.h](../../Codespace/Congro/Modules/Concurrency/Task/Task.h) | 3 |
| [Task/ThreadPool.h](../../Codespace/Congro/Modules/Concurrency/Task/ThreadPool.h) | 5 |
| [Thread/Sleep.h](../../Codespace/Congro/Modules/Concurrency/Thread/Sleep.h) | 2 |
| [Thread/Thread.h](../../Codespace/Congro/Modules/Concurrency/Thread/Thread.h) | 6 |

## Atomic/Atomic.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Atomic/Atomic.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CONCURRENCY_HAS_ATOMIC_U32`
- `CONCURRENCY_HAS_ATOMIC_U64`
- `CONCURRENCY_HAS_ATOMIC_PTR`
- `ATOMIC_U32_INIT(VALUE)`
- `ATOMIC_U64_INIT(VALUE)`
- `ATOMIC_PTR_INIT(VALUE)`
- `ATOMIC_BOOL_INIT(VALUE)`
- `ATOMIC_DECLARE(TYPE, SUFFIX)`

```c
TYPE ATOMIC_FUNC(SUFFIX##_Load)(const TAtomic##SUFFIX *atomic, TMemoryOrder order);

void ATOMIC_FUNC(SUFFIX##_Store)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

TYPE ATOMIC_FUNC(SUFFIX##_Exchange)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

bool ATOMIC_FUNC(SUFFIX##_CompareExchange)( TAtomic##SUFFIX *atomic, TYPE *expected, TYPE
    desired, TMemoryOrder success, TMemoryOrder failure);

uint32_t ATOMIC_FUNC(U32_FetchAdd)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

uint32_t ATOMIC_FUNC(U32_FetchSub)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

uint32_t ATOMIC_FUNC(U32_FetchAnd)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

uint32_t ATOMIC_FUNC(U32_FetchOr)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

uint32_t ATOMIC_FUNC(U32_FetchXor)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

uint64_t ATOMIC_FUNC(U64_FetchAdd)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

uint64_t ATOMIC_FUNC(U64_FetchSub)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

uint64_t ATOMIC_FUNC(U64_FetchAnd)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

uint64_t ATOMIC_FUNC(U64_FetchOr)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

uint64_t ATOMIC_FUNC(U64_FetchXor)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

bool ATOMIC_FUNC(Bool_Load)(const TAtomicBool *atomic, TMemoryOrder order);

void ATOMIC_FUNC(Bool_Store)(TAtomicBool *atomic, bool value, TMemoryOrder order);

bool ATOMIC_FUNC(Bool_Exchange)(TAtomicBool *atomic, bool value, TMemoryOrder order);

```

## Concurrency.space

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Concurrency.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CONCURRENCY_MOD(NAME)`
- `CONCURRENCY_FUNC(SPACE, NAME)`
- `CONCURRENCY_TYPE(NAME)`
- `CONCURRENCY_CONST(SPACE, NAME)`
- `ATOMIC_FUNC(NAME)`
- `THREAD_FUNC(NAME)`
- `COROUTINE_FUNC(NAME)`
- `MUTEX_FUNC(NAME)`
- `RWLOCK_FUNC(NAME)`
- `CONDITION_FUNC(NAME)`
- `ONCE_FUNC(NAME)`
- `SEMAPHORE_FUNC(NAME)`
- `BARRIER_FUNC(NAME)`
- `TASK_FUNC(NAME)`
- `THREAD_POOL_FUNC(NAME)`
- `FUTURE_FUNC(NAME)`


## Coroutine/Coroutine.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Coroutine/Coroutine.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `COROUTINE_INIT(FUNCTION, ARGUMENT)`
- `COROUTINE_BEGIN(COROUTINE)`
- `COROUTINE_YIELD(COROUTINE)`
- `COROUTINE_END(COROUTINE)`

```c
OPSTATUS COROUTINE_FUNC(Init)(TCoroutine *coroutine, TCoroutineFunction function, void
    *argument);

OPSTATUS COROUTINE_FUNC(Resume)(TCoroutine *coroutine);

OPSTATUS COROUTINE_FUNC(Reset)(TCoroutine *coroutine);

TCoroutineState COROUTINE_FUNC(GetState)(const TCoroutine *coroutine);

bool COROUTINE_FUNC(IsReady)(const TCoroutine *coroutine);

bool COROUTINE_FUNC(IsRunning)(const TCoroutine *coroutine);

bool COROUTINE_FUNC(IsSuspended)(const TCoroutine *coroutine);

bool COROUTINE_FUNC(IsFinished)(const TCoroutine *coroutine);

```

## Synchronization/Barrier.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Synchronization/Barrier.h)

```c
OPSTATUS BARRIER_FUNC(Init)(TBarrier *barrier, unsigned count);

OPSTATUS BARRIER_FUNC(Destroy)(TBarrier *barrier);

OPSTATUS BARRIER_FUNC(Wait)(TBarrier *barrier);

```

## Synchronization/Condition.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Synchronization/Condition.h)

```c
OPSTATUS CONDITION_FUNC(Init)(TCondition *condition);

OPSTATUS CONDITION_FUNC(Destroy)(TCondition *condition);

OPSTATUS CONDITION_FUNC(Wait)(TCondition *condition, TMutex *mutex);

OPSTATUS CONDITION_FUNC(NotifyOne)(TCondition *condition);

OPSTATUS CONDITION_FUNC(NotifyAll)(TCondition *condition);

```

## Synchronization/Mutex.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Synchronization/Mutex.h)

```c
OPSTATUS MUTEX_FUNC(Init)(TMutex *mutex);

OPSTATUS MUTEX_FUNC(Destroy)(TMutex *mutex);

OPSTATUS MUTEX_FUNC(Lock)(TMutex *mutex);

OPSTATUS MUTEX_FUNC(TryLock)(TMutex *mutex, bool *acquired);

OPSTATUS MUTEX_FUNC(Unlock)(TMutex *mutex);

```

## Synchronization/Once.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Synchronization/Once.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `ONCE_INIT`

```c
OPSTATUS ONCE_FUNC(Call)(TOnce *once, TOnceFunction function);

```

## Synchronization/RWLock.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Synchronization/RWLock.h)

```c
OPSTATUS RWLOCK_FUNC(Init)(TRWLock *lock);

OPSTATUS RWLOCK_FUNC(Destroy)(TRWLock *lock);

OPSTATUS RWLOCK_FUNC(ReadLock)(TRWLock *lock);

OPSTATUS RWLOCK_FUNC(TryReadLock)(TRWLock *lock, bool *acquired);

OPSTATUS RWLOCK_FUNC(ReadUnlock)(TRWLock *lock);

OPSTATUS RWLOCK_FUNC(WriteLock)(TRWLock *lock);

OPSTATUS RWLOCK_FUNC(TryWriteLock)(TRWLock *lock, bool *acquired);

OPSTATUS RWLOCK_FUNC(WriteUnlock)(TRWLock *lock);

```

## Synchronization/Semaphore.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Synchronization/Semaphore.h)

```c
OPSTATUS SEMAPHORE_FUNC(Init)(TSemaphore *semaphore, unsigned value);

OPSTATUS SEMAPHORE_FUNC(Destroy)(TSemaphore *semaphore);

OPSTATUS SEMAPHORE_FUNC(Wait)(TSemaphore *semaphore);

OPSTATUS SEMAPHORE_FUNC(TryWait)(TSemaphore *semaphore, bool *acquired);

OPSTATUS SEMAPHORE_FUNC(Post)(TSemaphore *semaphore);

```

## Task/Future.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Task/Future.h)

```c
OPSTATUS FUTURE_FUNC(Init)(TFuture *future);

OPSTATUS FUTURE_FUNC(Destroy)(TFuture *future);

bool FUTURE_FUNC(IsReady)(const TFuture *future);

OPSTATUS FUTURE_FUNC(Complete)(TFuture *future, void *result, OPSTATUS status);

OPSTATUS FUTURE_FUNC(Wait)(TFuture *future);

OPSTATUS FUTURE_FUNC(Get)(TFuture *future, void **result, OPSTATUS *resultStatus);

TTask FUTURE_FUNC(Task)(TFutureTask *futureTask, TFuture *future, TFutureFunction function, void
    *argument);

```

## Task/Task.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Task/Task.h)

```c
TTask TASK_FUNC(Create)(TTaskFunction function, void *argument);

bool TASK_FUNC(IsValid)(const TTask *task);

OPSTATUS TASK_FUNC(Run)(const TTask *task);

```

## Task/ThreadPool.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Task/ThreadPool.h)

```c
OPSTATUS THREAD_POOL_FUNC(Init)(TThreadPool *pool, TThread *threads, size_t threadCount, TTask
    *queue, size_t queueCapacity);

OPSTATUS THREAD_POOL_FUNC(Submit)(TThreadPool *pool, TTask task);

OPSTATUS THREAD_POOL_FUNC(TrySubmit)(TThreadPool *pool, TTask task, bool *submitted);

OPSTATUS THREAD_POOL_FUNC(Shutdown)(TThreadPool *pool);

OPSTATUS THREAD_POOL_FUNC(Destroy)(TThreadPool *pool);

```

## Thread/Sleep.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Thread/Sleep.h)

```c
OPSTATUS THREAD_FUNC(SleepFor)( CHRONOMETRY_TYPE(Duration) duration);

OPSTATUS THREAD_FUNC(SleepUntil)( CHRONOMETRY_TYPE(ClockTimePoint) deadline);

```

## Thread/Thread.h

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Thread/Thread.h)

```c
OPSTATUS THREAD_FUNC(Create)(TThread *thread, TThreadFunction function, void *argument);

OPSTATUS THREAD_FUNC(Join)(TThread *thread);

OPSTATUS THREAD_FUNC(Detach)(TThread *thread);

void THREAD_FUNC(Yield)(void);

TThreadNative THREAD_FUNC(Current)(void);

bool THREAD_FUNC(Equal)(TThreadNative first, TThreadNative second);

```

## Atomic/Impl/Atomic.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Atomic/Impl/Atomic.impl)

```c
TYPE ATOMIC_FUNC(SUFFIX##_FetchAdd)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

TYPE ATOMIC_FUNC(SUFFIX##_FetchSub)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

TYPE ATOMIC_FUNC(SUFFIX##_FetchAnd)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

TYPE ATOMIC_FUNC(SUFFIX##_FetchOr)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

TYPE ATOMIC_FUNC(SUFFIX##_FetchXor)(TAtomic##SUFFIX *atomic, TYPE value, TMemoryOrder order);

```

## Atomic/Impl/MSVC.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Atomic/Impl/MSVC.impl)

```c
uint32_t ATOMIC_FUNC(U32_Load)(const TAtomicU32 *atomic, TMemoryOrder order);

void ATOMIC_FUNC(U32_Store)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

uint32_t ATOMIC_FUNC(U32_Exchange)(TAtomicU32 *atomic, uint32_t value, TMemoryOrder order);

bool ATOMIC_FUNC(U32_CompareExchange)(TAtomicU32 *atomic, uint32_t *expected, uint32_t desired,
    TMemoryOrder success, TMemoryOrder failure);

uint64_t ATOMIC_FUNC(U64_Load)(const TAtomicU64 *atomic, TMemoryOrder order);

void ATOMIC_FUNC(U64_Store)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

uint64_t ATOMIC_FUNC(U64_Exchange)(TAtomicU64 *atomic, uint64_t value, TMemoryOrder order);

bool ATOMIC_FUNC(U64_CompareExchange)(TAtomicU64 *atomic, uint64_t *expected, uint64_t desired,
    TMemoryOrder success, TMemoryOrder failure);

uintptr_t ATOMIC_FUNC(Ptr_Load)(const TAtomicPtr *atomic, TMemoryOrder order);

void ATOMIC_FUNC(Ptr_Store)(TAtomicPtr *atomic, uintptr_t value, TMemoryOrder order);

uintptr_t ATOMIC_FUNC(Ptr_Exchange)(TAtomicPtr *atomic, uintptr_t value, TMemoryOrder order);

bool ATOMIC_FUNC(Ptr_CompareExchange)(TAtomicPtr *atomic, uintptr_t *expected, uintptr_t
    desired, TMemoryOrder success, TMemoryOrder failure);

```

## Task/Impl/Future.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Concurrency/Task/Impl/Future.impl)

```c
OPSTATUS FUTURE_FUNC(Complete)(TFuture *future, void *result, OPSTATUS resultStatus);

```
