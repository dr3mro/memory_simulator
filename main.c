/*
 * Author: Amr Osman
 * Date: 06/22/2026
 * Description: This is a memory simulator that implements different memory management strategies.
 * Memory simulator plan:
 * 1. Read the job table input.
 * 2. Model 20 KB of memory with 1 KB pages.
 * 3. Compare first-fit, best-fit, and worst-fit allocation.
 * 4. Track job start, sleep/end state, and deallocation.
 * 5. Print the memory state after each interval.
 * --------------- Plan ----------------
 * [x] Read input jobs
 * [x] Initialize memory state
 * [ ] For each time tick:
 * [ ] add arriving jobs
 * [ ] choose allocation strategy
 * [ ] allocate memory if space exists
 * [ ] update running jobs
 * [ ] deallocate finished jobs
 * [ ] handle sleeping jobs
 * [ ] Repeat until all jobs are done
 * [ ] Print final memory state
 * [ ] Compare first-fit, best-fit, and worst-fit results
 */
#include <stdlib.h>
#include "job_man.h"
#include "memory_man.h"
#include "job.h"
#define MAX_JOBS 100

int main() {

    // Initialize the job arrays
    Job jobs1[MAX_JOBS];
    Job jobs2[MAX_JOBS];
    load_jobs(jobs1, jobs2);
    ///////////////////////////////
    // Initialize the memory state
    MemoryState memory_state ;
    memory_manager(&memory_state);
    ///////////////////////////////

    return 0;
}