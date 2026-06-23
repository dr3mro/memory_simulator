/*
 * Author: Amr Osman
 * Date: 06/22/2026
 * Description: Memory simulator implementing different allocation strategies
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sim.h"
#include "data_types.h"
#include "read_jobs.h"
#include "memory_alloc.h"

void run_simulation(Job jobs[], int num_jobs, AllocationStrategy strategy, int max_time) {
    const char *strategy_names[] = {"Best-Fit", "First-Fit", "Worst-Fit"};
    
    printf("\n========== %s ALLOCATION ==========\n\n", strategy_names[strategy]);
    
    if (num_jobs == 0) {
        printf("No jobs to simulate.\n");
        return;
    }
    
    // Cap max_time at reasonable value to prevent infinite loops
    if (max_time <= 0 || max_time > 1000) {
        max_time = 100;
    }
    
    // Make a copy of jobs for simulation
    Job jobs_sim[MAX_JOBS];
    memcpy(jobs_sim, jobs, num_jobs * sizeof(Job));
    
    // Initialize memory state
    MemoryState mem_state = {
        .total_memory = MAX_MEMORY * PAGE_SIZE,
        .page_size = PAGE_SIZE,
        .pages = MAX_MEMORY
    };
    
    // Initialize simulator
    SimState *sim = sim_init(&mem_state, strategy);
    
    // Run simulation
    for (int t = 0; t <= max_time; t++) {
        sim_tick(sim, jobs_sim, num_jobs, t);
        sim_print_state(sim, jobs_sim, num_jobs, t);  // Print every time unit for detailed analysis
    }
    
    // Final stats
    int free_kb = get_free_memory_kb(sim->pages, sim->mem.pages);
    int used_kb = MAX_MEMORY - free_kb;
    printf("\nFinal - Used: %d KB, Free: %d KB, Utilization: %.1f%%\n\n", 
           used_kb, free_kb, (used_kb * 100.0) / MAX_MEMORY);
    
    sim_cleanup(sim);
}

int main() {
    printf("======================================\n");
    printf("MEMORY MANAGEMENT SIMULATION\n");
    printf("Total Memory: %d KB | Page Size: %d KB\n", MAX_MEMORY, PAGE_SIZE);
    printf("======================================\n");
    
    // Load jobs from CSV files
    Job jobs1[MAX_JOBS];
    Job jobs2[MAX_JOBS];
    unsigned int jobs1_count = 0;
    unsigned int jobs2_count = 0;
    
    read_input_jobs(jobs1, "jobs/jobs1.csv", &jobs1_count);
    read_input_jobs(jobs2, "jobs/jobs2.csv", &jobs2_count);
    
    printf("\nLoaded %u jobs from jobs1.csv\n", jobs1_count);
    printf("Loaded %u jobs from jobs2.csv\n\n", jobs2_count);
    
    // Calculate max time needed
    int max_time1 = 0, max_time2 = 0;
    for (int i = 0; i < (int)jobs1_count; i++) {
        int end = jobs1[i].start_time + jobs1[i].execution_interval;
        if (end > max_time1) max_time1 = end;
    }
    for (int i = 0; i < (int)jobs2_count; i++) {
        int end = jobs2[i].start_time + jobs2[i].execution_interval;
        if (end > max_time2) max_time2 = end;
    }
    
    // Initialize job allocation state
    for (int i = 0; i < (int)jobs1_count; i++) {
        jobs1[i].allocated = 0;
        jobs1[i].end_time = 0;
    }
    for (int i = 0; i < (int)jobs2_count; i++) {
        jobs2[i].allocated = 0;
        jobs2[i].end_time = 0;
    }
    
    // Run simulations for Job Set 1
    printf("\n****** JOB SET 1 SIMULATIONS ******\n");
    run_simulation(jobs1, jobs1_count, BEST_FIT, max_time1);
    run_simulation(jobs1, jobs1_count, FIRST_FIT, max_time1);
    run_simulation(jobs1, jobs1_count, WORST_FIT, max_time1);
    
    // Run simulations for Job Set 2
    printf("\n****** JOB SET 2 SIMULATIONS ******\n");
    run_simulation(jobs2, jobs2_count, BEST_FIT, max_time2);
    run_simulation(jobs2, jobs2_count, FIRST_FIT, max_time2);
    run_simulation(jobs2, jobs2_count, WORST_FIT, max_time2);
    
    return 0;
}