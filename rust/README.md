[![Actions Status](https://github.com/linksplatform/Examples.Doublets.CRUD/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD/actions?workflow=CI)

# Examples.Doublets.CRUD.Rust ([русская версия](https://github.com/linksplatform/Examples.Doublets.CRUD/blob/main/rust/README.ru.md))

A quick start example that shows how to create, read, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets) in Rust.

## Prerequisites
* Linux, macOS or Windows
* [Rust](https://rustup.rs/)
* [doublets](https://crates.io/crates/doublets) crate

## [The code](https://github.com/linksplatform/Examples.Doublets.CRUD/blob/main/rust/src/main.rs)

```rust
use doublets::{data, mem, unit, Doublets, DoubletsExt, Links};

fn main() -> Result<(), doublets::Error<usize>> {
    // A doublet links store is mapped to the "db.links" file:
    let mem = mem::FileMapped::from_path("db.links")?;
    let mut store = unit::Store::<usize, _>::new(mem)?;

    // Creating a doublet link:
    let link = store.create_link(1, 1)?;

    // Read operations:
    println!("The number of links in the data store is {}.", store.count_links([store.constants().any, store.constants().any, store.constants().any]));
    println!("Data store contents:");
    
    // Means any link address or that there is no restriction on link address
    let any = store.constants().any;
    // The arguments of a query are restrictions: on address, on source, on target
    store.each_iter([any, any, any]).for_each(|link| {
        println!("{link:?}");
    });

    // Cleaning (resetting) the contents of the link:
    let updated_link = store.update_link(link, 0, 0)?;

    // Removing the link
    store
        .delete_with(updated_link, |before, after| {
            data::Flow::Continue
        })
        .map(|_| ())
}
```

The expected output is:

```
The number of links in the data store is 1.
Data store contents:
[1, 1, 1]
```

Look at [doublets documentation](https://docs.rs/doublets) for more details.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
* [GraphQL server that uses Doublets as the database behind the universal API](https://github.com/linksplatform/Data.Doublets.GraphQL)
* [GitHub bot that uses Doublets as the dababase for file templates](https://github.com/linksplatform/Bot)
* [JSON to Doublets importer and Doublets to JSON exporter](https://github.com/linksplatform/Data.Doublets.Json)
* [XML to Doublets importer and Doublets to XML exporter](https://github.com/linksplatform/Data.Doublets.Xml)