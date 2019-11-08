[![Build Status](https://travis-ci.com/linksplatform/HelloWorld.Doublets.DotNet.svg?branch=master)](https://travis-ci.com/linksplatform/HelloWorld.Doublets.DotNet)

# HelloWorld.Doublets.DotNet ([english version](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/README.md))

Пример, который показывает как создать первую [связь](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) с помощью пакета [Platform.Data.Doublets](https://github.com/linksplatform/Data.Doublets).

## Для запуска требуется
* Linux, macOS или Windows
* [.NET Core](https://dotnet.microsoft.com/download) 2.2 или выше
* [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) NuGet пакет с версией 0.0.1 или выше

## [Код](https://github.com/linksplatform/HelloWorld.Doublets.DotNet/blob/master/Program.cs)

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
        Console.WriteLine("Привет Мир!");
        Console.WriteLine($"Это моя первая связь: ({link}: {links.GetSource(link)}->{links.GetTarget(link)}).");
        Console.WriteLine($"Всего связей в хранилище: {links.Count()}.");
        link = links.Update(link, default, default);
        links.Delete(link);
      }
    }
  }
}
```
