# Congro;Library
[Changelog](../../Version.md)&nbsp;|&nbsp;[English](../../README.md)
<pre>

Uma biblioteca para mentes curiosas que exploram além do caminho esperado.

$ congro --about

Congro;Library
Uma biblioteca modular e flexível para mentes curiosas.

Projetada para ser:
    [✓] Educacional
    [✓] Legível
    [✓] Padronizada
    [✓] Modular
    [✓] Flexível

Feita para programadores de todos os níveis de experiência.

> Por que Congro?
$ congro --why

Programar não deveria parecer a tarefa de decifrar código antigo.

Congro é projetada em torno de uma ideia simples:

    código legível
        +
    arquitetura modular
        +
    design educacional
        =
    software que vale a pena entender


Seja experimentando, aprendendo, prototipando ou construindo algo sério,
Congro busca manter sua estrutura interna compreensível sem sacrificar flexibilidade.

> Filosofia
$ congro --philosophy

┌──────────────────────────────────────────┐
│  > EDUCACIONAL                           │
│  Aprenda com o código, não ao redor dele.│
├──────────────────────────────────────────┤
│  > LEGÍVEL                               │
│  Abstrações claras. Intenções claras.    │
├──────────────────────────────────────────┤
│  > PADRONIZADA                           │
│  Interfaces e convenções consistentes.   │
├──────────────────────────────────────────┤
│  > MODULAR                               │
│  Pequenas partes. Sistemas componíveis.  │
├──────────────────────────────────────────┤
│  > FLEXÍVEL                              │
│  Adapte Congro ao seu experimento.       │
└──────────────────────────────────────────┘

> Contrato de compilação C11 / POSIX

Em alvos POSIX, os backends nativos da Congro usam interfaces controladas por macros
de teste de recursos POSIX. Em compilações C11 estritas, defina
`_POSIX_C_SOURCE=200809L` na linha de comando do compilador
(por exemplo, `-D_POSIX_C_SOURCE=200809L`). Ela deve ser definida antes que o
primeiro cabeçalho do sistema seja processado; por isso, Congro não tenta defini-la
dentro de um cabeçalho público. Isso torna a ordem dos includes determinística,
inclusive em programas que incluem cabeçalhos da libc antes da Congro.

> Instalação
$ git clone https://github.com/samucaoo1/Congro-Library.git


Ou, quando publicado:

$ brew install congro

$ yay(or paru) -S congro

> Teste rápido

Congro_Experiment();

Saída:

[Congro] Inicializando experimento...
[Congro] Carregando módulos...
[Congro] Executando...
[Congro] Concluído.

> Arquitetura

Congro é construída em torno de módulos independentes que podem ser combinados de acordo
com as necessidades do seu projeto.

congro/
│
├── Core/          # Componentes fundamentais
├── Modules/       # Funcionalidades modulares
├── Assets/        # Recursos
└── ...


O objetivo é tornar cada parte da biblioteca compreensível por conta própria.

┌─────────────┐
│    Core     │
└──────┬──────┘
       │
       ├──────────────┐
       ▼              ▼
┌─────────────┐ ┌─────────────┐
│   Módulo A  │ │   Módulo B  │
└──────┬──────┘ └──────┬──────┘
       │               │
       └───────┬───────┘
               ▼
        ┌─────────────┐
        │ Experimento │
        └─────────────┘

> Objetivos de design
[01] Manter as abstrações compreensíveis.
[02] Preferir composição em vez de complexidade desnecessária.
[03] Tornar os módulos úteis de forma independente.
[04] Manter APIs consistentes.
[05] Fazer do aprendizado parte do processo de desenvolvimento.
[06] Permitir experimentação sem lutar contra a biblioteca.

> Status
$ congro --status

Status do projeto: EXPERIMENTAL

API:          ██░░░░░░░░ 20%
Estabilidade: █████░░░░░ 50%
Docs:         ░░░░░░░░░░ 0%
Curiosidade:  ██████████ 100%


⚠️ Congro está atualmente em desenvolvimento ativo. As APIs podem mudar.

> Contribuindo

Tem um experimento?

Tem uma ideia estranha?

Encontrou algo que poderia ser mais claro?

$ git clone <repository>
$ git checkout -b experiment/my-idea
$ make your-changes
$ git commit -m "feat: my contribution"
$ git push


Contribuições, experimentos, melhorias e críticas construtivas são bem-vindos.

> Licença
Congro;Library é licenciada sob a Licença Pública da União Europeia, versão 1.2 somente (EUPL-1.2).

> Mensagem final
$ congro --message

┌────────────────────────────────────────────┐
│                                            │
│   "Continue curioso. Quebre. Aprenda."     │
│                                            │
│                 — Congro                   │
│                                            │
└────────────────────────────────────────────┘


Congro;Library — Uma biblioteca para mentes curiosas que exploram além do caminho esperado.
<pre>
