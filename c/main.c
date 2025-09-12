#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// FFI declarations for Platform.Data.Doublets
// Based on https://github.com/linksplatform/Data.Doublets/blob/master/c/ffi.h

// Link structure
typedef struct {
    uint32_t index;
    uint32_t source;
    uint32_t target;
} Link;

// Constants
typedef struct {
    uint32_t any;
    uint32_t continue_;
    uint32_t stop;
} Constants;

// Function declarations (these would be linked from the shared library)
void* UInt32UnitedMemoryLinks_New(const char* path);
void UInt32UnitedMemoryLinks_Drop(void* this_);
uint32_t UInt32UnitedMemoryLinks_Create(void* this_, Link* query);
uint32_t UInt32UnitedMemoryLinks_Update(void* this_, Link* restriction, Link* substitution);
uint32_t UInt32UnitedMemoryLinks_Delete(void* this_, Link* restriction);
uint64_t UInt32UnitedMemoryLinks_Count(void* this_, Link* restriction);
Constants UInt32UnitedMemoryLinks_GetConstants(void* this_);
uint8_t UInt32UnitedMemoryLinks_Each(void* this_, Link* restriction, uint8_t (*handler)(Link));
void UInt32UnitedMemoryLinks_Format(void* this_, Link link, char* output, size_t output_size);

// For this example, we'll create a simple mock implementation
// In a real scenario, these would be dynamically loaded from a shared library

// Mock implementation for demonstration
static Constants constants = {0, 1, 0};
static uint32_t next_id = 1;
static Link links[1000];
static size_t links_count = 0;

void* mock_new(const char* path) {
    (void)path; // Suppress unused parameter warning (path shown in comments)
    return &links;
}

void mock_drop(void* this_) {
    (void)this_; // Suppress unused parameter warning
    // Cleanup if needed
}

uint32_t mock_create(void* this_, Link* query) {
    (void)this_; (void)query; // Suppress unused parameter warnings
    uint32_t new_id = next_id++;
    Link new_link = {new_id, 0, 0};
    links[links_count++] = new_link;
    return new_id;
}

uint32_t mock_update(void* this_, Link* restriction, Link* substitution) {
    (void)this_; // Suppress unused parameter warning
    for (size_t i = 0; i < links_count; i++) {
        if (links[i].index == restriction->index) {
            links[i].source = substitution->source;
            links[i].target = substitution->target;
            return links[i].index;
        }
    }
    return 0;
}

uint32_t mock_delete(void* this_, Link* restriction) {
    (void)this_; // Suppress unused parameter warning
    for (size_t i = 0; i < links_count; i++) {
        if (links[i].index == restriction->index) {
            // Shift remaining elements
            for (size_t j = i; j < links_count - 1; j++) {
                links[j] = links[j + 1];
            }
            links_count--;
            return restriction->index;
        }
    }
    return 0;
}

uint64_t mock_count(void* this_, Link* restriction) {
    (void)this_; (void)restriction; // Suppress unused parameter warnings
    return links_count;
}

Constants mock_get_constants(void* this_) {
    (void)this_; // Suppress unused parameter warning
    return constants;
}

uint8_t print_link(Link link) {
    printf("(%u: %u %u)\n", link.index, link.source, link.target);
    return constants.continue_;
}

uint8_t mock_each(void* this_, Link* restriction, uint8_t (*handler)(Link)) {
    (void)this_; (void)restriction; // Suppress unused parameter warnings
    for (size_t i = 0; i < links_count; i++) {
        if (handler(links[i]) == constants.stop) {
            break;
        }
    }
    return constants.continue_;
}

int main() {
    // A doublet links store is mapped to the "db.links" file:
    void* links_store = mock_new("db.links");
    
    // Creating a doublet link:
    Link query = {0, 0, 0};
    uint32_t link_id = mock_create(links_store, &query);
    
    // The link is updated to reference itself twice (as a source and as a target):
    // The passed arguments are: an updated address, a new source, and a new target
    Link restriction = {link_id, 0, 0};
    Link substitution = {link_id, link_id, link_id};
    link_id = mock_update(links_store, &restriction, &substitution);
    
    // Read operations:
    uint64_t count = mock_count(links_store, NULL);
    printf("The number of links in the data store is %lu.\n", count);
    printf("Data store contents:\n");
    
    // Means any link address or that there is no restriction on link address
    Constants consts = mock_get_constants(links_store);
    // The arguments of a query are restrictions: on address, on source, on target
    Link any_query = {consts.any, consts.any, consts.any};
    mock_each(links_store, &any_query, print_link);
    
    // Cleaning (resetting) the contents of the link:
    Link reset_substitution = {link_id, 0, 0};
    link_id = mock_update(links_store, &restriction, &reset_substitution);
    
    // Removing the link
    Link delete_restriction = {link_id, 0, 0};
    mock_delete(links_store, &delete_restriction);
    
    // Cleanup
    mock_drop(links_store);
    
    return 0;
}