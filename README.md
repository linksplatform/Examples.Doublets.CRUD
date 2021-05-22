[![Actions Status](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/actions?workflow=CI)

# Examples.Doublets.CRUD.DotNet ([русская версия](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/README.ru.md))

A quick start example that shows how to create, read, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets).

## Prerequisites
* Linux, macOS or Windows
* [.NET 5+ or .NET Core 2.2+](https://dotnet.microsoft.com/download)
* [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) NuGet package with 0.6.0 or above

## [The code](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/Program.cs)

```C#
using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// A doublet links store is mapped to "db.links" file:
using var links = new UnitedMemoryLinks<uint>("db.links");

// A creation of the doublet link: 
var link = links.Create();

// The link is updated to reference itself twice (as a source and a target):
link = links.Update(link, newSource: link, newTarget: link);

// Read operations:
Console.WriteLine($"The number of links in the data store is {links.Count()}.");
Console.WriteLine("Data store contents:");
var any = links.Constants.Any; // Means any link address or no restriction on link address
// Arguments of the query are interpreted as restrictions: on address, on source, on target.
var query = new Link<uint>(index: any, source: any, target: any);
links.Each((link) => {
    Console.WriteLine(links.Format(link));
    return links.Constants.Continue;
}, query);

// The link's content reset:
link = links.Update(link, newSource: default, newTarget: default);

// The link deletion:
links.Delete(link);
```

Expected output is:

```
The number of links in the the data store is 1.
Data store contents:
(1: 1 1)
```

Run [this example at .NET fiddle](https://dotnetfiddle.net/Y7Zvt0). Look at [ILinks\<TLinkAddress\> documentation](https://linksplatform.github.io/Data/csharp/api/Platform.Data.ILinks-2.html) for more details.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
