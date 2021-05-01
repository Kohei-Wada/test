#include "list.c"


typedef list_t queue_t;


int queue_init(queue_t **q)
{
	return list_init(q);
}

void queue_free(queue_t *q)
{
	list_free(q);
}

int queue_enque(queue_t *q, void *v)
{
	return list_add_tail(q, v);
}

void *queue_deque(queue_t *q)
{
	void *v = list_get(q, 0);
	list_delete(q, v);
	return v;
}


