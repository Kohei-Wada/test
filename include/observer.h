#ifndef _OBSERVER_H_
#define _OBSERVER_H_


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


int subject_init(subject_t *s);
void subject_free(subject_t *s);
int subject_attach(subject_t *s, observer_t *o);
int subject_detach(subject_t *s, observer_t *o);
void subject_notify(subject_t *s);


int observer_init(observer_t *o, iobserver_t *io, subject_t *s);
void observer_free(observer_t *o);

#endif
