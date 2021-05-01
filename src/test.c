#include <stdio.h>
#include "queue.h"


int main(void) 
{

	int d[10]; 
	queue_t *q;

	for (int i = 0; i < 10; ++i) {
		d[i] = i;
	}

	queue_init(&q);

	for (int i = 0; i < 10; ++i) 
		queue_enque(q, &d[i]);

	for (int i = 0; i < 5; ++i) {
		void *v = queue_deque(q);
		printf("*v = %d\n", *(int*)v);
	}

	queue_free(q);

	return 0;
}

