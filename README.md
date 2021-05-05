[![Actions Status](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/actions?workflow=CI)

# HelloWorld.Doublets.DotNet ([русская версия](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/README.ru.md))

A quick start example that shows how to create, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets).

## Prerequisites
* Linux, macOS or Windows
* [.NET 5+ or .NET Core 2.2+](https://dotnet.microsoft.com/download)
* [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) NuGet package with 0.6.0 or above

## [The code](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/Program.cs)

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
                Console.WriteLine("Hello World!");
                Console.WriteLine($"The number of links in the the data store is {links.Count()}.");
                Console.WriteLine("Data store contents:");
                var query = new Link<uint>(links.Constants.Any, links.Constants.Any, links.Constants.Any);
                links.Each((link) => {
                    Console.WriteLine($"{links.Format(link)}");
                    return links.Constants.Continue;
                }, query);
                link = links.Update(link, default, default);
                links.Delete(link);
            }
        }
    }
}
```

Run [this example at .NET fiddle](https://dotnetfiddle.net/Y7Zvt0). Look for [ILinks\<TLinkAddress\> documentation](https://linksplatform.github.io/Data/csharp/api/Platform.Data.ILinks-2.html) for more details.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
