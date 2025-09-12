# Examples.Doublets.CRUD.C

A quick start example that shows how to create, read, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets) in C.

## Prerequisites
* Linux, macOS or Windows
* GCC or Clang compiler
* [Platform.Data.Doublets](https://github.com/linksplatform/Data.Doublets) C FFI library

## [The code](https://github.com/linksplatform/Examples.Doublets.CRUD/blob/main/c/main.c)

```C
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// FFI declarations for Platform.Data.Doublets
// Link structure
typedef struct {
    uint32_t index;
    uint32_t source;
    uint32_t target;
} Link;

// A doublet links store is mapped to the "db.links" file:
void* links_store = UInt32UnitedMemoryLinks_New("db.links");

// Creating a doublet link:
Link query = {0, 0, 0};
uint32_t link_id = UInt32UnitedMemoryLinks_Create(links_store, &query);

// The link is updated to reference itself twice (as a source and as a target):
Link restriction = {link_id, 0, 0};
Link substitution = {link_id, link_id, link_id};
link_id = UInt32UnitedMemoryLinks_Update(links_store, &restriction, &substitution);

// Read operations:
uint64_t count = UInt32UnitedMemoryLinks_Count(links_store, NULL);
printf("The number of links in the data store is %lu.\n", count);
printf("Data store contents:\n");

// Means any link address or that there is no restriction on link address
Constants consts = UInt32UnitedMemoryLinks_GetConstants(links_store);
Link any_query = {consts.any, consts.any, consts.any};
UInt32UnitedMemoryLinks_Each(links_store, &any_query, print_link);

// Cleaning (resetting) the contents of the link:
Link reset_substitution = {link_id, 0, 0};
link_id = UInt32UnitedMemoryLinks_Update(links_store, &restriction, &reset_substitution);

// Removing the link
Link delete_restriction = {link_id, 0, 0};
UInt32UnitedMemoryLinks_Delete(links_store, &delete_restriction);

// Cleanup
UInt32UnitedMemoryLinks_Drop(links_store);
```

## Build and Run

```bash
# Compile the example
make

# Run the example
./crud
```

The expected output is:

```
The number of links in the data store is 1.
Data store contents:
(1: 1 1)
```

## Note

This example uses a mock implementation for demonstration purposes. In a production environment, you would need to link against the actual Platform.Data.Doublets C FFI library.

Look at [Platform.Data.Doublets documentation](https://github.com/linksplatform/Data.Doublets) for more details.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
* [GraphQL server that uses Doublets as the database behind the universal API](https://github.com/linksplatform/Data.Doublets.GraphQL)
* [GitHub bot that uses Doublets as the dababase for file templates](https://github.com/linksplatform/Bot)
* [JSON to Doublets importer and Doublets to JSON exporter](https://github.com/linksplatform/Data.Doublets.Json)
* [XML to Doublets importer and Doublets to XML exporter](https://github.com/linksplatform/Data.Doublets.Xml)