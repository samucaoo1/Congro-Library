# Concurrency

Concurrency provides portable atomics, threads, sleeping, synchronization,
coroutines, tasks, futures, and thread pools.

**Root:** `Codespace/Congro/Modules/Concurrency`

Functions follow `CONCURRENCY_FUNC(Space, Name)`, for example:

```c
MUTEX_FUNC(Lock)(&mutex);
Concurrency_Mutex_Lock(&mutex);
```

## Atomic

**Header:** `Atomic/Atomic.h`

Types include `TAtomicU32`, `TAtomicPtr`, `TAtomicBool`, and `TMemoryOrder`.\n`TAtomicU64` is available when the target reports lock-free 64-bit atomics.

For `U32`, `U64`, and pointer atomics, the base family contains Load, Store,
Exchange, and CompareExchange.

Example:

```c
uint32_t value =
    ATOMIC_FUNC(U32_Load)(&counter, CONCURRENCY_ATOMIC_MEMORY_ORDER_SEQ_CST);

/* direct */
uint32_t same =
    Concurrency_Atomic_U32_Load(&counter, CONCURRENCY_ATOMIC_MEMORY_ORDER_SEQ_CST);
```

U32/U64 additionally provide:

- `ATOMIC_FUNC(U32_FetchAdd)` → `Concurrency_Atomic_U32_FetchAdd`
- `U32_FetchSub`, `U32_FetchAnd`, `U32_FetchOr`, `U32_FetchXor`
- corresponding `U64_*` operations.

Boolean atomics expose `Bool_Load`, `Bool_Store`, and `Bool_Exchange`.

## Thread

**Header:** `Thread/Thread.h`

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `THREAD_FUNC(Create)(&thread,fn,arg)` | `Concurrency_Thread_Create(...)` | Starts a thread. |
| `THREAD_FUNC(Join)(&thread)` | `Concurrency_Thread_Join(&thread)` | Waits for completion. |
| `THREAD_FUNC(Detach)(&thread)` | `Concurrency_Thread_Detach(&thread)` | Detaches ownership. |
| `THREAD_FUNC(Yield)()` | `Concurrency_Thread_Yield()` | Yields execution. |
| `THREAD_FUNC(Current)()` | `Concurrency_Thread_Current()` | Gets the native current-thread handle/id representation. |
| `THREAD_FUNC(Equal)(a,b)` | `Concurrency_Thread_Equal(a,b)` | Compares thread identities. |

## Sleep

**Header:** `Thread/Sleep.h`

- `THREAD_FUNC(SleepFor)(duration)` → `Concurrency_Thread_SleepFor(duration)`
- `THREAD_FUNC(SleepUntil)(deadline)` → `Concurrency_Thread_SleepUntil(deadline)`

These accept Chronometry types, keeping duration/deadline modeling consistent.

## Mutex

**Header:** `Synchronization/Mutex.h`

`Init`, `Destroy`, `Lock`, `TryLock`, and `Unlock`.

```c
TMutex mutex;
MUTEX_FUNC(Init)(&mutex);
MUTEX_FUNC(Lock)(&mutex);
/* protected work */
MUTEX_FUNC(Unlock)(&mutex);
MUTEX_FUNC(Destroy)(&mutex);
```

Direct calls are `Concurrency_Mutex_Init`, `Concurrency_Mutex_Lock`,
`Concurrency_Mutex_Unlock`, and `Concurrency_Mutex_Destroy`.

`TryLock` reports acquisition through a `bool *` output.

## RWLock

**Header:** `Synchronization/RWLock.h`

Operations:

`Init`, `Destroy`, `ReadLock`, `TryReadLock`, `ReadUnlock`,
`WriteLock`, `TryWriteLock`, `WriteUnlock`.

Example indirect/direct pair:

```c
RWLOCK_FUNC(ReadLock)(&lock);
Concurrency_RWLock_ReadLock(&lock);
```

## Condition

**Header:** `Synchronization/Condition.h`

- `CONDITION_FUNC(Init)` → `Concurrency_Condition_Init`
- `Destroy` → `Concurrency_Condition_Destroy`
- `Wait` → `Concurrency_Condition_Wait`
- `NotifyOne` → `Concurrency_Condition_NotifyOne`
- `NotifyAll` → `Concurrency_Condition_NotifyAll`

## Once

**Header:** `Synchronization/Once.h`

```c
ONCE_FUNC(Call)(&once, initialize_once);
Concurrency_Once_Call(&once, initialize_once);
```

The callback executes according to once-initialization semantics.

## Semaphore

**Header:** `Synchronization/Semaphore.h`

`Init`, `Destroy`, `Wait`, `TryWait`, and `Post`.

Direct family prefix: `Concurrency_Semaphore_`.

## Barrier

**Header:** `Synchronization/Barrier.h`

`Init(&barrier,count)`, `Wait(&barrier)`, and `Destroy(&barrier)`.

Direct family prefix: `Concurrency_Barrier_`.

## Coroutine

**Header:** `Coroutine/Coroutine.h`

Coroutines deliberately do not require an OS-thread backend.

- `COROUTINE_FUNC(Init)` → `Concurrency_Coroutine_Init`
- `Resume` → `Concurrency_Coroutine_Resume`
- `Reset` → `Concurrency_Coroutine_Reset`
- `GetState` → `Concurrency_Coroutine_GetState`
- `IsReady`, `IsRunning`, `IsSuspended`, `IsFinished`

Example:

```c
TCoroutine co;
COROUTINE_FUNC(Init)(&co, routine, context);

while (!COROUTINE_FUNC(IsFinished)(&co)) {
    COROUTINE_FUNC(Resume)(&co);
}
```

Direct form replaces those calls with `Concurrency_Coroutine_*`.

## Task

**Header:** `Task/Task.h`

- `TASK_FUNC(Create)(fn,arg)` → `Concurrency_Task_Create(fn,arg)`
- `TASK_FUNC(IsValid)(&task)` → `Concurrency_Task_IsValid(&task)`
- `TASK_FUNC(Run)(&task)` → `Concurrency_Task_Run(&task)`

## Future

**Header:** `Task/Future.h`

Lifecycle and synchronization:

`Init`, `Destroy`, `IsReady`, `Complete`, `Wait`, `Get`.

Direct family prefix: `Concurrency_Future_`.

`FUTURE_FUNC(Task)(&futureTask,&future,fn,arg)` creates a `TTask` that
completes the associated future.

## ThreadPool

**Header:** `Task/ThreadPool.h`

| Indirect | Direct |
| --- | --- |
| `THREAD_POOL_FUNC(Init)(...)` | `Concurrency_ThreadPool_Init(...)` |
| `THREAD_POOL_FUNC(Submit)(&pool,task)` | `Concurrency_ThreadPool_Submit(...)` |
| `THREAD_POOL_FUNC(TrySubmit)(&pool,task,&submitted)` | `Concurrency_ThreadPool_TrySubmit(...)` |
| `THREAD_POOL_FUNC(Shutdown)(&pool)` | `Concurrency_ThreadPool_Shutdown(&pool)` |
| `THREAD_POOL_FUNC(Destroy)(&pool)` | `Concurrency_ThreadPool_Destroy(&pool)` |

The caller supplies the thread array and task queue to `Init`, making storage
requirements explicit.
