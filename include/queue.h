#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "list.h"


typedef list_t queue_t;
int queue_init(queue_t **q);
void queue_free(queue_t *q);
int queue_enque(queue_t *q, void *v);
void *queue_deque(queue_t *q);

#endif

