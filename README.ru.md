[![Состояние сборки](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/actions?workflow=CI)

# Examples.Doublets.CRUD.DotNet ([english version](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/README.md))

Пример для быстрого старта, который показывает как создать, прочитать, обновить и удалить первую [связь](https://github.com/Konard/LinksPlatform/wiki/%D0%A7%D0%90%D0%92%D0%9E#%D0%A7%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D1%81%D0%B2%D1%8F%D0%B7%D1%8C) используя [Дуплеты](https://github.com/linksplatform/Data.Doublets).

## Для запуска требуется
* Linux, macOS или Windows
* [.NET 5+ или .NET Core 2.2+](https://dotnet.microsoft.com/download)
* NuGet пакет [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) с версией 0.6.0 или выше

## [Код](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/Program.cs) | [Запустить .NET fiddle](https://dotnetfiddle.net/Y7Zvt0)

```C#
using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// Хранилище дуплетов привязывается к файлу "db.links":
using var links = new UnitedMemoryLinks<uint>("db.links");

// Создание связи-дуплета: 
var link = links.Create();

// Связь обновляется чтобы ссылаться на себя дважды (в качестве начала и конца):
link = links.Update(link, newSource: link, newTarget: link);

// Операции чтения:
Console.WriteLine($"Количество связей в хранилище данных: {links.Count()}.");
Console.WriteLine("Содержимое хранилища данных:");
var any = links.Constants.Any; // Означает любой адрес связи или отсутствие ограничения на адрес связи
// Аргументы запроса интерпретируются как органичения
var query = new Link<uint>(index: any, source: any, target: any);
links.Each((link) => {
    Console.WriteLine(links.Format(link));
    return links.Constants.Continue;
}, query);

// Сброс содержимого связи:
link = links.Update(link, newSource: default, newTarget: default);

// Удаление связи:
links.Delete(link);
```
[Ожидаемый вывод](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/runs/2646250538#step:3:4):

```
Количество связей в хранилище данных: 1.
Содержимое хранилища данных:
(1: 1 1)
```

Посмотрите [документацию по ILinks\<TLinkAddress\>](https://linksplatform.github.io/Data/csharp/api/Platform.Data.ILinks-2.html) чтобы изучить подробности.

## Ищите что-то интереснее?
* [Сравнение между SQLite и Дуплетами](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Поисковый движок со встроенным поисковым роботом, который хранит веб-страницы в Дуплетах](https://github.com/linksplatform/Crawler)
