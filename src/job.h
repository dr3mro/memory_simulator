#ifndef JOB_H
#define JOB_H

typedef struct {
	int job_id;
	int start_time;
	int job_required_size;
	int execution_interval;
	char job_state[16];
} Job;

#endif // JOB_H