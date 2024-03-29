[![Actions Status](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/actions?workflow=CI)

# Examples.Doublets.CRUD.DotNet ([русская версия](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/README.ru.md))

A quick start example that shows how to create, read, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets).

## Prerequisites
* Linux, macOS or Windows
* [.NET 5+ or .NET Core 2.2+](https://dotnet.microsoft.com/download)
* [Platform.Data.Doublets](https://www.nuget.org/packages/Platform.Data.Doublets) NuGet package with 0.6.0 or above

## [The code](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/blob/master/csharp/Program.cs) | [Run .NET fiddle](https://dotnetfiddle.net/ERHBKA)

```C#
using System;
using Platform.Data;
using Platform.Data.Doublets;
using Platform.Data.Doublets.Memory.United.Generic;

// A doublet links store is mapped to the "db.links" file:
using var links = new UnitedMemoryLinks<uint>("db.links");

// Creating a doublet link: 
var link = links.Create();

// The link is updated to reference itself twice (as a source and as a target):
// The passed arguments are: an updated address, a new source, and a new target
link = links.Update(link, newSource: link, newTarget: link);

// Read operations:
Console.WriteLine($"The number of links in the data store is {links.Count()}.");
Console.WriteLine("Data store contents:");
// Means any link address or that there is no restriction on link address
var any = links.Constants.Any; 
// The arguments of a query are restrictions: on address, on source, on target
var query = new Link<uint>(index: any, source: any, target: any);
links.Each((link) => {
    Console.WriteLine(links.Format(link));
    return links.Constants.Continue;
}, query);

// Cleaning (resetting) the contents of the link:
link = links.Update(link, newSource: default, newTarget: default);

// Removing the link
links.Delete(link);
```

The [expected output](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/runs/2646250538#step:3:4) is:

```
The number of links in the the data store is 1.
Data store contents:
(1: 1 1)
```

Look at [ILinks\<TLinkAddress\> documentation](https://linksplatform.github.io/Data/csharp/api/Platform.Data.ILinks-2.html) for more details.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
* [GraphQL server that uses Doublets as the database behind the universal API](https://github.com/linksplatform/Data.Doublets.GraphQL)
* [GitHub bot that uses Doublets as the dababase for file templates](https://github.com/linksplatform/Bot)
* [JSON to Doublets importer and Doublets to JSON exporter](https://github.com/linksplatform/Data.Doublets.Json)
* [XML to Doublets importer and Doublets to XML exporter](https://github.com/linksplatform/Data.Doublets.Xml)
