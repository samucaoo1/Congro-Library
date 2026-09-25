# Congro;Library — documentação

Biblioteca modular C11, com arquitetura orientada a headers. Este índice reúne
guias de uso, referência de API e exemplos do código atual em `Codespace/Congro`.
Os guias estão em português brasileiro; os nomes da API preservam o código C.

## Comece aqui

- [Primeiros passos](GettingStarted.md): includes, compilação e primeiro programa.
- [Arquitetura](Architecture.md): organização, macros, namespace e ownership.
- [Core](Core.md): memória, comparação, status e pré-processador.
- [Testes e manutenção](Testing.md): validação local e documentos do projeto.
- [Exemplos completos](examples): programas pequenos, sem serviços externos.

## Um guia por módulo

| Módulo | Guia | Referência de API | Escopo |
|---|---|---|---|
| Core | [Core](Core.md) | [API](api/Core.md) | Algorithm, Cast, Error, Memory, Namespace, Preprocessor. |
| Bit | [Bit](modules/Bit.md) | [API](api/Bit.md) | Bits, máscaras, contagem, rotação e campos. |
| Chronometry | [Chronometry](modules/Chronometry.md) | [API](api/Chronometry.md) | Calendários, datas, durações, épocas, relógios, timers, formatos e offsets UTC. |
| Concurrency | [Concurrency](modules/Concurrency.md) | [API](api/Concurrency.md) | Atomics, threads, sleep, sincronização, coroutines, tasks, futures e pool. |
| Container | [Container](modules/Container.md) | [API](api/Container.md) | Vetores, strings, filas, pilhas, listas, árvores, Hash e Graph. |
| Math | [Math](modules/Math.md) | [API](api/Math.md) | Aritmética verificada, saturação, intervalos e equações. |
| Network | [Network](modules/Network.md) | [API](api/Network.md) | Endereços, DNS, sockets, conexões, listeners, datagramas e poller. |
| Random | [Random](modules/Random.md) | [API](api/Random.md) | Fontes, engines, entropia, mixers, distribuições e shuffle. |
| Struct | [Struct](modules/Struct.md) | [API](api/Struct.md) | TPair, TDual, TTriple, TQuad e TPenta. |
| Text | [Text](modules/Text.md) | [API](api/Text.md) | UTF-8, UTF-16, codepoints, largura e grids de caracteres/atributos. |
| Type | [Type](modules/Type.md) | [API](api/Type.md) | Aliases fundamentais, blocos de bits e números de largura fixa. |

Cada guia apresenta os pacotes, formas de inclusão/chamada, ciclo de vida,
erros, limitações e exemplos. A referência lista os headers e assinaturas
paramétricas; o arquivo vinculado contém enums, tipos, macros e condições de
compilação. Não confunda funcionalidades do [roadmap](../ROADMAP.md) com APIs
já implementadas.

## Fontes e projeto

- [Código](../Codespace/Congro) e [testes](../Codespace/Tests).
- [README](../README.md), [histórico](../Version.md) e [Entropy](../ENTROPY.md).
- [Licença](../LICENSE), [justificativa](../LICENSING.md), [segurança](../SECURITY.md),
  [conduta](../CODE_OF_CONDUCT.md) e [créditos](../AUTHORS.md).
- [Mapa para ferramentas e IA](../llms.txt) e [metadados de citação](../CITATION.cff).
- Repositório canônico: [samucaoo1/Congro-Library](https://github.com/samucaoo1/Congro-Library).

## Technical summary / search vocabulary

Congro;Library is an experimental modular C11, header-oriented / single-header-style
library for portable systems programming and education. Modules cover memory,
macro metaprogramming, generic containers, hash maps, directed graphs, atomics,
threads, coroutines, sockets, networking, calendars, timers, random generation,
Unicode, text grids, bit operations, arithmetic and fixed-width numeric types.
Implementation pages (`.impl`) are included by headers, not compiled separately.
Operational errors commonly use `OPSTATUS`; specific APIs have other documented
return conventions. License: EUPL-1.2-only. APIs remain under active development.
