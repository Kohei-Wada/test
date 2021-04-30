#include <stdio.h> 
#include "list.h"

typedef struct subject {
	list_t *observers;
} subject_t;

typedef struct observer  observer_t;

typedef struct iobserver {
	void (*update)(observer_t *o);
} iobserver_t;

struct observer {
	subject_t *s;
	iobserver_t *interface;
};

/**********************************************************/

int subject_init(subject_t *s)
{
	if (!s) return 1;
	return list_init(&s->observers);
}

void subject_free(subject_t *s)
{
	if (s) list_free(s->observers);
}

int subject_attach(subject_t *s, observer_t *o)
{
	if (!s || !o) return 1;
	return list_add_tail(s->observers, o);
}

int subject_detach(subject_t *s, observer_t *o)
{
	if (!s || !o) return 1;
	return list_delete(s->observers, o);
}

void subject_notify(subject_t *s)
{
	for (observer_t *o = list_get(s->observers, 0); o; o = list_next(s->observers, o))
		o->interface->update(o);
}

/**********************************************************/

int observer_init(observer_t *o, iobserver_t *io, subject_t *s)
{
	if (!o || !io || !s) return 1;
	o->interface = io;
	o->s = s;
	return subject_attach(s, o);
}

int observer_free(observer_t *o)
{
	return subject_detach(o->s, o);
}

