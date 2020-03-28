[![Состояние сборки](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/actions?workflow=CI)

# HelloWorld.Doublets.DotNet ([english version](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/README.md))

Пример, который показывает как создать, обновить и удалить первую [связь](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) с помощью [Дуплетов](https://github.com/linksplatform/Data.Doublets).

## Для запуска требуется
* Linux, macOS или Windows
* [.NET Core](https://dotnet.microsoft.com/download) 2.2 или выше
* NuGet пакет [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) с версией 0.6.0 или выше

## [Код](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/Program.cs)

```C#
using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

namespace HelloWorld.Doublets.DotNet
{
    class Program
    {
        static void Main()
        {
            using (var links = new UnitedMemoryLinks<uint>("db.links"))
            {
                var link = links.Create();
                link = links.Update(link, link, link);
                Console.WriteLine("Привет Мир!");
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
