#include <string.h>
#include "memory_alloc.h"

// Initialize memory - all pages free
void init_memory(MemoryPage memory[], int pages) {
    for (int i = 0; i < pages; i++) {
        memory[i].job_id = -1;
        memory[i].allocated = 0;
    }
}

// Get free memory in KB
int get_free_memory_kb(MemoryPage memory[], int pages) {
    int free = 0;
    for (int i = 0; i < pages; i++) {
        if (memory[i].job_id == -1) {
            free++;
        }
    }
    return free;  // Already in pages (1 KB each)
}

// Get number of free pages
int get_free_pages(MemoryPage memory[], int pages) {
    return get_free_memory_kb(memory, pages);
}

// Deallocate memory for a job
void deallocate(MemoryPage memory[], int job_id, int pages) {
    for (int i = 0; i < pages; i++) {
        if (memory[i].job_id == job_id) {
            memory[i].job_id = -1;
            memory[i].allocated = 0;
        }
    }
}

// Best-Fit: find the smallest hole that fits
int allocate_best_fit(MemoryPage memory[], int size, int job_id, int pages) {
    int best_start = -1;
    int best_size = pages + 1;
    int current_free = 0;
    int current_start = -1;

    // Find the smallest hole that fits
    for (int i = 0; i < pages; i++) {
        if (memory[i].job_id == -1) {
            if (current_start == -1) {
                current_start = i;
            }
            current_free++;
        } else {
            if (current_free >= size && current_free < best_size) {
                best_start = current_start;
                best_size = current_free;
            }
            current_free = 0;
            current_start = -1;
        }
    }

    // Check the last free space
    if (current_free >= size && current_free < best_size) {
        best_start = current_start;
        best_size = current_free;
    }

    // Allocate if we found space
    if (best_start != -1) {
        for (int i = best_start; i < best_start + size; i++) {
            memory[i].job_id = job_id;
            memory[i].allocated = 1;
        }
        return 1;
    }

    return 0;  // Allocation failed
}

// First-Fit: find the first hole that fits
int allocate_first_fit(MemoryPage memory[], int size, int job_id, int pages) {
    int current_free = 0;
    int current_start = -1;

    // Find the first hole that fits
    for (int i = 0; i < pages; i++) {
        if (memory[i].job_id == -1) {
            if (current_start == -1) {
                current_start = i;
            }
            current_free++;

            // Check if we have enough space
            if (current_free >= size) {
                for (int j = current_start; j < current_start + size; j++) {
                    memory[j].job_id = job_id;
                    memory[j].allocated = 1;
                }
                return 1;
            }
        } else {
            current_free = 0;
            current_start = -1;
        }
    }

    return 0;  // Allocation failed
}

// Worst-Fit: find the largest hole that fits
int allocate_worst_fit(MemoryPage memory[], int size, int job_id, int pages) {
    int worst_start = -1;
    int worst_size = -1;
    int current_free = 0;
    int current_start = -1;

    // Find the largest hole that fits
    for (int i = 0; i < pages; i++) {
        if (memory[i].job_id == -1) {
            if (current_start == -1) {
                current_start = i;
            }
            current_free++;
        } else {
            if (current_free >= size && current_free > worst_size) {
                worst_start = current_start;
                worst_size = current_free;
            }
            current_free = 0;
            current_start = -1;
        }
    }

    // Check the last free space
    if (current_free >= size && current_free > worst_size) {
        worst_start = current_start;
        worst_size = current_free;
    }

    // Allocate if we found space
    if (worst_start != -1) {
        for (int i = worst_start; i < worst_start + size; i++) {
            memory[i].job_id = job_id;
            memory[i].allocated = 1;
        }
        return 1;
    }

    return 0;  // Allocation failed
}
