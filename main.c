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
 * [ ] Initialize memory state
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

#include <stdio.h>
#include <stdlib.h>
#include "data_types.h"
#include "read_jobs.h"
#include "print_jobs.h"

#define MAX_JOBS 100

int main() {
    Job jobs1[MAX_JOBS];
    Job jobs2[MAX_JOBS];

    unsigned int jobs_count1 = 0;
    unsigned int jobs_count2 = 0;
    
    // Read jobs from CSV file
    read_input_jobs(jobs1, "jobs/jobs1.csv", &jobs_count1);
    read_input_jobs(jobs2, "jobs/jobs2.csv", &jobs_count2);

    // Print the loaded jobs
    print_jobs(jobs1, jobs_count1);
    print_jobs(jobs2, jobs_count2);  
    
    return 0;
}