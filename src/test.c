#include <stdio.h>
#include "stack.h"




int main(void) 
{

	int d[10]; 
	stack_t *s;

	for (int i = 0; i < 10; ++i) {
		d[i] = i;
	}

	stack_init(&s);

	for (int i = 0; i < 10; ++i) 
		stack_push(s, &d[i]);

	for (int i = 0; i < 5; ++i) {
		void *v = stack_pop(s);
		printf("*v = %d\n", *(int*)v);
	}

	stack_free(s);

	return 0;
}

