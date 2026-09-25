# Chronometry

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Chronometry.md)

Inclua `Congro/Modules/Chronometry/Chronometry.h` ou somente o header do pacote.
O módulo separa datas civis, durações, instantes de época e medição monotônica.

## Pacotes e unidades

| Pacote | Tipos e operações | Uso |
|---|---|---|
| Calendar | `Date`, `Policy`, `SystemPolicy`, `ReformPolicy`, `DateIsValid`, `IsLeapYear`, `DaysInMonth`, `DateCompare`, `DateToDayOfYear`, `DateToOrdinal`, `DateFromOrdinal`, `DateDifference` | Calendários gregoriano e juliano, puros ou com reforma histórica. |
| Duration | `Duration`, `FromNanoseconds`, `FromSeconds`, `Add`, `Subtract`, `Compare`, `Absolute` | Intervalo em nanosegundos num `int64_t`; operações verificadas retornam `OPSTATUS`. |
| DateTime | `TimeOfDay`, `DateTime`, `TimeIsValid`, `IsValid`, `Compare`, `AddDuration`, `Difference` | Data mais hora civil; campo fracionário em milissegundos. |
| Instant | `Instant`, `Compare`, `AddDuration`, `DurationBetween` | Segundos assinados e fração em nanosegundos; mantenha a fração normalizada. |
| Epoch | `DateToJulianDayNumber`, `DateFromJulianDayNumber`, `DateToRataDie`, `DateTimeToUnix`, `DateTimeFromUnix` | Conversões de época; Unix usa calendário gregoriano. |
| Clock | `ClockTimePoint`, `Now`, `DurationBetween` | Medição monotônica, sem significado de data civil. |
| Timer | `Timer`, `Delta`, `FrameLimiter` | Tempo decorrido, delta entre atualizações e orçamento de frame. |
| Timezone | `UtcOffset`, `OffsetDateTime`, `OffsetIsValid`, `ToUTC`, `FromUTC` | Deslocamento fixo em minutos a leste de UTC. |
| Format | `DateISO`, `DateTimeISO`, `ParseDateISO`, `ParseDateTimeISO` | Formatos ISO específicos implementados pela biblioteca; não é um parser ISO 8601 geral. |

Use `CHRONOMETRY_TYPE(Name)` para os tipos e as macros do pacote, como
`CALENDAR_FUNC(Name)`, `DURATION_FUNC(Name)` e `TIMER_FUNC(Name)`, para chamadas.

## Calendários históricos

`SystemPolicy(CALENDAR_CONST(GREGORIAN))` aplica o calendário gregoriano
prolepticamente. `ReformPolicy` aceita `CATHOLIC_1582`, `BRITISH_1752` e
`RUSSIAN_1918`: os dias suprimidos pela reforma não são datas válidas nessa
política. Escolha a política explicitamente antes de converter ou calcular
intervalos históricos. Ano, mês e dia são campos de bits: valide os valores
antes de atribuir dados externos, pois a atribuição pode truncá-los.

## Relógios, timers e frames

`TIMER_FUNC(Start)` inicializa um timer; `Elapsed` consulta o intervalo e
`Restart` consulta e reinicia. `DeltaStart` e `DeltaUpdate` acompanham intervalos
entre passos de uma aplicação.

Crie um limitador com `FrameLimiterFromFPS` ou `FrameLimiterCreate`, marque o
início com `FrameLimiterBegin` e consulte `FrameLimiterRemaining`. O limitador
calcula o tempo restante; quem chama decide esperar usando
`THREAD_FUNC(SleepFor)`, de [Concurrency](Concurrency.md). Não misture
`ClockTimePoint` com timestamps Unix e não suponha que uma espera tenha precisão
exata de nanosegundos.

## Fusos, formatos e erros

Timezone não carrega arquivos TZif nem regras IANA. O campo `daylightSavings`
não busca regras automaticamente. Para São Paulo com deslocamento de menos
três horas, o valor é `minutesEastOfUtc = -180`; a escolha do deslocamento para
cada data cabe ao chamador.

As funções de formatação recebem buffer e capacidade em bytes, incluindo espaço
para NUL. Verifique `OPSTATUS` antes de ler saídas; entradas inválidas, limites
de representação e buffers curtos são tratados conforme cada assinatura e
implementação. `DateTime` tem resolução de milissegundos, diferente de Duration.

## Exemplo

<!-- example: Chronometry.c -->

[Chronometry.c](../examples/Chronometry.c)

```c
#include <assert.h>
#include "Congro/Modules/Chronometry/Chronometry.h"

int main(void) {
  CALENDAR_FUNC(Policy) policy =
      CALENDAR_FUNC(SystemPolicy)(CALENDAR_CONST(GREGORIAN));
  CHRONOMETRY_TYPE(Date) date = {.year = 2024, .month = 2, .day = 29};
  uint16_t day = 0;
  OPSTATUS status = CALENDAR_FUNC(DateToDayOfYear)(&policy, date, &day);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  assert(day == 60);
  return 0;
}
```

[Testes de calendários, conversões e timers](../../Codespace/Tests/Chronometry).
