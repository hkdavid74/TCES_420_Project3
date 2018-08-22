#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "job.h"
#include <unistd.h>


job* init_job(int id) {
	srand(time(NULL));
	job *j = (job*) malloc(sizeof(job));
	j->is_completed = 0;
	j->current_task = 0;
	j->job_id = id;
	j->tasks = rand()%3+1;
	j->task_type = rand()%2;
	if (j->task_type == 1) 
		j->task = rand()%3+2;
	else if (j->task_type == 0) 
		j->task = rand()%2;


	j->destroy = delete_job;
	j->next = next_task;
	j->print = print_job;
	j->complete = complete_task;

	return j;
}

void delete_job(job *j) {
	// printf("Free\n");
	free(j);
}

void next_task(job *j) {
	j->current_task++;
	if (j->current_task == j->tasks)
		j->is_completed = 1;
	else {
		j->task_type = rand()%2;
		if (j->task_type == 1) 
			j->task = rand()%4+7;
		else if (j->task_type == 0) 
			j->task = rand()%4+1;
	}
}

void complete_task(job *j) {
	if (j->current_task < j->tasks)
		sleep(j->task);
	else 
		printf("Job is Finished!\n");
}


void print_job(job *j) {
	printf("Job ID: %d, Current Task: %d Job Complete: %d #ofTasks: %d\n",
		j->job_id,j->current_task,j->is_completed,j->tasks);
}