#include <stdio.h> 
#include <stdlib.h>
#include "list.h"
#include "observer.h"

typedef struct sky {
	subject_t s; 
} sky_t;

typedef struct dragon {
	observer_t o;
	int id; 
} dragon_t;

/*******************************************************************/

void sky_init(sky_t **s)
{
	*s = malloc(sizeof(sky_t));
	subject_init((subject_t*)(*s));
}

void sky_free(sky_t *s)
{
	subject_free((subject_t*)s);
	free(s);
}

void sky_notify(sky_t *s)
{
	subject_notify((subject_t*)s);
}

/*******************************************************************/

void fly(observer_t *o)
{
	dragon_t *d = (dragon_t*)o;
	printf("inside fly %d\n", d->id);
}

iobserver_t io = {
	.update = fly,
};

void dragon_init(dragon_t **d, sky_t *s, int id)
{
	*d = malloc(sizeof(dragon_t));
	observer_init((observer_t*)(*d), &io, (subject_t*)s);
	(*d)->id = id;
}

void dragon_free(dragon_t *d)
{
	observer_free((observer_t*)d);
	free(d);
}

/*******************************************************************/
int main(void)
{
	dragon_t *d[1000];
	sky_t *s;
	sky_init(&s);

	for (int i = 0; i < 1000; ++i) 
		dragon_init(&d[i], s, i);

	sky_notify(s);

	for (int i = 0; i < 1000; ++i)
		dragon_free(d[i]);

	sky_free(s);
}

