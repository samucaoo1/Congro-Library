# Arquitetura e convenções de uso

[Índice](INDEX.md) · [Core](Core.md)

## Organização

| Local/arquivo | Papel |
|---|---|
| `Codespace/Congro/Core` | Namespace, pré-processador, memória, status e comparação. |
| `Codespace/Congro/Modules/<Module>` | APIs de cada domínio e seus pacotes. |
| `.h` | Ponto de inclusão público ou suporte explícito, como VTable. |
| `.space` | Composição de nomes, configuração e declarações compartilhadas. |
| `.impl` | Definições incluídas por headers ou macros geradoras. |
| `.inc` | Trechos auxiliares, tabelas ou backends incluídos. |
| `Codespace/Tests/<Module>` | Programas de teste e Makefile por módulo. |
| `docs/modules`, `docs/api`, `docs/examples` | Guias, referência e exemplos verificáveis. |

Não há um agregador universal obrigatório. Alguns módulos possuem um header
agregador; outros exigem escolher pacotes. IncludeAll.c é teste de inclusão,
não ponto de entrada público da biblioteca.

## Nomes e geração

As macros de seleção `*_TYPE`, `*_FUNC`, `*_CONST` e equivalentes de pacote
compõem identificadores; preserve-as em exemplos e extensões. Tipos e funções
usam nomes como `TVector` e `PushBack`; constantes e macros de configuração
seguem nomes em maiúsculas com underscores. Existem exceções históricas na API
atual; a referência reproduz o código existente, sem inventar renomes.

Macros `DECLARE` e `DEFINE` podem gerar tipos, funções estáticas e tabelas. Sua
semântica exata depende da família: uma macro de declaração de família não é
necessariamente uma declaração de variável. Não instancie duas vezes o mesmo
sufixo no mesmo escopo. Coloque customizações compartilhadas em um header com
proteção de inclusão.

## Configurações que precisam concordar

| Configuração | Efeito |
|---|---|
| `CONGRO_NAMESPACE` | Prefixo de nomes selecionados por `LIB_PREFIX`. |
| `CONGRO_NAMESPACE_CONST` | Prefixo separado para constantes. |
| `CONTAINER_ENABLE_PSEUDO_METHODS` | Inclui/remove campo e tabelas de pseudo-métodos Container. |
| `TYPE_ENABLE_VTABLE` | Inclui/remove pseudo-métodos Type. |
| `TYPE_ALIAS_SMALL` ou `TYPE_ALIAS_COMPLETE` | Forma dos aliases fundamentais. |
| `TYPE_ALIAS_SAFE` ou `TYPE_ALIAS_UNSAFE` | Namespace dos aliases fundamentais. |

Defina configurações antes de qualquer header da biblioteca e de forma
consistente entre unidades de tradução que compartilhem objetos. Remover o
campo `api` altera layout; funções diretas continuam disponíveis. A implementação
estática por header também significa que um estado estático interno pode existir
por unidade de tradução: não suponha um singleton global para todo o executável.

## Ownership e falhas

Um container, grid, source aleatória proprietária ou conexão pode possuir
memória/handles. Copiar a struct por atribuição não transfere nem duplica esses
recursos de forma segura. Use a operação de cópia apropriada quando existir;
caso contrário, controle uma única instância proprietária.

Parâmetros de saída separam resultado útil de `OPSTATUS`; examine o status
antes de usar a saída. O código não oferece uma garantia geral de rollback.
Constantes de erro pertencem ao domínio: Network e Text acrescentam detalhes
específicos. Não deduza thread-safety da palavra `static`, de um campo público
ou da existência de um wrapper.

## Limites atuais

O [roadmap](../ROADMAP.md) registra intenção futura, não disponibilidade atual.
Text Grid não renderiza terminal; Timezone não carrega IANA; Random comum não é
criptográfico; TDecimal não implementa frações decimais; Graph não oferece
caminhos mínimos ponderados. Os guias registram essas diferenças para evitar
exemplos baseados em funcionalidades ainda inexistentes.

O antigo índice apontava para `PATTERN.md` na raiz, mas esse arquivo não está
presente nesta árvore. Esta página descreve convenções observáveis no código;
não substitui nem reconstrói o documento externo de padrão do projeto.
