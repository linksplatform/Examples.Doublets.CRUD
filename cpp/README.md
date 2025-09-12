[![Actions Status](https://github.com/linksplatform/Examples.Doublets.CRUD/workflows/CI/badge.svg)](https://github.com/linksplatform/Examples.Doublets.CRUD/actions?workflow=CI)

# Examples.Doublets.CRUD.Cpp

A quick start example that shows how to create, read, update and delete the first [link](https://github.com/Konard/LinksPlatform/wiki/FAQ#what-does-the-link-mean) using [Doublets](https://github.com/linksplatform/Data.Doublets) in C++.

## Prerequisites
* Linux, macOS or Windows
* [CMake 3.13+](https://cmake.org/download/)
* C++20 compatible compiler (GCC 10+, Clang 10+, or MSVC 19.29+)
* [Conan package manager](https://conan.io/downloads.html) (optional but recommended)
* [Platform.Data.Doublets](https://github.com/linksplatform/Data.Doublets) library

## Building

### Using Conan (Recommended)

```bash
mkdir build && cd build
conan install .. --build=missing
cmake ..
cmake --build .
```

### Using CMake directly

If you have the Platform.Data.Doublets repository cloned locally:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Running

After building, run the executable:

```bash
./bin/Examples.Doublets.CRUD.Cpp
```

## [The code](https://github.com/linksplatform/Examples.Doublets.CRUD/blob/main/cpp/main.cpp)

```cpp
#include <iostream>
#include <memory>
#include <cstdio>
#include <Platform.Data.Doublets.h>

using namespace Platform::Data::Doublets;
using namespace Platform::Data::Doublets::Memory::United::Generic;
using namespace Platform::Memory;
using namespace Platform::Interfaces;

int main() {
    try {
        // A doublet links store is mapped to the "db.links" file:
        using TLinkAddress = std::uint64_t;
        using LinksOptionsType = LinksOptions<TLinkAddress>;
        
        FileMappedResizableDirectMemory memory{"db.links"};
        UnitedMemoryLinks<LinksOptionsType> links{std::move(memory)};
        
        // Creating a doublet link:
        auto link = Create(links);
        
        // The link is updated to reference itself twice (as a source and as a target):
        // The passed arguments are: an updated address, a new source, and a new target
        link = Update(links, link, link, link);
        
        // Read operations:
        std::cout << "The number of links in the data store is " << Count(links) << "." << std::endl;
        std::cout << "Data store contents:" << std::endl;
        
        // Means any link address or that there is no restriction on link address
        const auto any = links.Constants.Any;
        
        // The arguments of a query are restrictions: on address, on source, on target
        typename UnitedMemoryLinks<LinksOptionsType>::LinkType query{any, any, any};
        
        links.Each(query, [&links](const auto& foundLink) -> TLinkAddress {
            std::cout << "(" << foundLink.Index << ": " << foundLink.Source << " " << foundLink.Target << ")" << std::endl;
            return links.Constants.Continue;
        });
        
        // Cleaning (resetting) the contents of the link:
        link = Update(links, link, TLinkAddress{0}, TLinkAddress{0});
        
        // Removing the link
        Delete(links, link);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
    
    return 0;
}
```

The expected output is:

```
The number of links in the data store is 1.
Data store contents:
(1: 1 1)
```

Look at [Platform.Data.Doublets C++ documentation](https://github.com/linksplatform/Data.Doublets/tree/main/cpp) for more details.

## Looking for something more interesting?
* [Comparison between SQLite and Doublets](https://github.com/linksplatform/Comparisons.SQLiteVSDoublets)
* [Search engine with its web crawler, that stores web-pages in the Doublets](https://github.com/linksplatform/Crawler)
* [GraphQL server that uses Doublets as the database behind the universal API](https://github.com/linksplatform/Data.Doublets.GraphQL)
* [GitHub bot that uses Doublets as the dababase for file templates](https://github.com/linksplatform/Bot)
* [JSON to Doublets importer and Doublets to JSON exporter](https://github.com/linksplatform/Data.Doublets.Json)
* [XML to Doublets importer and Doublets to XML exporter](https://github.com/linksplatform/Data.Doublets.Xml)