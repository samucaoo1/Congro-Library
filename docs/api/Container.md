# Container: referência de API

[Guia de uso](../modules/Container.md) · [Índice](../INDEX.md)

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
| [Aliases/Commons.h](../../Codespace/Congro/Modules/Container/Aliases/Commons.h) | 0 |
| [Aliases/Linear.h](../../Codespace/Congro/Modules/Container/Aliases/Linear.h) | 0 |
| [Aliases/Tree.h](../../Codespace/Congro/Modules/Container/Aliases/Tree.h) | 0 |
| [Array/Flat.space](../../Codespace/Congro/Modules/Container/Array/Flat.space) | 0 |
| [Array/Queue.h](../../Codespace/Congro/Modules/Container/Array/Queue.h) | 12 |
| [Array/Stack.h](../../Codespace/Congro/Modules/Container/Array/Stack.h) | 10 |
| [Array/String.h](../../Codespace/Congro/Modules/Container/Array/String.h) | 24 |
| [Array/VTable/Queue.h](../../Codespace/Congro/Modules/Container/Array/VTable/Queue.h) | 0 |
| [Array/VTable/Stack.h](../../Codespace/Congro/Modules/Container/Array/VTable/Stack.h) | 0 |
| [Array/VTable/String.h](../../Codespace/Congro/Modules/Container/Array/VTable/String.h) | 0 |
| [Array/VTable/Vector.h](../../Codespace/Congro/Modules/Container/Array/VTable/Vector.h) | 0 |
| [Array/Vector.h](../../Codespace/Congro/Modules/Container/Array/Vector.h) | 18 |
| [Container.space](../../Codespace/Congro/Modules/Container/Container.space) | 0 |
| [Graph/Graph.h](../../Codespace/Congro/Modules/Container/Graph/Graph.h) | 15 |
| [Graph/Graph.space](../../Codespace/Congro/Modules/Container/Graph/Graph.space) | 0 |
| [Graph/VTable/Graph.h](../../Codespace/Congro/Modules/Container/Graph/VTable/Graph.h) | 0 |
| [Hash/Hash.h](../../Codespace/Congro/Modules/Container/Hash/Hash.h) | 12 |
| [Hash/Hash.space](../../Codespace/Congro/Modules/Container/Hash/Hash.space) | 1 |
| [Hash/VTable/Hash.h](../../Codespace/Congro/Modules/Container/Hash/VTable/Hash.h) | 0 |
| [Linked/Deque.h](../../Codespace/Congro/Modules/Container/Linked/Deque.h) | 11 |
| [Linked/Forward.h](../../Codespace/Congro/Modules/Container/Linked/Forward.h) | 12 |
| [Linked/Linked.space](../../Codespace/Congro/Modules/Container/Linked/Linked.space) | 0 |
| [Linked/List.h](../../Codespace/Congro/Modules/Container/Linked/List.h) | 15 |
| [Linked/Node.h](../../Codespace/Congro/Modules/Container/Linked/Node.h) | 0 |
| [Linked/Queue.h](../../Codespace/Congro/Modules/Container/Linked/Queue.h) | 9 |
| [Linked/Stack.h](../../Codespace/Congro/Modules/Container/Linked/Stack.h) | 8 |
| [Linked/VTable/Deque.h](../../Codespace/Congro/Modules/Container/Linked/VTable/Deque.h) | 0 |
| [Linked/VTable/Forward.h](../../Codespace/Congro/Modules/Container/Linked/VTable/Forward.h) | 0 |
| [Linked/VTable/List.h](../../Codespace/Congro/Modules/Container/Linked/VTable/List.h) | 0 |
| [Linked/VTable/Queue.h](../../Codespace/Congro/Modules/Container/Linked/VTable/Queue.h) | 0 |
| [Linked/VTable/Stack.h](../../Codespace/Congro/Modules/Container/Linked/VTable/Stack.h) | 0 |
| [Tree/AVL.h](../../Codespace/Congro/Modules/Container/Tree/AVL.h) | 0 |
| [Tree/BST.h](../../Codespace/Congro/Modules/Container/Tree/BST.h) | 0 |
| [Tree/RedBlack.h](../../Codespace/Congro/Modules/Container/Tree/RedBlack.h) | 0 |
| [Tree/Tree.h](../../Codespace/Congro/Modules/Container/Tree/Tree.h) | 0 |
| [Tree/Tree.space](../../Codespace/Congro/Modules/Container/Tree/Tree.space) | 0 |
| [Tree/VTable/Tree.h](../../Codespace/Congro/Modules/Container/Tree/VTable/Tree.h) | 0 |

## Aliases/Linear.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Aliases/Linear.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CONTAINER_VECTOR_ASSOC(OP)`
- `CONTAINER_FLAT_QUEUE_ASSOC(OP)`
- `CONTAINER_FLAT_STACK_ASSOC(OP)`
- `CONTAINER_STRING_ASSOC(OP)`
- `CONTAINER_LIST_ASSOC(OP)`
- `CONTAINER_FORWARD_ASSOC(OP)`
- `CONTAINER_DEQUE_ASSOC(OP)`
- `CONTAINER_LINKED_QUEUE_ASSOC(OP)`
- `CONTAINER_LINKED_STACK_ASSOC(OP)`
- `Push(self, value)`
- `PushBack(self, value)`
- `PushFront(self, value)`
- `Pop(...)`
- `PopBack(...)`
- `PopFront(...)`
- `At(self, index)`
- `Front(self)`
- `Back(self)`
- `Top(self)`
- `Reserve(self, count)`
- `Capacity(self)`
- `Data(self)`
- `Insert(...)`
- `Erase(self, position, countOrOut)`
- `Clear(self)`
- `Empty(self)`
- `Size(self)`
- `Destroy(self)`


## Aliases/Tree.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Aliases/Tree.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TREE_ALIAS_SELECT_INSERT(_1, _2, _3, NAME, ...)`
- `TREE_SET_ASSOC(ALG, OP)`
- `TREE_MAP_ASSOC(ALG, OP)`
- `TREE_ALL_ASSOC(OP)`
- `TreeInit(self)`
- `TreeDestroy(self)`
- `TreeClear(self)`
- `TREE_INSERT_SET(self, key)`
- `TREE_INSERT_MAP(self, key, value)`
- `TreeInsert(...)`
- `TreeRemove(self, key)`
- `TreeFind(self, key)`
- `TreeFindNode(self, key)`
- `TreeContains(self, key)`
- `TreeMin(self)`
- `TreeMax(self)`
- `TreeEmpty(self)`
- `TreeSize(self)`
- `TreeBegin(self)`
- `TreeEnd(self)`
- `TreeNext(self, node)`
- `TreePrev(self, node)`
- `TreeConstBegin(self)`
- `TreeConstEnd(self)`
- `TreeConstNext(self, node)`
- `TreeConstPrev(self, node)`


## Array/Flat.space

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Array/Flat.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `FLAT_NS(NAME)`
- `FLAT_GROWTH_FACTOR`
- `FLAT_INITIAL_CAPACITY`
- `FLAT_VECTOR_GROWTH_FACTOR`
- `FLAT_VECTOR_INITIAL_CAPACITY`
- `FLAT_QUEUE_GROWTH_FACTOR`
- `FLAT_QUEUE_INITIAL_CAPACITY`
- `FLAT_STACK_GROWTH_FACTOR`
- `FLAT_STACK_INITIAL_CAPACITY`
- `TSTRING_GROWTH_FACTOR`
- `TSTRING_INITIAL_CAPACITY`


## Array/Queue.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Array/Queue.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `FLAT_QUEUE_TYPE(SUFFIX)`
- `FLAT_QUEUE_FUNC(SUFFIX, FUNC)`
- `FLAT_QUEUE_DECLARE(TYPE, SUFFIX)`
- `FLAT_QUEUE_INSTANCE_DECLARE(TYPE, NAME)`
- `TFlat_Queue(TYPE, NAME)`

```c
OPSTATUS FLAT_QUEUE_FUNC(SUFFIX, Init)( FLAT_QUEUE_TYPE(SUFFIX) * queue);

void FLAT_QUEUE_FUNC(SUFFIX, Destroy)(FLAT_QUEUE_TYPE(SUFFIX) * queue);

OPSTATUS FLAT_QUEUE_FUNC(SUFFIX, Reserve)( FLAT_QUEUE_TYPE(SUFFIX) * queue, size_t newCapacity);

OPSTATUS FLAT_QUEUE_FUNC(SUFFIX, ShrinkToFit)( FLAT_QUEUE_TYPE(SUFFIX) * queue);

OPSTATUS FLAT_QUEUE_FUNC(SUFFIX, Compact)( FLAT_QUEUE_TYPE(SUFFIX) * queue);

OPSTATUS FLAT_QUEUE_FUNC(SUFFIX, Push)( FLAT_QUEUE_TYPE(SUFFIX) * queue, TYPE value);

OPSTATUS FLAT_QUEUE_FUNC(SUFFIX, Pop)( FLAT_QUEUE_TYPE(SUFFIX) * queue, TYPE * outValue);

TYPE *FLAT_QUEUE_FUNC(SUFFIX, Front)(FLAT_QUEUE_TYPE(SUFFIX) * queue);

TYPE *FLAT_QUEUE_FUNC(SUFFIX, Back)(FLAT_QUEUE_TYPE(SUFFIX) * queue);

bool FLAT_QUEUE_FUNC(SUFFIX, Empty)(const FLAT_QUEUE_TYPE(SUFFIX) * queue);

size_t FLAT_QUEUE_FUNC(SUFFIX, Size)(const FLAT_QUEUE_TYPE(SUFFIX) * queue);

size_t FLAT_QUEUE_FUNC(SUFFIX, Capacity)( const FLAT_QUEUE_TYPE(SUFFIX) * queue);

```

## Array/Stack.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Array/Stack.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `FLAT_STACK_TYPE(SUFFIX)`
- `FLAT_STACK_FUNC(SUFFIX, FUNC)`
- `FLAT_STACK_DECLARE(TYPE, SUFFIX)`
- `FLAT_STACK_INSTANCE_DECLARE(TYPE, NAME)`
- `TFlat_Stack(TYPE, NAME)`

```c
OPSTATUS FLAT_STACK_FUNC(SUFFIX, Init)( FLAT_STACK_TYPE(SUFFIX) * stack);

void FLAT_STACK_FUNC(SUFFIX, Destroy)(FLAT_STACK_TYPE(SUFFIX) * stack);

OPSTATUS FLAT_STACK_FUNC(SUFFIX, Reserve)( FLAT_STACK_TYPE(SUFFIX) * stack, size_t newCapacity);

OPSTATUS FLAT_STACK_FUNC(SUFFIX, ShrinkToFit)( FLAT_STACK_TYPE(SUFFIX) * stack);

OPSTATUS FLAT_STACK_FUNC(SUFFIX, Push)( FLAT_STACK_TYPE(SUFFIX) * stack, TYPE value);

OPSTATUS FLAT_STACK_FUNC(SUFFIX, Pop)( FLAT_STACK_TYPE(SUFFIX) * stack, TYPE * outValue);

TYPE *FLAT_STACK_FUNC(SUFFIX, Top)(FLAT_STACK_TYPE(SUFFIX) * stack);

bool FLAT_STACK_FUNC(SUFFIX, Empty)(const FLAT_STACK_TYPE(SUFFIX) * stack);

size_t FLAT_STACK_FUNC(SUFFIX, Size)(const FLAT_STACK_TYPE(SUFFIX) * stack);

size_t FLAT_STACK_FUNC(SUFFIX, Capacity)( const FLAT_STACK_TYPE(SUFFIX) * stack);

```

## Array/String.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Array/String.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TSTRING_TYPE(SUFFIX)`
- `TSTRING_FUNC(SUFFIX, FUNC)`
- `TSTRING_DECLARE(CHAR_TYPE, SUFFIX)`
- `TSTRING_INSTANCE_DECLARE(SUFFIX, NAME)`
- `TString(SUFFIX, NAME)`

```c
OPSTATUS TSTRING_FUNC(SUFFIX, Init)(TSTRING_TYPE(SUFFIX) * str);

void TSTRING_FUNC(SUFFIX, Destroy)(TSTRING_TYPE(SUFFIX) * str);

OPSTATUS TSTRING_FUNC(SUFFIX, FromCStr)( TSTRING_TYPE(SUFFIX) * str, const CHAR_TYPE *cstr);

const CHAR_TYPE *TSTRING_FUNC(SUFFIX, CStr)( TSTRING_TYPE(SUFFIX) * str);

size_t TSTRING_FUNC(SUFFIX, Length)(const TSTRING_TYPE(SUFFIX) *str);

bool TSTRING_FUNC(SUFFIX, Empty)(const TSTRING_TYPE(SUFFIX) *str);

void TSTRING_FUNC(SUFFIX, Clear)(TSTRING_TYPE(SUFFIX) * str);

OPSTATUS TSTRING_FUNC(SUFFIX, Reserve)( TSTRING_TYPE(SUFFIX) * str, size_t newCapacity);

OPSTATUS TSTRING_FUNC(SUFFIX, PushBack)( TSTRING_TYPE(SUFFIX) * str, CHAR_TYPE ch);

OPSTATUS TSTRING_FUNC(SUFFIX, PopBack)(TSTRING_TYPE(SUFFIX) * str, CHAR_TYPE *outValue);

size_t TSTRING_FUNC(SUFFIX, Capacity)(const TSTRING_TYPE(SUFFIX) *str);

OPSTATUS TSTRING_FUNC(SUFFIX, InsertChar)( TSTRING_TYPE(SUFFIX) * str, size_t pos, CHAR_TYPE
    ch);

CHAR_TYPE *TSTRING_FUNC(SUFFIX, At)( TSTRING_TYPE(SUFFIX) * str, size_t index);

CHAR_TYPE *TSTRING_FUNC(SUFFIX, Front)(TSTRING_TYPE(SUFFIX) * str);

CHAR_TYPE *TSTRING_FUNC(SUFFIX, Back)(TSTRING_TYPE(SUFFIX) * str);

OPSTATUS TSTRING_FUNC(SUFFIX, Append)( TSTRING_TYPE(SUFFIX) * str, const CHAR_TYPE *cstr);

OPSTATUS TSTRING_FUNC(SUFFIX, AppendStr)( TSTRING_TYPE(SUFFIX) * str, TSTRING_TYPE(SUFFIX) *
    other);

OPSTATUS TSTRING_FUNC(SUFFIX, Insert)( TSTRING_TYPE(SUFFIX) * str, size_t pos, const CHAR_TYPE
    *cstr);

OPSTATUS TSTRING_FUNC(SUFFIX, Erase)( TSTRING_TYPE(SUFFIX) * str, size_t pos, size_t count);

OPSTATUS TSTRING_FUNC(SUFFIX, Substr)( TSTRING_TYPE(SUFFIX) * str, size_t pos, size_t count,
    TSTRING_TYPE(SUFFIX) * out);

OPSTATUS TSTRING_FUNC(SUFFIX, Compare)( const TSTRING_TYPE(SUFFIX) *str, const
    TSTRING_TYPE(SUFFIX) *other, TComparisonResult *result);

OPSTATUS TSTRING_FUNC(SUFFIX, Find)( const TSTRING_TYPE(SUFFIX) *str, CHAR_TYPE ch, size_t
    start, size_t *index);

OPSTATUS TSTRING_FUNC(SUFFIX, FindStr)( const TSTRING_TYPE(SUFFIX) *str, const CHAR_TYPE
    *needle, size_t start, size_t *index);

CHAR_TYPE *TSTRING_FUNC(SUFFIX, Data)(TSTRING_TYPE(SUFFIX) * str);

```

## Array/Vector.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Array/Vector.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `FLAT_VECTOR_TYPE(SUFFIX)`
- `FLAT_VECTOR_FUNC(SUFFIX, FUNC)`
- `FLAT_VECTOR_DECLARE(TYPE, SUFFIX)`
- `TVECTOR_TYPE(SUFFIX)`
- `TVECTOR_FUNC(SUFFIX, FUNC)`
- `FLAT_VECTOR_INSTANCE_DECLARE(TYPE, NAME)`
- `TVector(TYPE, NAME)`

```c
OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, Init)( FLAT_VECTOR_TYPE(SUFFIX) * vec);

void FLAT_VECTOR_FUNC(SUFFIX, Destroy)(FLAT_VECTOR_TYPE(SUFFIX) * vec);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, Reserve)( FLAT_VECTOR_TYPE(SUFFIX) * vec, size_t newCapacity);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, ShrinkToFit)( FLAT_VECTOR_TYPE(SUFFIX) * vec);

TYPE *FLAT_VECTOR_FUNC(SUFFIX, At)( FLAT_VECTOR_TYPE(SUFFIX) * vec, size_t index);

TYPE *FLAT_VECTOR_FUNC(SUFFIX, Front)(FLAT_VECTOR_TYPE(SUFFIX) * vec);

TYPE *FLAT_VECTOR_FUNC(SUFFIX, Back)(FLAT_VECTOR_TYPE(SUFFIX) * vec);

TYPE *FLAT_VECTOR_FUNC(SUFFIX, Data)(FLAT_VECTOR_TYPE(SUFFIX) * vec);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, PushBack)( FLAT_VECTOR_TYPE(SUFFIX) * vec, TYPE value);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, PopBack)( FLAT_VECTOR_TYPE(SUFFIX) * vec, TYPE * outValue);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, Insert)( FLAT_VECTOR_TYPE(SUFFIX) * vec, size_t position, TYPE
    value);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, Erase)( FLAT_VECTOR_TYPE(SUFFIX) * vec, size_t position,
    size_t count);

void FLAT_VECTOR_FUNC(SUFFIX, Clear)(FLAT_VECTOR_TYPE(SUFFIX) * vec);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, PushFront)( FLAT_VECTOR_TYPE(SUFFIX) * vec, TYPE value);

OPSTATUS FLAT_VECTOR_FUNC(SUFFIX, PopFront)( FLAT_VECTOR_TYPE(SUFFIX) * vec, TYPE * outValue);

bool FLAT_VECTOR_FUNC(SUFFIX, Empty)(const FLAT_VECTOR_TYPE(SUFFIX) * vec);

size_t FLAT_VECTOR_FUNC(SUFFIX, Size)(const FLAT_VECTOR_TYPE(SUFFIX) * vec);

size_t FLAT_VECTOR_FUNC(SUFFIX, Capacity)( const FLAT_VECTOR_TYPE(SUFFIX) * vec);

```

## Container.space

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Container.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CONTAINER_ENABLE_PSEUDO_METHODS`
- `CONTAINER_API_FORWARD(API_TYPE)`
- `CONTAINER_API_FIELD(API_TYPE)`
- `CONTAINER_API_BIND(SELF, API)`
- `CONTAINER_API_INITIALIZER(API)`


## Graph/Graph.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Graph/Graph.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `GRAPH_VISITOR_TYPEDEF(VERTEX_SUFFIX, WEIGHT_SUFFIX)`
- `GRAPH_DEFINE(VERTEX_TYPE, VERTEX_SUFFIX, WEIGHT_TYPE, WEIGHT_SUFFIX)`
- `GRAPH_DECLARE(VERTEX_SUFFIX, WEIGHT_SUFFIX, NAME)`

```c
OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, Init)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph);

void GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, Destroy)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph);

void GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, Clear)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph);

OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, AddVertex)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, VERTEX_TYPE data, size_t *outIndex);

OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, AddEdge)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, size_t source, size_t destination, WEIGHT_TYPE weight);

OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, RemoveEdge)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, size_t source, size_t destination);

OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, RemoveVertex)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, size_t index);

bool GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, HasEdge)( const TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, size_t source, size_t destination);

WEIGHT_TYPE * GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, FindWeight)(
    TGRAPH_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX) * graph, size_t source, size_t destination);

WEIGHT_TYPE const * GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, ConstFindWeight)( const
    TGRAPH_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX) * graph, size_t source, size_t destination);

size_t GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, VertexCount)( const
    TGRAPH_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX) * graph);

size_t GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, EdgeCount)( const
    TGRAPH_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX) * graph);

bool GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, IsEmpty)( const TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph);

OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, BFS)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, size_t start, TGRAPH_VISITOR_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX)
    visitor, void *context);

OPSTATUS GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, DFS)( TGRAPH_TYPE(VERTEX_SUFFIX,
    WEIGHT_SUFFIX) * graph, size_t start, TGRAPH_VISITOR_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX)
    visitor, void *context);

```

## Graph/Graph.space

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Graph/Graph.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `GRAPH_NS(NAME)`
- `GRAPH_INITIAL_VERTEX_CAPACITY`
- `GRAPH_INITIAL_EDGE_CAPACITY`
- `GRAPH_SUFFIX(VERTEX_SUFFIX, WEIGHT_SUFFIX)`
- `TGRAPH_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX)`
- `TGRAPH_VERTEX_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX)`
- `TGRAPH_EDGE_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX)`
- `GRAPH_OPERATION(VERTEX_SUFFIX, WEIGHT_SUFFIX, FUNC)`
- `TGRAPH_VISITOR_TYPE(VERTEX_SUFFIX, WEIGHT_SUFFIX)`


## Hash/Hash.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Hash/Hash.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `HASH_MAP_DEFINE(KEY_TYPE, KEY_SUFFIX, VALUE_TYPE, VALUE_SUFFIX, HASH_FUNCTION, EQUAL_FUNCTION)`
- `HASH_MAP_DECLARE(KEY_SUFFIX, VALUE_SUFFIX, NAME)`

```c
OPSTATUS HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Init)( THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX) *
    hash);

void HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Destroy)( THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX) *
    hash);

OPSTATUS HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Rehash)( THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX)
    * hash, size_t newCapacity);

VALUE_TYPE * HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Find)( THASH_TYPE(KEY_SUFFIX,
    VALUE_SUFFIX) * hash, KEY_TYPE key);

VALUE_TYPE const * HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, ConstFind)( const
    THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX) * hash, KEY_TYPE key);

bool HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Contains)( const THASH_TYPE(KEY_SUFFIX,
    VALUE_SUFFIX) * hash, KEY_TYPE key);

OPSTATUS HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Insert)( THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX)
    * hash, KEY_TYPE key, VALUE_TYPE value);

OPSTATUS HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Remove)( THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX)
    * hash, KEY_TYPE key);

void HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Clear)( THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX) *
    hash);

bool HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, IsEmpty)( const THASH_TYPE(KEY_SUFFIX,
    VALUE_SUFFIX) * hash);

size_t HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Size)( const THASH_TYPE(KEY_SUFFIX,
    VALUE_SUFFIX) * hash);

size_t HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, Capacity)( const THASH_TYPE(KEY_SUFFIX,
    VALUE_SUFFIX) * hash);

```

## Hash/Hash.space

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Hash/Hash.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `HASH_NS(NAME)`
- `HASH_INITIAL_CAPACITY`
- `HASH_LOAD_PERCENT`
- `HASH_BUCKET_EMPTY`
- `HASH_BUCKET_OCCUPIED`
- `HASH_BUCKET_DELETED`
- `HASH_SUFFIX(KEY_SUFFIX, VALUE_SUFFIX)`
- `THASH_TYPE(KEY_SUFFIX, VALUE_SUFFIX)`
- `THASH_BUCKET_TYPE(KEY_SUFFIX, VALUE_SUFFIX)`
- `HASH_FUNC(KEY_SUFFIX, VALUE_SUFFIX, FUNC)`
- `HASH_OPERATION(KEY_SUFFIX, VALUE_SUFFIX, FUNC)`
- `HASH_INT(VALUE)`
- `HASH_CSTRING(VALUE)`
- `HASH_EQUAL_INT(A, B)`
- `HASH_EQUAL_CSTRING(A, B)`

```c
size_t Hash_CString(const char *value);

```

## Linked/Deque.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/Deque.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_DEQUE_TYPE(SUFFIX)`
- `LINKED_DEQUE_FUNC(SUFFIX, FUNC)`
- `LINKED_DEQUE_NODE_TYPE(SUFFIX)`
- `LINKED_DEQUE_DECLARE(TYPE, SUFFIX)`
- `LINKED_DEQUE_INSTANCE_DECLARE(TYPE, NAME)`
- `TLinked_Deque(TYPE, NAME)`

```c
OPSTATUS LINKED_DEQUE_FUNC(SUFFIX, Init)( LINKED_DEQUE_TYPE(SUFFIX) * deque);

void LINKED_DEQUE_FUNC(SUFFIX, Destroy)( LINKED_DEQUE_TYPE(SUFFIX) * deque);

OPSTATUS LINKED_DEQUE_FUNC(SUFFIX, PushFront)( LINKED_DEQUE_TYPE(SUFFIX) * deque, TYPE value);

OPSTATUS LINKED_DEQUE_FUNC(SUFFIX, PushBack)( LINKED_DEQUE_TYPE(SUFFIX) * deque, TYPE value);

OPSTATUS LINKED_DEQUE_FUNC(SUFFIX, PopFront)( LINKED_DEQUE_TYPE(SUFFIX) * deque, TYPE *
    outValue);

OPSTATUS LINKED_DEQUE_FUNC(SUFFIX, PopBack)( LINKED_DEQUE_TYPE(SUFFIX) * deque, TYPE *
    outValue);

void LINKED_DEQUE_FUNC(SUFFIX, Clear)( LINKED_DEQUE_TYPE(SUFFIX) * deque);

TYPE *LINKED_DEQUE_FUNC(SUFFIX, Front)( LINKED_DEQUE_TYPE(SUFFIX) * deque);

TYPE *LINKED_DEQUE_FUNC(SUFFIX, Back)( LINKED_DEQUE_TYPE(SUFFIX) * deque);

bool LINKED_DEQUE_FUNC(SUFFIX, Empty)( const LINKED_DEQUE_TYPE(SUFFIX) * deque);

size_t LINKED_DEQUE_FUNC(SUFFIX, Size)( const LINKED_DEQUE_TYPE(SUFFIX) * deque);

```

## Linked/Forward.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/Forward.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_FORWARD_LIST_TYPE(SUFFIX)`
- `LINKED_FORWARD_LIST_FUNC(SUFFIX, FUNC)`
- `LINKED_FORWARD_LIST_NODE_TYPE(SUFFIX)`
- `LINKED_FORWARD_LIST_DECLARE(TYPE, SUFFIX)`
- `LINKED_FORWARD_LIST_INSTANCE_DECLARE(TYPE, NAME)`
- `TLinked_ForwardList(TYPE, NAME)`

```c
OPSTATUS LINKED_FORWARD_LIST_FUNC(SUFFIX, Init)( LINKED_FORWARD_LIST_TYPE(SUFFIX) * container);

void LINKED_FORWARD_LIST_FUNC(SUFFIX, Destroy)( LINKED_FORWARD_LIST_TYPE(SUFFIX) * container);

OPSTATUS LINKED_FORWARD_LIST_FUNC(SUFFIX, PushFront)( LINKED_FORWARD_LIST_TYPE(SUFFIX) *
    container, TYPE value);

OPSTATUS LINKED_FORWARD_LIST_FUNC(SUFFIX, PopFront)( LINKED_FORWARD_LIST_TYPE(SUFFIX) *
    container, TYPE * outValue);

OPSTATUS LINKED_FORWARD_LIST_FUNC(SUFFIX, InsertAfter)( LINKED_FORWARD_LIST_TYPE(SUFFIX) *
    container, LINKED_FORWARD_LIST_NODE_TYPE(SUFFIX) * pos, TYPE value,
    LINKED_FORWARD_LIST_NODE_TYPE(SUFFIX) * *outNode);

OPSTATUS LINKED_FORWARD_LIST_FUNC(SUFFIX, EraseAfter)( LINKED_FORWARD_LIST_TYPE(SUFFIX) *
    container, LINKED_FORWARD_LIST_NODE_TYPE(SUFFIX) * pos);

void LINKED_FORWARD_LIST_FUNC(SUFFIX, Clear)( LINKED_FORWARD_LIST_TYPE(SUFFIX) * container);

TYPE *LINKED_FORWARD_LIST_FUNC(SUFFIX, Front)( LINKED_FORWARD_LIST_TYPE(SUFFIX) * container);

TYPE *LINKED_FORWARD_LIST_FUNC(SUFFIX, Back)( LINKED_FORWARD_LIST_TYPE(SUFFIX) * container);

LINKED_FORWARD_LIST_NODE_TYPE(SUFFIX) * LINKED_FORWARD_LIST_FUNC(SUFFIX, Begin)(
    LINKED_FORWARD_LIST_TYPE(SUFFIX) * container);

bool LINKED_FORWARD_LIST_FUNC(SUFFIX, Empty)( const LINKED_FORWARD_LIST_TYPE(SUFFIX) *
    container);

size_t LINKED_FORWARD_LIST_FUNC(SUFFIX, Size)( const LINKED_FORWARD_LIST_TYPE(SUFFIX) *
    container);

```

## Linked/Linked.space

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/Linked.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_NS(NAME)`


## Linked/List.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/List.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_LIST_TYPE(SUFFIX)`
- `LINKED_LIST_FUNC(SUFFIX, FUNC)`
- `LINKED_LIST_NODE_TYPE(SUFFIX)`
- `LINKED_LIST_DECLARE(TYPE, SUFFIX)`
- `LINKED_LIST_INSTANCE_DECLARE(TYPE, NAME)`
- `TLinked_List(TYPE, NAME)`

```c
OPSTATUS LINKED_LIST_FUNC(SUFFIX, Init)( LINKED_LIST_TYPE(SUFFIX) * list);

void LINKED_LIST_FUNC(SUFFIX, Destroy)( LINKED_LIST_TYPE(SUFFIX) * list);

TYPE *LINKED_LIST_FUNC(SUFFIX, Front)(LINKED_LIST_TYPE(SUFFIX) * list);

TYPE *LINKED_LIST_FUNC(SUFFIX, Back)(LINKED_LIST_TYPE(SUFFIX) * list);

LINKED_LIST_NODE_TYPE(SUFFIX) * LINKED_LIST_FUNC(SUFFIX, Begin)(LINKED_LIST_TYPE(SUFFIX) *
    list);

LINKED_LIST_NODE_TYPE(SUFFIX) * LINKED_LIST_FUNC(SUFFIX, End)(LINKED_LIST_TYPE(SUFFIX) * list);

OPSTATUS LINKED_LIST_FUNC(SUFFIX, PushFront)( LINKED_LIST_TYPE(SUFFIX) * list, TYPE value);

OPSTATUS LINKED_LIST_FUNC(SUFFIX, PushBack)( LINKED_LIST_TYPE(SUFFIX) * list, TYPE value);

OPSTATUS LINKED_LIST_FUNC(SUFFIX, PopFront)( LINKED_LIST_TYPE(SUFFIX) * list, TYPE * outValue);

OPSTATUS LINKED_LIST_FUNC(SUFFIX, PopBack)( LINKED_LIST_TYPE(SUFFIX) * list, TYPE * outValue);

OPSTATUS LINKED_LIST_FUNC(SUFFIX, Insert)( LINKED_LIST_TYPE(SUFFIX) * list,
    LINKED_LIST_NODE_TYPE(SUFFIX) * pos, TYPE value, LINKED_LIST_NODE_TYPE(SUFFIX) * *outNode);

OPSTATUS LINKED_LIST_FUNC(SUFFIX, Erase)( LINKED_LIST_TYPE(SUFFIX) * list,
    LINKED_LIST_NODE_TYPE(SUFFIX) * pos, LINKED_LIST_NODE_TYPE(SUFFIX) * *outNode);

void LINKED_LIST_FUNC(SUFFIX, Clear)(LINKED_LIST_TYPE(SUFFIX) * list);

bool LINKED_LIST_FUNC(SUFFIX, Empty)(const LINKED_LIST_TYPE(SUFFIX) * list);

size_t LINKED_LIST_FUNC(SUFFIX, Size)(const LINKED_LIST_TYPE(SUFFIX) * list);

```

## Linked/Node.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/Node.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_NODE_TYPE(CONTAINER, SUFFIX)`
- `LINKED_NODE_VALUE_FIELD(TYPE)`
- `SINGLE_LINKED_NODE_TYPE(SUFFIX, CONTAINER)`
- `DOUBLE_LINKED_NODE_TYPE(SUFFIX, CONTAINER)`


## Linked/Queue.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/Queue.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_QUEUE_TYPE(SUFFIX)`
- `LINKED_QUEUE_FUNC(SUFFIX, FUNC)`
- `LINKED_QUEUE_NODE_TYPE(SUFFIX)`
- `LINKED_QUEUE_DECLARE(TYPE, SUFFIX)`
- `LINKED_QUEUE_INSTANCE_DECLARE(TYPE, NAME)`
- `TLinked_Queue(TYPE, NAME)`

```c
OPSTATUS LINKED_QUEUE_FUNC(SUFFIX, Init)( LINKED_QUEUE_TYPE(SUFFIX) * queue);

void LINKED_QUEUE_FUNC(SUFFIX, Destroy)( LINKED_QUEUE_TYPE(SUFFIX) * queue);

OPSTATUS LINKED_QUEUE_FUNC(SUFFIX, Push)( LINKED_QUEUE_TYPE(SUFFIX) * queue, TYPE value);

OPSTATUS LINKED_QUEUE_FUNC(SUFFIX, Pop)( LINKED_QUEUE_TYPE(SUFFIX) * queue, TYPE * outValue);

void LINKED_QUEUE_FUNC(SUFFIX, Clear)( LINKED_QUEUE_TYPE(SUFFIX) * queue);

TYPE *LINKED_QUEUE_FUNC(SUFFIX, Front)( LINKED_QUEUE_TYPE(SUFFIX) * queue);

TYPE *LINKED_QUEUE_FUNC(SUFFIX, Back)( LINKED_QUEUE_TYPE(SUFFIX) * queue);

bool LINKED_QUEUE_FUNC(SUFFIX, Empty)( const LINKED_QUEUE_TYPE(SUFFIX) * queue);

size_t LINKED_QUEUE_FUNC(SUFFIX, Size)( const LINKED_QUEUE_TYPE(SUFFIX) * queue);

```

## Linked/Stack.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Linked/Stack.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `LINKED_STACK_TYPE(SUFFIX)`
- `LINKED_STACK_FUNC(SUFFIX, FUNC)`
- `LINKED_STACK_NODE_TYPE(SUFFIX)`
- `LINKED_STACK_DECLARE(TYPE, SUFFIX)`
- `LINKED_STACK_INSTANCE_DECLARE(TYPE, NAME)`
- `TLinked_Stack(TYPE, NAME)`

```c
OPSTATUS LINKED_STACK_FUNC(SUFFIX, Init)( LINKED_STACK_TYPE(SUFFIX) * stack);

void LINKED_STACK_FUNC(SUFFIX, Destroy)( LINKED_STACK_TYPE(SUFFIX) * stack);

OPSTATUS LINKED_STACK_FUNC(SUFFIX, Push)( LINKED_STACK_TYPE(SUFFIX) * stack, TYPE value);

OPSTATUS LINKED_STACK_FUNC(SUFFIX, Pop)( LINKED_STACK_TYPE(SUFFIX) * stack, TYPE * outValue);

void LINKED_STACK_FUNC(SUFFIX, Clear)( LINKED_STACK_TYPE(SUFFIX) * stack);

TYPE *LINKED_STACK_FUNC(SUFFIX, Top)( LINKED_STACK_TYPE(SUFFIX) * stack);

bool LINKED_STACK_FUNC(SUFFIX, Empty)( const LINKED_STACK_TYPE(SUFFIX) * stack);

size_t LINKED_STACK_FUNC(SUFFIX, Size)( const LINKED_STACK_TYPE(SUFFIX) * stack);

```

## Tree/AVL.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/AVL.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TREE_AVL_SET_DEFINE(KEY_TYPE)`
- `TREE_AVL_SET_DEFINE_CMP(SUFFIX, KEY_TYPE, CMP)`
- `TREE_AVL_MAP_DEFINE(KEY_TYPE, VALUE_TYPE)`
- `TREE_AVL_MAP_DEFINE_CMP(SUFFIX_K, KEY_TYPE, VALUE_TYPE, CMP)`
- `TREE_AVL_SET_INSTANCE_DECLARE(KEY, NAME)`
- `TTree_AVL_Set(KEY, NAME)`
- `TREE_AVL_MAP_INSTANCE_DECLARE(KEY, VAL, NAME)`
- `TTree_AVL_Map(KEY, VAL, NAME)`


## Tree/BST.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/BST.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TREE_BST_SET_DEFINE(KEY_TYPE)`
- `TREE_BST_SET_DEFINE_CMP(SUFFIX, KEY_TYPE, CMP)`
- `TREE_BST_MAP_DEFINE(KEY_TYPE, VALUE_TYPE)`
- `TREE_BST_MAP_DEFINE_CMP(SUFFIX_K, KEY_TYPE, VALUE_TYPE, CMP)`
- `TREE_BST_SET_INSTANCE_DECLARE(KEY, NAME)`
- `TTree_BST_Set(KEY, NAME)`
- `TREE_BST_MAP_INSTANCE_DECLARE(KEY, VAL, NAME)`
- `TTree_BST_Map(KEY, VAL, NAME)`


## Tree/RedBlack.h

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/RedBlack.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TREE_RB_SET_DEFINE(KEY_TYPE)`
- `TREE_RB_SET_DEFINE_CMP(SUFFIX, KEY_TYPE, CMP)`
- `TREE_RB_MAP_DEFINE(KEY_TYPE, VALUE_TYPE)`
- `TREE_RB_MAP_DEFINE_CMP(SUFFIX_K, KEY_TYPE, VALUE_TYPE, CMP)`
- `TREE_RB_SET_INSTANCE_DECLARE(KEY, NAME)`
- `TTree_RB_Set(KEY, NAME)`
- `TREE_RB_MAP_INSTANCE_DECLARE(KEY, VAL, NAME)`
- `TTree_RB_Map(KEY, VAL, NAME)`


## Tree/Tree.space

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/Tree.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TREE_NS`
- `TTREE_SET_TYPE(ALG, KEY)`
- `TTREE_MAP_TYPE(ALG, KEY, VAL)`
- `TTREE_PUBLIC_SET_TYPE(ALG, KEY)`
- `TTREE_PUBLIC_MAP_TYPE(ALG, KEY, VAL)`
- `TTREE_NODE(T)`
- `TTREE_FN(T, FUNC)`
- `TTREE_CMPOUT`
- `TREE_SET_DECLARE(ALG, KEY, NAME)`
- `TREE_MAP_DECLARE(ALG, KEY, VAL, NAME)`


## Array/Impl/String.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Array/Impl/String.impl)

```c
size_t TSTRING_FUNC(SUFFIX, StrLen)(const CHAR_TYPE *cstr);

```

## Tree/AVL.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/AVL.impl)

```c
OPSTATUS TTREE_FN(T, Remove)(T * tree, KEY_TYPE key);

OPSTATUS TTREE_FN(T, Insert)(T * tree, KEY_TYPE key);

OPSTATUS TTREE_FN(T, Insert)( T * tree, KEY_TYPE key, VALUE_TYPE value);

```

## Tree/Common/Iterators.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/Common/Iterators.impl)

```c
TTREE_NODE(T) * TTREE_FN(T, Begin)(T * tree);

TTREE_NODE(T) * TTREE_FN(T, End)(T * tree);

TTREE_NODE(T) * TTREE_FN(T, Next)(TTREE_NODE(T) * node);

TTREE_NODE(T) * TTREE_FN(T, Prev)(TTREE_NODE(T) * node);

const TTREE_NODE(T) *TTREE_FN(T, ConstBegin)(const T *tree);

const TTREE_NODE(T) *TTREE_FN(T, ConstEnd)(const T *tree);

const TTREE_NODE(T) *TTREE_FN(T, ConstNext)( const TTREE_NODE(T) *node);

const TTREE_NODE(T) *TTREE_FN(T, ConstPrev)( const TTREE_NODE(T) *node);

```

## Tree/Common/Lifecycle.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/Common/Lifecycle.impl)

```c
OPSTATUS TTREE_FN(T, Init)(T * tree);

void TTREE_FN(T, Destroy)(T * tree);

void TTREE_FN(T, Clear)(T * tree);

```

## Tree/Common/Observers.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Container/Tree/Common/Observers.impl)

```c
TTREE_NODE(T) * TTREE_FN(T, FindNode)(T * tree, KEY_TYPE key);

bool TTREE_FN(T, Contains)(const T *tree, KEY_TYPE key);

TTREE_NODE(T) * TTREE_FN(T, MinNode)(TTREE_NODE(T) * node);

TTREE_NODE(T) * TTREE_FN(T, MaxNode)(TTREE_NODE(T) * node);

KEY_TYPE *TTREE_FN(T, Min)(T * tree);

KEY_TYPE *TTREE_FN(T, Max)(T * tree);

bool TTREE_FN(T, Empty)(const T *tree);

size_t TTREE_FN(T, Size)(const T *tree);

KEY_TYPE *TTREE_FN(T, Find)(T * tree, KEY_TYPE key);

VALUE_TYPE *TTREE_FN(T, Find)(T * tree, KEY_TYPE key);

```
