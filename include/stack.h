#ifndef _STACK_H_
#define _STACK_H_
#include "list.h"


typedef list_t stack_t;

int stack_init(stack_t **s);
void *stack_pop(stack_t *s);
int stack_push(stack_t *s, void *v);
void stack_free(stack_t *s);


#endif 



