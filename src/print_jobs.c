#include <stdio.h>
#include "print_jobs.h"

void print_jobs(const Job *jobs, unsigned int jobs_count) {

    printf("Loaded %u jobs:\n", jobs_count);
    for (unsigned int i = 0; i < jobs_count; i++) {
    	printf("Job %d: start=%d, size=%d, interval=%d, state=%s\n",
    		jobs[i].job_id,
    		jobs[i].start_time,
    		jobs[i].job_required_size,
    		jobs[i].execution_interval,
    		jobs[i].job_state);
    }
}