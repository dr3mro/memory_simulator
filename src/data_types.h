#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#define MAX_JOBS 100
#define MAX_MEMORY 20  // 20 Kbytes
#define PAGE_SIZE 1    // 1 Kbyte

// Job structure with lifecycle tracking
typedef struct {
    int job_id;
    int start_time;
    int job_required_size;
    int execution_interval;
    char job_state[16];  // "End" or "Sleep"
    int allocated;       // 1 if in memory, 0 otherwise
    int end_time;        // When job completes
} Job;

// Memory page structure
typedef struct {
    int job_id;   // Which job occupies this page (-1 if free)
    int allocated;
} MemoryPage;

// Memory state structure
typedef struct {
    int total_memory;
    int page_size;
    int pages;
} MemoryState;

// Allocation strategy enumeration
typedef enum {
    BEST_FIT = 0,
    FIRST_FIT = 1,
    WORST_FIT = 2
} AllocationStrategy;

#endif // DATA_TYPES_H
