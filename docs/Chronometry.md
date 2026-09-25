# Chronometry

Chronometry is Congro's time domain: calendar systems, civil dates, durations,
monotonic clocks, instants, epochs, formatting, timers, frame limiting, and UTC
offset conversion.

**Root:** `Codespace/Congro/Modules/Chronometry`

Namespace helpers such as `CALENDAR_FUNC(Name)` expand to
`Chronometry_Calendar_Name`. The same rule applies to Duration, Clock, Timer,
Instant, DateTime, Epoch, Timezone, and Format.

## Calendar

**Header:** `Calendar/Calendar.h`

Important types include `Chronometry_Date`, calendar systems, reforms, and
calendar policies. Policies let conversions operate against a chosen calendar
or historical reform rather than assuming a single calendar globally.

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `CALENDAR_FUNC(SystemPolicy)(system)` | `Chronometry_Calendar_SystemPolicy(system)` | Builds a policy for a calendar system. |
| `CALENDAR_FUNC(ReformPolicy)(id,&policy)` | `Chronometry_Calendar_ReformPolicy(...)` | Gets a predefined historical reform policy. |
| `CALENDAR_FUNC(DateCompare)(a,b)` | `Chronometry_Calendar_DateCompare(a,b)` | Compares two dates. |
| `CALENDAR_FUNC(IsLeapYear)(system,year)` | `Chronometry_Calendar_IsLeapYear(...)` | Leap-year test. |
| `CALENDAR_FUNC(DaysInMonth)(system,year,month)` | `Chronometry_Calendar_DaysInMonth(...)` | Number of days in a month. |
| `CALENDAR_FUNC(DateIsValid)(&policy,date)` | `Chronometry_Calendar_DateIsValid(...)` | Validates a date under a policy. |
| `CALENDAR_FUNC(DateToDayOfYear)(&policy,date,&day)` | `Chronometry_Calendar_DateToDayOfYear(...)` | Converts to ordinal day within the year. |
| `CALENDAR_FUNC(DateToOrdinal)(&policy,date,&ordinal)` | `Chronometry_Calendar_DateToOrdinal(...)` | Converts to the library's day ordinal. |
| `CALENDAR_FUNC(DateFromOrdinal)(&policy,n,&date)` | `Chronometry_Calendar_DateFromOrdinal(...)` | Reconstructs a date from an ordinal. |
| `CALENDAR_FUNC(DateDifference)(&policy,a,b,&days)` | `Chronometry_Calendar_DateDifference(...)` | Signed difference in days. |

Example:

```c
Chronometry_Calendar_Policy policy =
    CALENDAR_FUNC(SystemPolicy)(CHRONOMETRY_CALENDAR_GREGORIAN);

Chronometry_Date date = {2026, 9, 25};
uint16_t dayOfYear = 0;

CALENDAR_FUNC(DateToDayOfYear)(&policy, date, &dayOfYear);
```

The direct call is
`Chronometry_Calendar_DateToDayOfYear(&policy, date, &dayOfYear)`.

## Duration

**Header:** `Duration/Duration.h`

| Indirect | Direct |
| --- | --- |
| `DURATION_FUNC(FromNanoseconds)(ns)` | `Chronometry_Duration_FromNanoseconds(ns)` |
| `DURATION_FUNC(FromSeconds)(seconds,&out)` | `Chronometry_Duration_FromSeconds(...)` |
| `DURATION_FUNC(Add)(a,b,&out)` | `Chronometry_Duration_Add(...)` |
| `DURATION_FUNC(Subtract)(a,b,&out)` | `Chronometry_Duration_Subtract(...)` |
| `DURATION_FUNC(Compare)(a,b)` | `Chronometry_Duration_Compare(a,b)` |
| `DURATION_FUNC(Absolute)(value,&out)` | `Chronometry_Duration_Absolute(...)` |

Example:

```c
Chronometry_Duration second;
DURATION_FUNC(FromSeconds)(1, &second);
```

Direct: `Chronometry_Duration_FromSeconds(1, &second)`.

## Clock

**Header:** `Clock/Clock.h`

`Chronometry_ClockTimePoint` represents a clock reading intended for elapsed
time measurement.

| Indirect | Direct |
| --- | --- |
| `CLOCK_FUNC(Now)(&point)` | `Chronometry_Clock_Now(&point)` |
| `CLOCK_FUNC(DurationBetween)(start,end,&duration)` | `Chronometry_Clock_DurationBetween(...)` |

Use Clock for measuring time passage rather than interpreting civil dates.

## DateTime

**Header:** `DateTime/DateTime.h`

Types: `Chronometry_TimeOfDay` and `Chronometry_DateTime`.

| Indirect | Direct |
| --- | --- |
| `DATETIME_FUNC(TimeIsValid)(time)` | `Chronometry_DateTime_TimeIsValid(time)` |
| `DATETIME_FUNC(IsValid)(&policy,value)` | `Chronometry_DateTime_IsValid(...)` |
| `DATETIME_FUNC(Compare)(a,b)` | `Chronometry_DateTime_Compare(a,b)` |
| `DATETIME_FUNC(AddDuration)(&policy,value,duration,&out)` | `Chronometry_DateTime_AddDuration(...)` |
| `DATETIME_FUNC(Difference)(&policy,a,b,&out)` | `Chronometry_DateTime_Difference(...)` |

## Instant and Unix epoch

**Headers:** `Instant/Instant.h`, `Epoch/Epoch.h`

Instant operations:

- `INSTANT_FUNC(Compare)` → `Chronometry_Instant_Compare`
- `INSTANT_FUNC(AddDuration)` → `Chronometry_Instant_AddDuration`
- `INSTANT_FUNC(DurationBetween)` → `Chronometry_Instant_DurationBetween`

Epoch conversions:

- `EPOCH_FUNC(DateToJulianDayNumber)` → `Chronometry_Epoch_DateToJulianDayNumber`
- `EPOCH_FUNC(DateFromJulianDayNumber)` → `Chronometry_Epoch_DateFromJulianDayNumber`
- `EPOCH_FUNC(DateToRataDie)` → `Chronometry_Epoch_DateToRataDie`
- `EPOCH_FUNC(DateTimeToUnix)` → `Chronometry_Epoch_DateTimeToUnix`
- `EPOCH_FUNC(DateTimeFromUnix)` → `Chronometry_Epoch_DateTimeFromUnix`

Example:

```c
Chronometry_Instant instant;
EPOCH_FUNC(DateTimeToUnix)(dateTime, &instant);

/* direct */
Chronometry_Epoch_DateTimeToUnix(dateTime, &instant);
```

## Format

**Header:** `Format/Format.h`

| Indirect | Direct |
| --- | --- |
| `CHRONOMETRY_FORMAT_FUNC(DateISO)(date,buf,cap)` | `Chronometry_Format_DateISO(...)` |
| `CHRONOMETRY_FORMAT_FUNC(DateTimeISO)(dt,buf,cap)` | `Chronometry_Format_DateTimeISO(...)` |
| `CHRONOMETRY_FORMAT_FUNC(ParseDateISO)(text,&date)` | `Chronometry_Format_ParseDateISO(...)` |
| `CHRONOMETRY_FORMAT_FUNC(ParseDateTimeISO)(text,&dt)` | `Chronometry_Format_ParseDateTimeISO(...)` |

Example:

```c
char buffer[64];
CHRONOMETRY_FORMAT_FUNC(DateISO)(date, buffer, sizeof(buffer));
```

Direct: `Chronometry_Format_DateISO(date, buffer, sizeof(buffer))`.

## Timezone / fixed UTC offsets

**Header:** `Timezone/Timezone.h`

Types: `Chronometry_UtcOffset`, `Chronometry_OffsetDateTime`.

- `TIMEZONE_FUNC(OffsetIsValid)` → `Chronometry_Timezone_OffsetIsValid`
- `TIMEZONE_FUNC(ToUTC)` → `Chronometry_Timezone_ToUTC`
- `TIMEZONE_FUNC(FromUTC)` → `Chronometry_Timezone_FromUTC`

These APIs model explicit UTC offsets. They are not a full IANA/TZif timezone
database.

## Timer, Delta, and FrameLimiter

**Header:** `Timer/Timer.h`

Timer:

- `TIMER_FUNC(Start)` → `Chronometry_Timer_Start`
- `TIMER_FUNC(Elapsed)` → `Chronometry_Timer_Elapsed`
- `TIMER_FUNC(Restart)` → `Chronometry_Timer_Restart`

Delta:

- `TIMER_FUNC(DeltaStart)` → `Chronometry_Timer_DeltaStart`
- `TIMER_FUNC(DeltaUpdate)` → `Chronometry_Timer_DeltaUpdate`

Frame limiter:

- `TIMER_FUNC(FrameLimiterCreate)` → `Chronometry_Timer_FrameLimiterCreate`
- `TIMER_FUNC(FrameLimiterFromFPS)` → `Chronometry_Timer_FrameLimiterFromFPS`
- `TIMER_FUNC(FrameLimiterBegin)` → `Chronometry_Timer_FrameLimiterBegin`
- `TIMER_FUNC(FrameLimiterRemaining)` → `Chronometry_Timer_FrameLimiterRemaining`

Example:

```c
Chronometry_FrameLimiter limiter;
TIMER_FUNC(FrameLimiterFromFPS)(60, &limiter);
TIMER_FUNC(FrameLimiterBegin)(&limiter);

Chronometry_Duration remaining;
TIMER_FUNC(FrameLimiterRemaining)(&limiter, &remaining);
```

Direct equivalents are `Chronometry_Timer_FrameLimiterFromFPS`,
`Chronometry_Timer_FrameLimiterBegin`, and
`Chronometry_Timer_FrameLimiterRemaining`. Sleeping itself lives in the
Concurrency Thread package so Chronometry can remain focused on timekeeping.
