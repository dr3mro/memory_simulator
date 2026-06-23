#ifndef SIM_H
#define SIM_H

#include "data_types.h"

typedef struct {
    MemoryState mem;
    MemoryPage *pages;
    AllocationStrategy strategy;
} SimState;

SimState* sim_init(MemoryState *mem, AllocationStrategy strategy);
void sim_tick(SimState *sim, Job *all_jobs, int all_jobs_count, int current_time);
void sim_print_state(SimState *sim, Job *all_jobs, int all_jobs_count, int current_time);
void sim_cleanup(SimState *sim);

#endif // SIM_H
