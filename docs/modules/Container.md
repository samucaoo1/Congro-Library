# Container

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Container.md)

Containers tipados são gerados por macros. Inclua o header da estrutura desejada;
não existe um header público agregador `Container.h`. Hash e Graph fazem parte
da árvore atual.

## Escolha da estrutura

| Pacote/header | Estrutura | Operações e uso |
|---|---|---|
| `Array/Vector.h` | Vetor contíguo | `Init`, `Destroy`, `Reserve`, `ShrinkToFit`, `At`, `Front`, `Back`, `Data`, `PushBack/Front`, `PopBack/Front`, `Insert`, `Erase`, `Clear`, `Empty`, `Size`, `Capacity`. |
| `Array/String.h` | String dinâmica | Buffer de caracteres com operações de string; consulte capacidade e terminação NUL na API. |
| `Array/Stack.h` | Pilha em array | Inserção/remoção LIFO. |
| `Array/Queue.h` | Fila em array | Inserção/remoção FIFO. |
| `Linked/Forward.h`, `Linked/List.h` | Listas simples e duplas | Nós, inserção, remoção e percurso. |
| `Linked/Stack.h`, `Queue.h`, `Deque.h` | Adaptadores encadeados | Pilha, fila e fila de duas pontas. |
| `Tree/BST.h`, `AVL.h`, `RedBlack.h` | Conjuntos e mapas ordenados | Busca, inserção, remoção e percurso; AVL e RedBlack mantêm balanceamento. |
| `Hash/Hash.h` | Mapa hash | Endereçamento aberto com sondagem linear, tombstones e rehash. |
| `Graph/Graph.h` | Grafo dirigido ponderado | Vértices por índice, listas de adjacência, BFS e DFS. |
| `Aliases/Commons.h`, `Linear.h`, `Tree.h` | Conveniências | Aliases de tipos e operações existentes. |

Vetor favorece acesso por índice e armazenamento contíguo; inserir na frente ou
no meio desloca elementos. Árvores ordenadas mantêm ordem por comparação; Hash
não oferece ordem de iteração. Uma BST sem balanceamento pode degenerar.

## Macros, tipos e configuração

`FLAT_VECTOR_DECLARE(TYPE, SUFFIX)` gera uma família, não uma variável.
`FLAT_VECTOR_TYPE(int)` seleciona o tipo e `FLAT_VECTOR_FUNC(int, PushBack)` a
função. `int`, `float` e `double` já têm vetores instanciados; não os declare
novamente. A macro `FLAT_VECTOR_INSTANCE_DECLARE` cria uma instância.

Outras famílias têm geradores próprios: `TREE_AVL_SET_DEFINE`,
`TREE_AVL_MAP_DEFINE` (e equivalentes BST/RB), `HASH_MAP_DEFINE` e `GRAPH_DEFINE`.
`TREE_SET_DECLARE(ALG, KEY, NAME)` e `TREE_MAP_DECLARE(ALG, KEY, VAL, NAME)`
criam variáveis de famílias já geradas. Consulte as assinaturas e os testes para
escolher sufixos, comparadores e funções de hash. Coloque suas instanciações em
um header protegido e use sufixos únicos.

`CONTAINER_ENABLE_PSEUDO_METHODS` vale 1 por padrão. Defina 0 antes de qualquer
header Container para remover o campo `api`; as funções diretas permanecem.
Para usar pseudo-métodos com uma variável criada manualmente, associe a tabela
com `CONTAINER_API_BIND`. Não presuma que todo `Init` faça essa associação.
Mantenha a configuração consistente entre unidades de tradução.

## Propriedade e invalidação

Os containers liberam seus buffers/nós, mas não destroem recursos apontados por
cada elemento. Valores são copiados como valores C; uma chave `char *` não é
uma cópia profunda da string. Não copie um container proprietário por atribuição
para depois destruir as duas cópias.

Crescimento, rehash, remoção e compactação podem invalidar ponteiros obtidos
pela API. Adquira novamente o ponteiro após uma modificação. Cheque `OPSTATUS`
nas operações que alocam; acesso por ponteiro pode retornar `NULL`. Não existe
uma garantia geral de acesso concorrente: sincronize externamente.

## Strings, filas, pilhas e listas

String expõe `FromCStr`, `CStr`, `Length`, `Capacity`, `Reserve`, `Append`,
`AppendStr`, `Insert`, `InsertChar`, `Erase`, `Substr`, `Compare`, `Find` e
`FindStr`, além das operações de ciclo de vida e acesso. A capacidade é uma
propriedade do buffer; Length descreve o conteúdo. Não mantenha o ponteiro de
`CStr` através de operações que possam realocar. Strings char16/char32 continuam
sequências de unidades: não executam automaticamente normalização Unicode.

Stack usa `Push`, `Pop` e `Top`; Queue usa `Push`, `Pop`, `Front` e `Back`.
As variantes em array oferecem `Reserve` e `ShrinkToFit`; Queue também tem
`Compact`. Operações Pop recebem saída para o valor conforme a assinatura.

Listas usam ponteiros de nó, não índices de vetor. Respeite o container ao qual
o nó pertence em `InsertAfter` (Forward), `Insert` (List) e remoção; não retenha nó removido.
Forward oferece `EraseAfter`; List oferece `Erase` com saída do próximo nó.
Use `Begin` e os links de nó para percorrer; List também oferece `End`.
`Contains`, `Merge` e `Splice` não estão expostos pelos headers Linked desta
árvore: faça o percurso explicitamente quando precisar localizar um valor.

## Árvores

Selecione BST, AVL ou RB e depois Set ou Map. `TTREE_SET_TYPE` e
`TTREE_MAP_TYPE` selecionam o tipo gerado; `TTREE_FN(T, Operation)` seleciona
suas operações. Map recebe chave e valor; Set armazena somente a chave.
As instâncias padrão estão ao final de cada header de algoritmo.

As famílias oferecem `Init`, `Destroy`, `Clear`, `Insert`, `Remove`, `Find`,
`FindNode`, `Contains`, `Min`, `Max`, `MinNode`, `MaxNode`, `Empty`, `Size`,
`Begin`, `End`, `Next`, `Prev` e variantes de percurso `Const*`. Não altere uma
chave armazenada pelo ponteiro retornado: isso quebra a ordenação. Comparadores
customizados devem produzir uma ordenação consistente. As variantes
`*_DEFINE_CMP` permitem fornecê-los sem mudar o tipo armazenado.

## Hash

`HASH_MAP_DEFINE(KEY_TYPE, KEY_SUFFIX, VALUE_TYPE, VALUE_SUFFIX, HASH, EQUAL)`
recebe chave antes do valor. Estão disponíveis `int → int`, `int → ptr`, `cstring → int` e
`cstring → ptr`. `HASH_INT`, `HASH_CSTRING`, `HASH_EQUAL_INT` e
`HASH_EQUAL_CSTRING` são auxiliares prontos.

`Init` cria a capacidade inicial. `Insert` substitui o valor de uma chave
existente; `Find`/`ConstFind` retornam ponteiro ou `NULL`; `Contains` testa
presença; `Remove` retorna `NOT_FOUND` se a chave não existir. `Clear` esvazia
preservando capacidade; `Rehash` reorganiza buckets; `Size`, `Capacity` e
`IsEmpty` consultam o estado; `Destroy` libera o buffer.

Hash e igualdade devem concordar: chaves iguais precisam ter o mesmo hash.
Mantenha chaves string vivas e imutáveis enquanto estiverem no mapa. O hashing
fornecido é para estruturas de dados, sem garantia criptográfica.

## Graph

`GRAPH_DEFINE(VERTEX_TYPE, VERTEX_SUFFIX, WEIGHT_TYPE, WEIGHT_SUFFIX)` gera os
tipos e operações. Há instâncias `int/int` e `int/float`.

`AddVertex` retorna o índice por parâmetro de saída. `AddEdge(source, destination,
weight)` cria uma aresta dirigida ou atualiza seu peso. Para duas direções,
adicione duas arestas. `RemoveEdge` remove uma direção. `RemoveVertex` compacta
a lista e reajusta índices: índices anteriores deixam de ser identificadores
estáveis. `HasEdge`, `FindWeight`, `ConstFindWeight`, `VertexCount`, `EdgeCount`
e `IsEmpty` consultam o grafo.

`BFS` e `DFS` recebem vértice inicial, visitante e contexto. Percorrem a parte
alcançável; não calculam caminho mínimo ponderado. Não modifique a estrutura
do grafo dentro do visitante. `Clear` libera adjacências e preserva capacidade
do array de vértices; `Destroy` libera os recursos do grafo.

## Exemplos

<!-- example: Container.c -->

[Container.c](../examples/Container.c)

```c
#include <assert.h>
#include "Congro/Modules/Container/Array/Vector.h"

int main(void) {
  FLAT_VECTOR_TYPE(int) values = {0};
  OPSTATUS status = FLAT_VECTOR_FUNC(int, Init)(&values);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = FLAT_VECTOR_FUNC(int, PushBack)(&values, 42);
  if (status == STATUS_CONST(SUCCESS)) {
    int *first = FLAT_VECTOR_FUNC(int, At)(&values, 0);
    assert(first != NULL && *first == 42);
  }
  FLAT_VECTOR_FUNC(int, Destroy)(&values);
  return status == STATUS_CONST(SUCCESS) ? 0 : 2;
}
```

<!-- example: Hash.c -->

[Hash.c](../examples/Hash.c)

```c
#include <assert.h>
#include "Congro/Modules/Container/Hash/Hash.h"

int main(void) {
  THASH_TYPE(cstring, int) scores = {0};
  OPSTATUS status = HASH_OPERATION(cstring, int, Init)(&scores);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = HASH_OPERATION(cstring, int, Insert)(&scores, "okarin", 42);
  if (status == STATUS_CONST(SUCCESS)) {
    const int *score = HASH_OPERATION(cstring, int, ConstFind)(&scores, "okarin");
    assert(score != NULL && *score == 42);
  }
  HASH_OPERATION(cstring, int, Destroy)(&scores);
  return status == STATUS_CONST(SUCCESS) ? 0 : 2;
}
```

<!-- example: Graph.c -->

[Graph.c](../examples/Graph.c)

```c
#include <assert.h>
#include "Congro/Modules/Container/Graph/Graph.h"

int main(void) {
  TGRAPH_TYPE(int, int) graph = {0};
  size_t from = 0;
  size_t to = 0;
  OPSTATUS status = GRAPH_OPERATION(int, int, Init)(&graph);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = GRAPH_OPERATION(int, int, AddVertex)(&graph, 10, &from);
  if (status == STATUS_CONST(SUCCESS))
    status = GRAPH_OPERATION(int, int, AddVertex)(&graph, 20, &to);
  if (status == STATUS_CONST(SUCCESS))
    status = GRAPH_OPERATION(int, int, AddEdge)(&graph, from, to, 7);
  if (status == STATUS_CONST(SUCCESS)) {
    assert(GRAPH_OPERATION(int, int, HasEdge)(&graph, from, to));
    assert(!GRAPH_OPERATION(int, int, HasEdge)(&graph, to, from));
  }
  GRAPH_OPERATION(int, int, Destroy)(&graph);
  return status == STATUS_CONST(SUCCESS) ? 0 : 2;
}
```

[Testes de todas as famílias](../../Codespace/Tests/Container).
