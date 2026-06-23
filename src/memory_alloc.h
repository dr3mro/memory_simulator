#ifndef MEMORY_ALLOC_H
#define MEMORY_ALLOC_H

#include "data_types.h"

// Allocation functions
int allocate_best_fit(MemoryPage memory[], int size, int job_id, int pages);
int allocate_first_fit(MemoryPage memory[], int size, int job_id, int pages);
int allocate_worst_fit(MemoryPage memory[], int size, int job_id, int pages);

// Deallocation
void deallocate(MemoryPage memory[], int job_id, int pages);

// Utilities
void init_memory(MemoryPage memory[], int pages);
int get_free_memory_kb(MemoryPage memory[], int pages);
int get_free_pages(MemoryPage memory[], int pages);

#endif // MEMORY_ALLOC_H
