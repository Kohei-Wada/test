#include "list.c"

typedef list_t stack_t;


int stack_init(stack_t **s)
{
	return list_init(s);
}

void* stack_pop(stack_t *s)
{
	void *v = list_get(s, 0);
	list_delete(s, v);
	return v;
}

int stack_push(stack_t *s, void *v)
{
	return list_add_head(s, v);
}

void stack_display(stack_t *s)
{
	list_display(s);
}

void stack_free(stack_t *s)
{
	list_free(s);
}


