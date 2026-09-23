# Congro;Library
[Changelog](../../Version.md)&nbsp;|&nbsp;[Por qué EUPL?](LICENSING(ES-LATAM).md)&nbsp;|&nbsp;[Código de Conducta](CODE_OF_CONDUCT(ES-LATAM).md)&nbsp;|&nbsp;[Créditos](AUTHORS(ES-LATAM).md)&nbsp;|&nbsp;[Português (Brasil)](../Portugues-Brasil/README(PT-BR).md)&nbsp;|&nbsp;[English](../../README.md)
<pre>

Una biblioteca para mentes curiosas que exploran más allá del camino esperado.

$ congro --about

Congro;Library
Una biblioteca modular y flexible para mentes curiosas.

Diseñada para ser:
    [✓] Educativa
    [✓] Legible
    [✓] Estandarizada
    [✓] Modular
    [✓] Flexible

Pensada para programadores de todos los niveles de experiencia.

> ¿Por qué Congro?
$ congro --why

Programar no debería sentirse como descifrar código antiguo.

Congro está diseñada alrededor de una idea simple:

    código legible
        +
    arquitectura modular
        +
    diseño educativo
        =
    software que vale la pena entender


Ya sea que estés experimentando, aprendiendo, creando prototipos o construyendo algo serio,
Congro busca mantener sus partes internas comprensibles sin sacrificar flexibilidad.

> Filosofía
$ congro --philosophy

┌──────────────────────────────────────────┐
│  > EDUCATIVA                             │
│  Aprendé del código, no alrededor de él. │
├──────────────────────────────────────────┤
│  > LEGIBLE                               │
│  Abstracciones claras. Intenciones claras.│
├──────────────────────────────────────────┤
│  > ESTANDARIZADA                         │
│  Interfaces y convenciones consistentes. │
├──────────────────────────────────────────┤
│  > MODULAR                               │
│  Piezas pequeñas. Sistemas componibles.  │
├──────────────────────────────────────────┤
│  > FLEXIBLE                              │
│  Adaptá Congro a tu experimento.         │
└──────────────────────────────────────────┘

> Contrato de compilación C11 / POSIX

En sistemas POSIX, los backends nativos de Congro usan interfaces controladas por macros
de prueba de características POSIX. En compilaciones C11 estrictas, definí
`_POSIX_C_SOURCE=200809L` en la línea de comandos del compilador
(por ejemplo, `-D_POSIX_C_SOURCE=200809L`). Debe estar definida antes de que se
procese el primer header del sistema; por eso Congro no intenta definirla desde
un header público. Esto hace que el orden de los includes sea determinista,
incluso en programas que incluyen headers de libc antes de Congro.

> Instalación
$ git clone https://github.com/samucaoo1/Congro-Library.git

O, cuando esté publicado:

$ brew install congro

$ yay(or paru) -S congro

> Prueba rápida

Congro_Experiment();

Salida:

[Congro] Inicializando experimento...
[Congro] Cargando módulos...
[Congro] Ejecutando...
[Congro] Listo.

> Arquitectura

Congro está construida alrededor de módulos independientes que se pueden combinar según
las necesidades de tu proyecto.

congro/
│
├── Core/          # Componentes fundamentales
├── Modules/       # Funcionalidad modular
├── Assets/        # Recursos
└── ...

El objetivo es que cada parte de la biblioteca se pueda entender por sí sola.

> Objetivos de diseño
[01] Mantené las abstracciones comprensibles.
[02] Preferí la composición antes que la complejidad innecesaria.
[03] Hacé que los módulos sean útiles de forma independiente.
[04] Mantené las APIs consistentes.
[05] Hacé que aprender sea parte del proceso de desarrollo.
[06] Permití experimentar sin pelearte con la biblioteca.

> Estado
$ congro --status

Estado del proyecto: EXPERIMENTAL

API:          ██░░░░░░░░ 20%
Estabilidad:  █████░░░░░ 50%
Docs:         ░░░░░░░░░░ 0%
Curiosidad:   ██████████ 100%

⚠️ Congro está actualmente en desarrollo activo. Las APIs pueden cambiar.

> Contribuir

¿Tenés un experimento?

¿Tenés una idea rara?

¿Encontraste algo que podría ser más claro?

$ git clone <repository>
$ git checkout -b experiment/my-idea
$ make your-changes
$ git commit -m "feat: my contribution"
$ git push

Las contribuciones, experimentos, mejoras y críticas constructivas son bienvenidas.

Al participar en el proyecto, aceptás seguir el [Código de Conducta](CODE_OF_CONDUCT(ES-LATAM).md).

> Créditos
Congro;Library fue creada por [Samuel (okarin)](https://github.com/samucaoo1). Consultá [AUTHORS(ES-LATAM).md](AUTHORS(ES-LATAM).md) para ver los créditos de autoría y contribución del proyecto.

> Licencia
Congro;Library está licenciada bajo la Licencia Pública de la Unión Europea, Versión 1.2 solamente (EUPL-1.2).

Consultá [Por qué EUPL?](LICENSING(ES-LATAM).md) para conocer la justificación de licenciamiento del proyecto.

> Mensaje final
$ congro --message

┌────────────────────────────────────────────┐
│                                            │
│   "Mantené la curiosidad. Rompé. Aprendé." │
│                                            │
│                 — Congro                   │
│                                            │
└────────────────────────────────────────────┘

Congro;Library — Una biblioteca para mentes curiosas que exploran más allá del camino esperado.
<pre>
