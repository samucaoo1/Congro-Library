# Chronometry: referência de API

[Guia de uso](../modules/Chronometry.md) · [Índice](../INDEX.md)

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
| [Calendar/Calendar.h](../../Codespace/Congro/Modules/Chronometry/Calendar/Calendar.h) | 10 |
| [Chronometry.h](../../Codespace/Congro/Modules/Chronometry/Chronometry.h) | 0 |
| [Chronometry.space](../../Codespace/Congro/Modules/Chronometry/Chronometry.space) | 0 |
| [Clock/Clock.h](../../Codespace/Congro/Modules/Chronometry/Clock/Clock.h) | 2 |
| [DateTime/DateTime.h](../../Codespace/Congro/Modules/Chronometry/DateTime/DateTime.h) | 5 |
| [Duration/Duration.h](../../Codespace/Congro/Modules/Chronometry/Duration/Duration.h) | 6 |
| [Epoch/Epoch.h](../../Codespace/Congro/Modules/Chronometry/Epoch/Epoch.h) | 5 |
| [Format/Format.h](../../Codespace/Congro/Modules/Chronometry/Format/Format.h) | 4 |
| [Instant/Instant.h](../../Codespace/Congro/Modules/Chronometry/Instant/Instant.h) | 3 |
| [Timer/Timer.h](../../Codespace/Congro/Modules/Chronometry/Timer/Timer.h) | 9 |
| [Timezone/Timezone.h](../../Codespace/Congro/Modules/Chronometry/Timezone/Timezone.h) | 3 |

## Calendar/Calendar.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Calendar/Calendar.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CHRONOMETRY_CALENDAR_MONTH_TABLE(X)`
- `CHRONOMETRY_CALENDAR_REFORM_TABLE(X)`

```c
CALENDAR_FUNC(Policy);

OPSTATUS CALENDAR_FUNC(ReformPolicy)( CALENDAR_FUNC(ReformId) id, CALENDAR_FUNC(Policy)
    *policy);

int CALENDAR_FUNC(DateCompare)(CHRONOMETRY_TYPE(Date) left, CHRONOMETRY_TYPE(Date) right);

bool CALENDAR_FUNC(IsLeapYear)(CALENDAR_FUNC(System) system, int32_t year);

uint8_t CALENDAR_FUNC(DaysInMonth)(CALENDAR_FUNC(System) system, int32_t year, uint8_t month);

bool CALENDAR_FUNC(DateIsValid)( const CALENDAR_FUNC(Policy) *policy, CHRONOMETRY_TYPE(Date)
    date);

OPSTATUS CALENDAR_FUNC(DateToDayOfYear)( const CALENDAR_FUNC(Policy) *policy,
    CHRONOMETRY_TYPE(Date) date, uint16_t *dayOfYear);

OPSTATUS CALENDAR_FUNC(DateToOrdinal)( const CALENDAR_FUNC(Policy) *policy,
    CHRONOMETRY_TYPE(Date) date, int64_t *ordinal);

OPSTATUS CALENDAR_FUNC(DateFromOrdinal)( const CALENDAR_FUNC(Policy) *policy, int64_t ordinal,
    CHRONOMETRY_TYPE(Date) *date);

OPSTATUS CALENDAR_FUNC(DateDifference)( const CALENDAR_FUNC(Policy) *policy,
    CHRONOMETRY_TYPE(Date) left, CHRONOMETRY_TYPE(Date) right, int64_t *days);

```

## Chronometry.space

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Chronometry.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CHRONOMETRY_MOD(NAME)`
- `CHRONOMETRY_FUNC(MODULE, NAME)`
- `CHRONOMETRY_TYPE(NAME)`
- `CHRONOMETRY_CONST(SPACE, NAME)`
- `CALENDAR_CONST(NAME)`
- `DURATION_FUNC(NAME)`
- `CLOCK_FUNC(NAME)`
- `TIMER_FUNC(NAME)`
- `INSTANT_FUNC(NAME)`
- `CALENDAR_FUNC(NAME)`
- `DATETIME_FUNC(NAME)`
- `EPOCH_FUNC(NAME)`
- `TIMEZONE_FUNC(NAME)`
- `CHRONOMETRY_FORMAT_FUNC(NAME)`


## Clock/Clock.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Clock/Clock.h)

```c
OPSTATUS CLOCK_FUNC(Now)( CHRONOMETRY_TYPE(ClockTimePoint) *result);

OPSTATUS CLOCK_FUNC(DurationBetween)( CHRONOMETRY_TYPE(ClockTimePoint) start,
    CHRONOMETRY_TYPE(ClockTimePoint) end, CHRONOMETRY_TYPE(Duration) *result);

```

## DateTime/DateTime.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/DateTime/DateTime.h)

```c
bool DATETIME_FUNC(TimeIsValid)(CHRONOMETRY_TYPE(TimeOfDay) time);

bool DATETIME_FUNC(IsValid)( const CALENDAR_FUNC(Policy) *policy, CHRONOMETRY_TYPE(DateTime)
    value);

int DATETIME_FUNC(Compare)(CHRONOMETRY_TYPE(DateTime) left, CHRONOMETRY_TYPE(DateTime) right);

OPSTATUS DATETIME_FUNC(AddDuration)( const CALENDAR_FUNC(Policy) *policy,
    CHRONOMETRY_TYPE(DateTime) value, CHRONOMETRY_TYPE(Duration) duration,
    CHRONOMETRY_TYPE(DateTime) *result);

OPSTATUS DATETIME_FUNC(Difference)( const CALENDAR_FUNC(Policy) *policy,
    CHRONOMETRY_TYPE(DateTime) left, CHRONOMETRY_TYPE(DateTime) right,
    CHRONOMETRY_TYPE(Duration) *result);

```

## Duration/Duration.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Duration/Duration.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CHRONOMETRY_NANOSECONDS_PER_MICROSECOND`
- `CHRONOMETRY_NANOSECONDS_PER_MILLISECOND`
- `CHRONOMETRY_NANOSECONDS_PER_SECOND`
- `CHRONOMETRY_SECONDS_PER_MINUTE`
- `CHRONOMETRY_MINUTES_PER_HOUR`
- `CHRONOMETRY_HOURS_PER_DAY`

```c
CHRONOMETRY_TYPE(Duration) DURATION_FUNC(FromNanoseconds)( int64_t nanoseconds);

OPSTATUS DURATION_FUNC(FromSeconds)( int64_t seconds, CHRONOMETRY_TYPE(Duration) *result);

OPSTATUS DURATION_FUNC(Add)(CHRONOMETRY_TYPE(Duration) left, CHRONOMETRY_TYPE(Duration) right,
    CHRONOMETRY_TYPE(Duration) *result);

OPSTATUS DURATION_FUNC(Subtract)( CHRONOMETRY_TYPE(Duration) left, CHRONOMETRY_TYPE(Duration)
    right, CHRONOMETRY_TYPE(Duration) *result);

int DURATION_FUNC(Compare)(CHRONOMETRY_TYPE(Duration) left, CHRONOMETRY_TYPE(Duration) right);

OPSTATUS DURATION_FUNC(Absolute)( CHRONOMETRY_TYPE(Duration) value, CHRONOMETRY_TYPE(Duration)
    *result);

```

## Epoch/Epoch.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Epoch/Epoch.h)

```c
OPSTATUS EPOCH_FUNC(DateToJulianDayNumber)( const CALENDAR_FUNC(Policy) *policy,
    CHRONOMETRY_TYPE(Date) date, int64_t *julianDayNumber);

OPSTATUS EPOCH_FUNC(DateFromJulianDayNumber)( const CALENDAR_FUNC(Policy) *policy, int64_t
    julianDayNumber, CHRONOMETRY_TYPE(Date) *date);

OPSTATUS EPOCH_FUNC(DateToRataDie)( CHRONOMETRY_TYPE(Date) date, int64_t *rataDie);

OPSTATUS EPOCH_FUNC(DateTimeToUnix)( CHRONOMETRY_TYPE(DateTime) value, CHRONOMETRY_TYPE(Instant)
    *instant);

OPSTATUS EPOCH_FUNC(DateTimeFromUnix)( CHRONOMETRY_TYPE(Instant) instant,
    CHRONOMETRY_TYPE(DateTime) *value);

```

## Format/Format.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Format/Format.h)

```c
OPSTATUS CHRONOMETRY_FORMAT_FUNC(DateISO)( CHRONOMETRY_TYPE(Date) date, char *buffer, size_t
    capacity);

OPSTATUS CHRONOMETRY_FORMAT_FUNC(DateTimeISO)( CHRONOMETRY_TYPE(DateTime) value, char *buffer,
    size_t capacity);

OPSTATUS CHRONOMETRY_FORMAT_FUNC(ParseDateISO)( const char *text, CHRONOMETRY_TYPE(Date) *date);

OPSTATUS CHRONOMETRY_FORMAT_FUNC(ParseDateTimeISO)( const char *text, CHRONOMETRY_TYPE(DateTime)
    *value);

```

## Instant/Instant.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Instant/Instant.h)

```c
int INSTANT_FUNC(Compare)(CHRONOMETRY_TYPE(Instant) left, CHRONOMETRY_TYPE(Instant) right);

OPSTATUS INSTANT_FUNC(AddDuration)( CHRONOMETRY_TYPE(Instant) instant,
    CHRONOMETRY_TYPE(Duration) duration, CHRONOMETRY_TYPE(Instant) *result);

OPSTATUS INSTANT_FUNC(DurationBetween)( CHRONOMETRY_TYPE(Instant) start,
    CHRONOMETRY_TYPE(Instant) end, CHRONOMETRY_TYPE(Duration) *result);

```

## Timer/Timer.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Timer/Timer.h)

```c
OPSTATUS TIMER_FUNC(Start)(CHRONOMETRY_TYPE(Timer) *timer);

OPSTATUS TIMER_FUNC(Elapsed)( const CHRONOMETRY_TYPE(Timer) *timer, CHRONOMETRY_TYPE(Duration)
    *elapsed);

OPSTATUS TIMER_FUNC(Restart)( CHRONOMETRY_TYPE(Timer) *timer, CHRONOMETRY_TYPE(Duration)
    *elapsed);

OPSTATUS TIMER_FUNC(DeltaStart)(CHRONOMETRY_TYPE(Delta) *delta);

OPSTATUS TIMER_FUNC(DeltaUpdate)( CHRONOMETRY_TYPE(Delta) *delta, CHRONOMETRY_TYPE(Duration)
    *elapsed);

OPSTATUS TIMER_FUNC(FrameLimiterCreate)( CHRONOMETRY_TYPE(Duration) target,
    CHRONOMETRY_TYPE(FrameLimiter) *limiter);

OPSTATUS TIMER_FUNC(FrameLimiterFromFPS)( uint32_t fps, CHRONOMETRY_TYPE(FrameLimiter)
    *limiter);

OPSTATUS TIMER_FUNC(FrameLimiterBegin)( CHRONOMETRY_TYPE(FrameLimiter) *limiter);

OPSTATUS TIMER_FUNC(FrameLimiterRemaining)( const CHRONOMETRY_TYPE(FrameLimiter) *limiter,
    CHRONOMETRY_TYPE(Duration) *remaining);

```

## Timezone/Timezone.h

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Timezone/Timezone.h)

```c
bool TIMEZONE_FUNC(OffsetIsValid)( CHRONOMETRY_TYPE(UtcOffset) offset);

OPSTATUS TIMEZONE_FUNC(ToUTC)( CHRONOMETRY_TYPE(OffsetDateTime) value, CHRONOMETRY_TYPE(Instant)
    *instant);

OPSTATUS TIMEZONE_FUNC(FromUTC)( CHRONOMETRY_TYPE(Instant) instant, CHRONOMETRY_TYPE(UtcOffset)
    offset, CHRONOMETRY_TYPE(OffsetDateTime) *value);

```

## Calendar/Impl/Calendar.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Chronometry/Calendar/Impl/Calendar.impl)

```c
CALENDAR_FUNC(System);

```
