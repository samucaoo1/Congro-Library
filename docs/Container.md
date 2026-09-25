# Container

Container is Congro's generic data-structure module. It contains flat/contiguous
containers, linked containers, ordered trees, hash maps, and adjacency-list
graphs.

**Root:** `Codespace/Congro/Modules/Container`

Container APIs are generated for concrete C types. Direct functions always
exist. When `CONTAINER_ENABLE_PSEUDO_METHODS == 1` (the default), selected
containers also carry an `api` table and the alias headers expose ergonomic
C11 `_Generic` operations.

## Calling styles

A vector operation can be written through its namespace macro:

```c
FLAT_VECTOR_FUNC(int, PushBack)(&values, 42);
```

or directly:

```c
Flat_Vector_int_PushBack(&values, 42);
```

With pseudo-methods enabled, generated instances can additionally use their
function table where available:

```c
values.api->pushBack(&values, 42);
```

The direct function remains the canonical API documented below.

---

# Flat / Vector

**Header:** `Array/Vector.h`

Built-in specializations: `int`, `float`, `double`.

Declaration helper:

```c
TVector(int, values);
```

The generated type is `FLAT_VECTOR_TYPE(int)`, directly
`Flat_TVector_int`.

## Lifecycle and capacity

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `FLAT_VECTOR_FUNC(int, Init)(&v)` | `Flat_Vector_int_Init(&v)` | Initializes an empty vector. |
| `...Destroy(&v)` | `Flat_Vector_int_Destroy(&v)` | Releases owned storage. |
| `...Reserve(&v,n)` | `Flat_Vector_int_Reserve(&v,n)` | Ensures capacity. |
| `...ShrinkToFit(&v)` | `Flat_Vector_int_ShrinkToFit(&v)` | Reduces spare capacity. |
| `...Clear(&v)` | `Flat_Vector_int_Clear(&v)` | Removes elements while retaining the object. |
| `...Empty(&v)` | `Flat_Vector_int_Empty(&v)` | Empty-state query. |
| `...Size(&v)` | `Flat_Vector_int_Size(&v)` | Number of elements. |
| `...Capacity(&v)` | `Flat_Vector_int_Capacity(&v)` | Allocated element capacity. |

## Access

- `FLAT_VECTOR_FUNC(int, At)(&v,index)` → `Flat_Vector_int_At`
- `Front` → `Flat_Vector_int_Front`
- `Back` → `Flat_Vector_int_Back`
- `Data` → `Flat_Vector_int_Data`

These return pointers into the container; their lifetime follows the vector's
storage lifetime and can be invalidated by operations that reallocate.

## Modifiers

- `PushBack` → `Flat_Vector_int_PushBack`
- `PopBack` → `Flat_Vector_int_PopBack`
- `PushFront` → `Flat_Vector_int_PushFront`
- `PopFront` → `Flat_Vector_int_PopFront`
- `Insert` → `Flat_Vector_int_Insert`
- `Erase` → `Flat_Vector_int_Erase`

Example:

```c
TVector(int, values);

FLAT_VECTOR_FUNC(int, Init)(&values);
FLAT_VECTOR_FUNC(int, PushBack)(&values, 10);
FLAT_VECTOR_FUNC(int, PushBack)(&values, 20);

int *last = FLAT_VECTOR_FUNC(int, Back)(&values);

FLAT_VECTOR_FUNC(int, Destroy)(&values);
```

Direct calls are `Flat_Vector_int_Init`, `Flat_Vector_int_PushBack`,
`Flat_Vector_int_Back`, and `Flat_Vector_int_Destroy`.

---

# Flat / Queue

**Header:** `Array/Queue.h`

Built-ins: `int`, `float`, `double`.

Type/direct type: `FLAT_QUEUE_TYPE(int)` / `Flat_TQueue_int`.

Declaration helper: `TFlat_Queue(int, queue)`.

Functions:

- `Init` → `Flat_Queue_int_Init`
- `Destroy` → `Flat_Queue_int_Destroy`
- `Reserve` → `Flat_Queue_int_Reserve`
- `ShrinkToFit` → `Flat_Queue_int_ShrinkToFit`
- `Compact` → `Flat_Queue_int_Compact`
- `Push` → `Flat_Queue_int_Push`
- `Pop` → `Flat_Queue_int_Pop`
- `Front`, `Back`
- `Empty`, `Size`, `Capacity`

`Compact` restores a compact contiguous layout after queue movement has left
unused leading storage.

Example:

```c
TFlat_Queue(int, queue);
FLAT_QUEUE_FUNC(int, Init)(&queue);
FLAT_QUEUE_FUNC(int, Push)(&queue, 7);

int value;
FLAT_QUEUE_FUNC(int, Pop)(&queue, &value);
FLAT_QUEUE_FUNC(int, Destroy)(&queue);
```

Direct family: `Flat_Queue_int_*`.

---

# Flat / Stack

**Header:** `Array/Stack.h`

Built-ins: `int`, `float`, `double`.

Declaration helper: `TFlat_Stack(int, stack)`.

Functions:

`Init`, `Destroy`, `Reserve`, `ShrinkToFit`, `Push`, `Pop`, `Top`,
`Empty`, `Size`, `Capacity`.

Indirect:

```c
FLAT_STACK_FUNC(int, Push)(&stack, 42);
int *top = FLAT_STACK_FUNC(int, Top)(&stack);
```

Direct:

```c
Flat_Stack_int_Push(&stack, 42);
int *top = Flat_Stack_int_Top(&stack);
```

---

# Flat / String

**Header:** `Array/String.h`

Generated forms:

- suffix `8` — UTF-8 storage
- suffix `16` — UTF-16 storage
- suffix `32` — UTF-32/code-unit storage

Type example: `TSTRING_TYPE(8)` → `Flat_TString_8`.

Declaration: `TString(8, text)`.

## Functions

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `TSTRING_FUNC(8, Init)(&s)` | `Flat_String_8_Init(&s)` | Initialize. |
| `...Destroy(&s)` | `Flat_String_8_Destroy(&s)` | Release storage. |
| `...FromCStr(&s,text)` | `Flat_String_8_FromCStr(...)` | Assign from a zero-terminated sequence. |
| `...CStr(&s)` | `Flat_String_8_CStr(&s)` | Obtain zero-terminated data. |
| `...Length(&s)` | `Flat_String_8_Length(&s)` | Logical length. |
| `...Empty(&s)` | `Flat_String_8_Empty(&s)` | Empty query. |
| `...Clear(&s)` | `Flat_String_8_Clear(&s)` | Clear contents. |
| `...Reserve(&s,n)` | `Flat_String_8_Reserve(...)` | Reserve capacity. |
| `...Capacity(&s)` | `Flat_String_8_Capacity(&s)` | Capacity query. |
| `...PushBack(&s,ch)` | `Flat_String_8_PushBack(...)` | Append one code unit. |
| `...PopBack(&s,&ch)` | `Flat_String_8_PopBack(...)` | Remove final code unit. |
| `...InsertChar(&s,pos,ch)` | `Flat_String_8_InsertChar(...)` | Insert one code unit. |
| `...At(&s,i)` | `Flat_String_8_At(...)` | Pointer to code unit. |
| `...Front(&s)` / `Back(&s)` | `Flat_String_8_Front/Back` | Endpoint access. |
| `...Append(&s,cstr)` | `Flat_String_8_Append(...)` | Append C-style text. |
| `...AppendStr(&s,&other)` | `Flat_String_8_AppendStr(...)` | Append another TString. |
| `...Insert(&s,pos,cstr)` | `Flat_String_8_Insert(...)` | Insert text. |
| `...Erase(&s,pos,count)` | `Flat_String_8_Erase(...)` | Remove a range. |
| `...Substr(&s,pos,count,&out)` | `Flat_String_8_Substr(...)` | Extract a substring. |
| `...Compare(&a,&b,&cmp)` | `Flat_String_8_Compare(...)` | Compare two strings. |
| `...Find(&s,ch,start,&index)` | `Flat_String_8_Find(...)` | Find a code unit. |
| `...FindStr(&s,needle,start,&index)` | `Flat_String_8_FindStr(...)` | Find a sequence. |
| `...Data(&s)` | `Flat_String_8_Data(&s)` | Mutable underlying data. |

---

# Linked / ForwardList

**Header:** `Linked/Forward.h`

Built-ins: `int`, `float`, `double`, `char`.

Declaration: `TLinked_ForwardList(int, list)`.

Direct type: `Linked_TForwardList_int`.

Operations:

`Init`, `Destroy`, `PushFront`, `PopFront`, `InsertAfter`,
`EraseAfter`, `Clear`, `Front`, `Back`, `Begin`, `Empty`, `Size`.

Example pair:

```c
LINKED_FORWARD_LIST_FUNC(int, PushFront)(&list, 42);
Linked_ForwardList_int_PushFront(&list, 42);
```

---

# Linked / List

**Header:** `Linked/List.h`

Built-ins: `int`, `float`, `double`, `char`, `void_ptr`.

Declaration: `TLinked_List(int, list)`.

Functions:

`Init`, `Destroy`, `Front`, `Back`, `Begin`, `End`, `PushFront`,
`PushBack`, `PopFront`, `PopBack`, `Insert`, `Erase`, `Clear`,
`Empty`, `Size`.

Direct family: `Linked_List_int_*`.

`Insert` and `Erase` work with generated node pointers, making node-oriented
list operations explicit rather than hiding iterator state.

---

# Linked / Deque, Queue, Stack

**Headers:** `Linked/Deque.h`, `Queue.h`, `Stack.h`

Deque operations:
`Init`, `Destroy`, `PushFront`, `PushBack`, `PopFront`, `PopBack`,
`Clear`, `Front`, `Back`, `Empty`, `Size`.

Queue operations:
`Init`, `Destroy`, `Push`, `Pop`, `Clear`, `Front`, `Back`,
`Empty`, `Size`.

Stack operations:
`Init`, `Destroy`, `Push`, `Pop`, `Clear`, `Top`, `Empty`,
`Size`.

Example:

```c
TLinked_Deque(int, deque);
LINKED_DEQUE_FUNC(int, Init)(&deque);
LINKED_DEQUE_FUNC(int, PushBack)(&deque, 1);
LINKED_DEQUE_FUNC(int, PushFront)(&deque, 0);
```

Direct: `Linked_Deque_int_Init`, `Linked_Deque_int_PushBack`,
`Linked_Deque_int_PushFront`.

---

# Tree

**Header:** `Tree/Tree.h`

Algorithms:

- `BST` — binary search tree
- `AVL` — height-balanced tree
- `RB` — red-black tree

Both sets and maps are generated.

Examples of types:

```c
TTREE_SET_TYPE(AVL, int)       /* Tree_AVL_Set_int */
TTREE_MAP_TYPE(AVL, int, float) /* Tree_AVL_Map_int_float */
```

Built-ins currently include set keys `int`, `float`, `double`; maps include
`int -> int` and `int -> float`.

## Common operations

Set/map families provide:

`Init`, `Destroy`, `Clear`, `Insert`, `Remove`, `FindNode`, `Find`,
`Contains`, `MinNode`, `MaxNode`, `Min`, `Max`, `Empty`, `Size`,
`Begin`, `End`, `Next`, `Prev`, `ConstBegin`, `ConstEnd`,
`ConstNext`, `ConstPrev`.

The set `Insert` accepts a key. Map `Insert` accepts key and value.

Example:

```c
TTree_AVL_Set(int, numbers);

TTREE_FN(TTREE_SET_TYPE(AVL, int), Init)(&numbers);
TTREE_FN(TTREE_SET_TYPE(AVL, int), Insert)(&numbers, 42);

bool found =
    TTREE_FN(TTREE_SET_TYPE(AVL, int), Contains)(&numbers, 42);
```

Direct:

```c
Tree_AVL_Set_int_Init(&numbers);
Tree_AVL_Set_int_Insert(&numbers, 42);
bool found = Tree_AVL_Set_int_Contains(&numbers, 42);
```

When pseudo-method aliases are enabled, `TreeInsert(numbers, 42)`,
`TreeContains(numbers, 42)`, `TreeSize(numbers)`, etc. provide C11
`_Generic` dispatch.

---

# Hash

**Header:** `Hash/Hash.h`

The implementation is an open-addressed hash map with linear probing.

Built-in maps currently include `int -> int` and `int -> void *`.

Type:

```c
THASH_TYPE(int, int)   /* THash_int_int */
```

Operations:

| Indirect | Direct |
| --- | --- |
| `HASH_OPERATION(int,int,Init)(&h)` | `Hash_int_int_Init(&h)` |
| `...Destroy(&h)` | `Hash_int_int_Destroy(&h)` |
| `...Rehash(&h,n)` | `Hash_int_int_Rehash(&h,n)` |
| `...Find(&h,key)` | `Hash_int_int_Find(&h,key)` |
| `...ConstFind(&h,key)` | `Hash_int_int_ConstFind(&h,key)` |
| `...Contains(&h,key)` | `Hash_int_int_Contains(&h,key)` |
| `...Insert(&h,key,value)` | `Hash_int_int_Insert(...)` |
| `...Remove(&h,key)` | `Hash_int_int_Remove(...)` |
| `...Clear(&h)` | `Hash_int_int_Clear(&h)` |
| `...IsEmpty(&h)` | `Hash_int_int_IsEmpty(&h)` |
| `...Size(&h)` | `Hash_int_int_Size(&h)` |
| `...Capacity(&h)` | `Hash_int_int_Capacity(&h)` |

Custom generated maps use `HASH_MAP_DEFINE`/the declaration plumbing with an
explicit hash function and equality function.

Helpers include `HASH_INT`, `HASH_CSTRING`, `HASH_EQUAL_INT`,
`HASH_EQUAL_CSTRING`, and the direct `Hash_CString` function.

---

# Graph

**Header:** `Graph/Graph.h`

Graph uses adjacency lists and generated vertex/weight types.

Built-ins:

- `int` vertices with `int` weights
- `int` vertices with `float` weights

Type:

```c
TGRAPH_TYPE(int, float) /* TGraph_int_float */
```

Operations:

- `GRAPH_OPERATION(int,float,Init)` → `Graph_int_float_Init`
- `Destroy`, `Clear`
- `AddVertex`, `RemoveVertex`
- `AddEdge`, `RemoveEdge`
- `HasEdge`
- `FindWeight`, `ConstFindWeight`
- `VertexCount`, `EdgeCount`, `IsEmpty`
- `BFS`, `DFS`

Example:

```c
TGRAPH_TYPE(int, float) graph;
size_t a, b;

GRAPH_OPERATION(int, float, Init)(&graph);
GRAPH_OPERATION(int, float, AddVertex)(&graph, 10, &a);
GRAPH_OPERATION(int, float, AddVertex)(&graph, 20, &b);
GRAPH_OPERATION(int, float, AddEdge)(&graph, a, b, 1.5f);
```

Direct:

```c
TGraph_int_float graph;
Graph_int_float_Init(&graph);
Graph_int_float_AddVertex(&graph, 10, &a);
Graph_int_float_AddVertex(&graph, 20, &b);
Graph_int_float_AddEdge(&graph, a, b, 1.5f);
```

`BFS` and `DFS` accept a generated visitor callback plus a `void *context`.

---

# Generic aliases

**Headers:** `Aliases/Linear.h`, `Aliases/Tree.h`

When pseudo-methods are enabled, the built-in linear specializations can use
generic operation names:

`Push`, `PushBack`, `PushFront`, `Pop`, `PopBack`, `PopFront`,
`At`, `Front`, `Back`, `Top`, `Reserve`, `Capacity`, `Data`,
`Insert`, `Erase`, `Clear`, `Empty`, `Size`, `Destroy`.

Example:

```c
TVector(int, values);
FLAT_VECTOR_FUNC(int, Init)(&values);

PushBack(values, 42);
int *first = Front(values);
Destroy(values);
```

These aliases are convenience dispatch. For custom generated types or code that
prefers maximum explicitness, use the generated direct functions.
