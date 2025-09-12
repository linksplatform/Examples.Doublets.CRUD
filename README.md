# Examples.Doublets.CRUD

Quick start examples that show how to create, read, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets) across different programming languages.

## Language Implementations

### C# (.NET)
[![Actions Status](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD.DotNet/actions?workflow=CI)

**Location:** [`csharp/`](./csharp/)

**Prerequisites:**
- .NET 5+ or .NET Core 2.2+
- Platform.Data.Doublets NuGet package

[View C# Example](./csharp/README.md) | [Run .NET fiddle](https://dotnetfiddle.net/ERHBKA)

### Rust
**Location:** [`rust/`](./rust/)

**Prerequisites:**
- Rust toolchain
- doublets-rs crate

[View Rust Example](./rust/)

### C
**Location:** [`c/`](./c/)

**Prerequisites:**
- GCC or Clang compiler
- Platform.Data.Doublets C FFI library

[View C Example](./c/README.md)

## What is Doublets?

Doublets is a data structure that represents everything as links (connections) between elements. Each link has:
- **Index**: Unique identifier
- **Source**: What the link points from
- **Target**: What the link points to

## CRUD Operations

All examples demonstrate the same fundamental operations:

1. **Create**: Generate a new link
2. **Read**: Query and iterate through links
3. **Update**: Modify link connections
4. **Delete**: Remove links from storage

## Expected Output

All language implementations produce similar output:
```
The number of links in the data store is 1.
Data store contents:
(1: 1 1)
```

This shows a self-referential link where the link with index 1 points to itself as both source and target.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
* [GraphQL server that uses Doublets as the database behind the universal API](https://github.com/linksplatform/Data.Doublets.GraphQL)
* [GitHub bot that uses Doublets as the dababase for file templates](https://github.com/linksplatform/Bot)
* [JSON to Doublets importer and Doublets to JSON exporter](https://github.com/linksplatform/Data.Doublets.Json)
* [XML to Doublets importer and Doublets to XML exporter](https://github.com/linksplatform/Data.Doublets.Xml)

## Contributing

Feel free to contribute examples in other programming languages following the same CRUD pattern demonstrated here.