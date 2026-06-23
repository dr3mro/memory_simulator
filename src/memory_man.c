#include "data_types.h"

void memory_manager(MemoryState* memory_state) {
    // Initialize the memory state with 20 KB of memory and 1 KB pages
    memory_state->total_memory = 20 * 1024; // 20 KB
    memory_state->page_size = 1024; // 1 KB
    memory_state->pages = memory_state->total_memory / memory_state->page_size;
}