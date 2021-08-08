/**
 * Implementation of Set using linked list.
 */

#include "list.h"
#include "new.h"


void * new (const void * type, ...) {
	struct Node * element = node_create(0);

	return (void *) element;
}

void delete(void * _item) {
	struct Node * list = _item;

	list_destroy(list);
}

void * add (void * _list, const void * _element) {
	struct Node * list = _list;

	return list_append (&list, _element);
}

void * find (const void * _list, const void * _element) {
	struct Node * list = (void *) _list;

	return (void *) list_find (list, _element);
}

void * drop (void * _list, const void * _element) {
	struct Node * list = _list;

	return list_remove (&list, _element);
}

int contains (const void * _list, const void * _element) {
	const struct Node * list = _list;

	return list_find (list, _element) ? 1 : 0;
}

/* Objects differ exactly when the array indicies representing them differ. */
int differ (const void * a, const void * b) {
	return a != b;
}

/* to keep compiler happy */
const void * Object;
const void * Set = 0;

