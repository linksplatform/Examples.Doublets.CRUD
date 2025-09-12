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