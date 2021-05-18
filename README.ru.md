[![Состояние сборки](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/actions?workflow=CI)

# Examples.Doublets.CRUD.DotNet ([english version](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/README.md))

Пример, который показывает как создать, обновить и удалить первую [связь](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) с помощью [Дуплетов](https://github.com/linksplatform/Data.Doublets).

## Для запуска требуется
* Linux, macOS или Windows
* [.NET 5+ или .NET Core 2.2+](https://dotnet.microsoft.com/download)
* NuGet пакет [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) с версией 0.6.0 или выше

## [Код](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/Program.cs)

```C#
using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

namespace Examples.Doublets.CRUD.DotNet
{
    class Program
    {
        static void Main()
        {
            using (var links = new UnitedMemoryLinks<uint>("db.links"))
            {
                var link = links.Create();
                link = links.Update(link, link, link);
                Console.WriteLine($"Это моя первая связь: {links.Format(link)}");
                Console.WriteLine($"Всего связей в хранилище: {links.Count()}.");
                link = links.Update(link, default, default);
                links.Delete(link);
            }
        }
    }
}
```

## Ищите что-то интереснее?
* [Сравнение между SQLite и Дуплетами](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Поисковый движок со встроенным поисковым роботом, который хранит веб-страницы в Дуплетах](https://github.com/linksplatform/Crawler)
