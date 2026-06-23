#ifndef DATA_TYPES_H
#define DATA_TYPES_H

typedef struct {
	int job_id;
	int start_time;
	int job_required_size;
	int execution_interval;
	char job_state[16];
} Job;

typedef struct {
	int total_memory;
	int page_size;
	int pages;
} MemoryState;

#endif

