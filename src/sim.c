#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sim.h"
#include "memory_alloc.h"

SimState* sim_init(MemoryState *mem, AllocationStrategy strategy) {
    SimState *sim = malloc(sizeof(SimState));
    sim->mem = *mem;
    sim->pages = malloc(mem->pages * sizeof(MemoryPage));
    sim->strategy = strategy;
    
    init_memory(sim->pages, mem->pages);
    return sim;
}

void sim_tick(SimState *sim, Job *all_jobs, int all_jobs_count, int current_time) {
    // Check for jobs ending (only deallocate "End" jobs, not "Sleep" jobs)
    for (int i = 0; i < all_jobs_count; i++) {
        if (all_jobs[i].allocated && strcmp(all_jobs[i].job_state, "End") == 0) {
            if (current_time == all_jobs[i].end_time) {
                printf("    [DEALLOCATE] T=%d: Job %d freed (%d KB, state=End)\n", current_time, all_jobs[i].job_id, all_jobs[i].job_required_size);
                deallocate(sim->pages, all_jobs[i].job_id, sim->mem.pages);
                all_jobs[i].allocated = 0;
            }
        }
        // Note: "Sleep" jobs retain their allocation and never deallocate
    }

    // Check for jobs starting
    for (int i = 0; i < all_jobs_count; i++) {
        if (!all_jobs[i].allocated && all_jobs[i].start_time == current_time) {
            int success = 0;

            // Try to allocate based on strategy
            if (sim->strategy == BEST_FIT) {
                success = allocate_best_fit(sim->pages, all_jobs[i].job_required_size, 
                                           all_jobs[i].job_id, sim->mem.pages);
            } else if (sim->strategy == FIRST_FIT) {
                success = allocate_first_fit(sim->pages, all_jobs[i].job_required_size, 
                                            all_jobs[i].job_id, sim->mem.pages);
            } else if (sim->strategy == WORST_FIT) {
                success = allocate_worst_fit(sim->pages, all_jobs[i].job_required_size, 
                                            all_jobs[i].job_id, sim->mem.pages);
            }

            if (success) {
                printf("    [ALLOCATE] T=%d: Job %d allocated (%d KB, state=%s)\n", current_time, all_jobs[i].job_id, all_jobs[i].job_required_size, all_jobs[i].job_state);
                all_jobs[i].allocated = 1;
                all_jobs[i].end_time = current_time + all_jobs[i].execution_interval;
            } else {
                printf("    [FAILED] T=%d: Job %d allocation failed (needed %d KB, insufficient space)\n", current_time, all_jobs[i].job_id, all_jobs[i].job_required_size);
            }
        }
    }
}

void sim_print_state(SimState *sim, Job *all_jobs, int all_jobs_count, int current_time) {
    (void) all_jobs;
    (void) all_jobs_count;
    printf("Time %2d: Memory [", current_time);
    for (int i = 0; i < sim->mem.pages; i++) {
        if (sim->pages[i].job_id == -1) {
            printf("F");
        } else {
            printf("%d", sim->pages[i].job_id % 10);  /* Map job_id to single digit */
        }
    }
    printf("] Free: %2d KB\n", get_free_memory_kb(sim->pages, sim->mem.pages));
}

void sim_cleanup(SimState *sim) {
    free(sim->pages);
    free(sim);
}
