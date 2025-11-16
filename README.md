# SampVoice Safe Wrapper

## RUS
Безопасная обёртка для плагина SampVoice в SA-MP (San Andreas Multiplayer).

## Описание

Этот проект предоставляет безопасные функции-обёртки для нативного API плагина SampVoice, которые включают проверки на корректность параметров перед вызовом оригинальных функций. Это помогает предотвратить ошибки и краши сервера при неправильном использовании детектов.

## Особенности

-  Проверка подключения игрока перед вызовом функций
-  Валидация параметров (ID ключей, расстояния, потоков)
-  Безопасная очистка потоков при отключении игрока
-  Защита от использования невалидных указателей (NULL проверки)
-  Автоматическая нормализация некорректных значений

## Установка

1. Скопируйте файлы `sampvoice.inc` и `sampvoice_safe.inc` в папку `pawno/include/` вашего сервера SA-MP
2. Подключите обёртку в вашем gamemode:

```pawn
#include <sampvoice_safe>
```

3. Используйте функции с суффиксом `_Safe` вместо оригинальных:

```pawn
public OnGameModeInit()
{
    
    SvInit_Safe(16); 
    return 1;
}

public OnPlayerConnect(playerid)
{
    
    if(SvHasMicro_Safe(playerid))
    {
   
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{

    SvCleanupPlayerStreams(playerid);
    return 1;
}
```
Ваша задача сделать ctrl c + ctrl v. Не получилось? ЯП не ваше.


## Доступные функции

Все функции из оригинального API имеют безопасные версии с суффиксом `_Safe`:

- `SvInit_Safe(bitrate)` - Инициализация с проверкой битрейта
- `SvGetVersion_Safe(playerid)` - Получение версии с проверкой подключения
- `SvHasMicro_Safe(playerid)` - Проверка микрофона
- `SvStartRecord_Safe(playerid)` / `SvStopRecord_Safe(playerid)` - Управление записью
- `SvAddKey_Safe(playerid, keyid)` - Добавление ключа с валидацией
- `SvHasKey_Safe(playerid, keyid)` / `SvRemoveKey_Safe(playerid, keyid)` - Работа с ключами
- `SvCreateSLStreamAtPlayer_Safe(...)` - Создание потока с проверками
- `SvCreateDLStreamAtPlayer_Safe(...)` - Создание лимитированного потока
- `SvAttachListenerToStream_Safe(...)` / `SvAttachSpeakerToStream_Safe(...)` - Присоединение к потокам
- `SvDeleteStream_Safe(stream)` - Безопасное удаление потока (с очисткой)
- `SvCleanupPlayerStreams(playerid)` - Очистка всех потоков игрока



## ENG

A secure wrapper for the SampVoice plugin in SA-MP (San Andreas Multiplayer).

## Description

This project provides secure wrapper functions for the native SampVoice plugin API, which include parameter validation checks before calling the original functions. This helps prevent errors and server crashes when using the API incorrectly.

## Features

- Checks player connection before calling functions
- Parameter validation (ID keys, distances, streams)
- Safe thread cleanup when a player disconnects
- Protection against using invalid pointers (NULL checks)
- Automatic normalization of incorrect values

## Installation

1. Copy the files `sampvoice.inc` and `sampvoice_safe.inc` to the `pawno/include/` folder of your SA-MP server
2. Connect the wrapper in your gamemode:


```pawn
#include <sampvoice_safe>
```

3. Use functions with the `_Safe` suffix instead of the original ones:

```pawn
public OnGameModeInit()
{
 
 SvInit_Safe(16); 
 return 1;
}

public OnPlayerConnect(playerid)
{
 
 if(SvHasMicro_Safe(playerid))
 {
 
 }
 return 1;
}

public OnPlayerDisconnect(playerid, reason)
{

 SvCleanupPlayerStreams(playerid);
 return 1;
}
```

## Available functions

All functions from the original API have safe versions with the suffix `_Safe`:

- `SvInit_Safe(bitrate)` - Initialization with bitrate verification
- `SvGetVersion_Safe(playerid)` - Getting the version with connection verification
- `SvHasMicro_Safe(playerid)` - Checking the microphone
- `SvStartRecord_Safe(playerid)` / `SvStopRecord_Safe(playerid)` - Record management
- `SvAddKey_Safe(playerid, keyid)` - Adding a key with validation
- `SvHasKey_Safe(playerid, keyid)` / `SvRemoveKey_Safe(playerid, keyid)` - Working with keys
- `SvCreateSLStreamAtPlayer_Safe(...)` - Creating a stream with checks

## Created by Enot-gg 14.11.2025
