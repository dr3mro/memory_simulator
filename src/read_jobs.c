#include <stdio.h>
#include <string.h>
#include "read_jobs.h"

void read_input_jobs(Job *jobs, const char *filename, unsigned int *jobs_count) {
	#define MAX_LINE_LEN 256
	char line[MAX_LINE_LEN];
	
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    *jobs_count = 0;
    
    // Skip header line
    if (fgets(line, sizeof(line), file) == NULL) {
    	fclose(file);
    	return;
    }
    
    // Parse CSV rows
    while (fgets(line, sizeof(line), file)) {
    	// Remove trailing newline
    	line[strcspn(line, "\n")] = '\0';
    	
    	// Parse: job_id, start_time, job_required_size, execution_interval, job_state
    	int n = sscanf(line, "%d,%d,%d,%d,%15s",
    		&jobs[*jobs_count].job_id,
    		&jobs[*jobs_count].start_time,
    		&jobs[*jobs_count].job_required_size,
    		&jobs[*jobs_count].execution_interval,
    		jobs[*jobs_count].job_state);
    	
    	if (n == 5) {
    		(*jobs_count)++;
    	}
    }
    
    fclose(file);
}