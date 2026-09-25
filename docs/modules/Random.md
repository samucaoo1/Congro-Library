# Random

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Random.md)

Inclua `Congro/Modules/Random/Random.h`. Para uma sequência reproduzível,
mantenha uma `TRandomSource`; para uma transformação determinística única,
use `RANDOM_FUNC(U64_FromSeed)`.

## Escolha da API

| Camada | API | Comportamento |
|---|---|---|
| Conveniência | `U64`, `U64_FromSeed`, `RangeU64`, `RangeI64`, `F64`, `Bool` | Valores diretos, sem objeto de estado do chamador. |
| Source | `Init`, `InitWithState`, `InitSystem`, `Reseed`, `NextU64`, `Destroy` | Estado persistente, engine e mixer opcional. |
| Engine | Lcg, Pcg, Romu, Sfc, Splitmix, WyRand, Xoroshiro, Xoshiro | Famílias de geradores, com `Seed`, `Next` e tabela de operações. |
| Distribution | `U64`, `I64`, `F64`, `Bool` | Consome uma fonte; intervalos inteiros inclusivos, real em `[0,1)`. |
| Mixer | Jenkins, Knuth, Murmur3, Splitmix64, Stafford, Wang, WyHash, Xorshift | Misturas determinísticas de um valor de 64 bits. |
| Entropy | `System`, `Address`, `Clock`, `Jitter`, `Thread`, `Time`, `Collect` | Entropia do SO ou amostras ambientais, conforme a função. |
| Entropy/Pool | `Pool_Init`, `Pool_Add`, `Pool_Finalize` | Acumula amostras em um pool fornecido pelo chamador. |
| Shuffle | `Vector`, `VectorFromSource` e macros `RANDOM_SHUFFLE_VECTOR*` | Embaralhamento de elementos de tamanho fixo. |

## Reprodutibilidade e segurança

`U64_FromSeed(42)` recria o estado e devolve o primeiro valor: repeti-lo com a
mesma seed repete o resultado, não avança uma sequência. Para avançar, inicialize
Source uma vez e chame `NextU64` ou Distribution repetidamente. Não há função
pública `Random_Seed` global nesta versão.

`U64` chama `Entropy_Collect`, que mistura endereços, relógios, jitter e outras
amostras locais. Não é um CSPRNG, e não há promessa de unicidade. `Entropy_System`
é uma chamada separada ao backend do SO e retorna `bool`; cheque o sucesso.
`InitSystem` pode falhar com `NOT_AVAILABLE`. Semear uma engine comum com
entropia do SO não transforma essa engine em gerador criptográfico.

## Memória e concorrência

`Source_Init` aloca estado; `Destroy` o libera. `InitWithState` recebe memória
emprestada: ela deve ter tamanho e alinhamento adequados à engine e permanecer
viva; `Destroy` não a libera. `Reseed` reinicia uma fonte existente. O helper
`SourceFromSeed`, incluído por Random.h, devolve fonte proprietária por valor;
para detectar falhas de alocação prefira `Source_Init` com seu `OPSTATUS`.

Uma Source é mutável e não contém sincronização própria. Use fontes separadas
por thread ou proteção externa. Uma tabela de engine descreve tamanho de
estado e funções; passar estado de outra engine é inválido.

## Shuffle

Passe número de elementos e `sizeof(elemento)`, não o tamanho total como count.
As macros inferem o tamanho de um elemento. O buffer precisa ser gravável e
conter pelo menos `count * elementSize` bytes. A operação rearranja os valores,
sem assumir propriedade de recursos apontados por eles. Verifique `OPSTATUS`.
Use `VectorFromSource` com seed conhecida para reproduzir uma permutação.

## Exemplo

<!-- example: Random.c -->

[Random.c](../examples/Random.c)

```c
#include <assert.h>
#include "Congro/Modules/Random/Random.h"

int main(void) {
  TRandomSource source = {0};
  int values[] = {1, 2, 3, 4};
  OPSTATUS status = RANDOM_SOURCE_FUNC(Init)(
      &source, &RANDOM_ENGINE_FUNC(Xoshiro, VTable), UINT64_C(42), NULL);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  uint64_t roll = RANDOM_DISTRIBUTION_FUNC(U64)(&source, 1, 6);
  assert(roll >= 1 && roll <= 6);
  status = RANDOM_SHUFFLE_VECTOR_FROM_SOURCE(values, 4, &source);
  RANDOM_SOURCE_FUNC(Destroy)(&source);
  if (status != STATUS_CONST(SUCCESS))
    return 2;
  assert(values[0] + values[1] + values[2] + values[3] == 10);
  return 0;
}
```

[Testes de engines, distribuições, fontes e shuffle](../../Codespace/Tests/Random).
