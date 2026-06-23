
#include "read_jobs.h"
#include "print_jobs.h"
#include "job_man.h"
#include <stdio.h>
#include <stdlib.h>

void load_jobs(Job* jobs1, Job* jobs2) {    
    unsigned int jobs_count1 = 0;
    unsigned int jobs_count2 = 0;
    
    // Read jobs from CSV file
    read_input_jobs(jobs1, "jobs/jobs1.csv", &jobs_count1);
    read_input_jobs(jobs2, "jobs/jobs2.csv", &jobs_count2);

    // Print the loaded jobs
    print_jobs(jobs1, jobs_count1);
    print_jobs(jobs2, jobs_count2);  
}