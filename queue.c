
#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
	int qsize;	
	int head,tail;
	job* jobqueue; 
}queue;


void enqueue(queue *q,job j) {
	for (int i=0; i<q->qsize; i++) {
		if (q->tail==qsize && q->head!=q->tail) {
			printf("Queue is full!\n");
			return;
		}
		if (q->head==q->tail) {
			q->head =0;
			q->tail =0;
			q->jobqueue[i]=j;
			q->tail++;
			return;
		}
		if (i==q->tail) {
			q->jobqueue[i]=j;
			q->tail++;
			return;
		}
	}
}

job* dequeue(queue *q) {
	for (int i=0; i<q->size; i++) {
		if (q->head == q->tail && q->tail!=0) {
			q->head = 0;
		}
		if (i==q->head) {
			job *ret = &q->jobqueue[i];
			q->head++;
			return ret;
		}
	}
}

int queue_size(queue *q) {
	int quantity=0;
	for (int i=q->head; i<q->tail; i++) {
		quantity++;
	}
	return quantity;
}

void queue_init(queue *q,int size) {
	q->qsize = size;
	q->head = 0;
	q->tail = 0;
	q->jobqueue = (job*)calloc(size,sizeof(job));
	
}