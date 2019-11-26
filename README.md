[![Actions Status](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/actions?workflow=CI)

# HelloWorld.Doublets.DotNet ([русская версия](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/README.ru.md))

A quick start example that shows how to create the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Platform.Data.Doublets](https://github.com/linksplatform/Data.Doublets) package.

## Prerequisites
* Linux, macOS or Windows
* [.NET Core](https://dotnet.microsoft.com/download) 2.2 or above
* [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) NuGet package with 0.0.1 or above

## [The code](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/Program.cs)

```C#
using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.ResizableDirectMemory.Generic;

namespace HelloWorld.Doublets.DotNet
{
  class Program
  {
    static void Main()
    {
      using (var links = new ResizableDirectMemoryLinks<uint>("db.links"))
      {
        var link = links.Create();
        link = links.Update(link, link, link);
        Console.WriteLine("Hello World!");
        Console.WriteLine($"This is my first link: ({link}: {links.GetSource(link)}->{links.GetTarget(link)}).");
        Console.WriteLine($"Total links in the storage: {links.Count()}.");
        link = links.Update(link, default, default);
        links.Delete(link);
      }
    }
  }
}
```

## Looking something more complex?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)