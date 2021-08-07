/**
 * Implementation of Set using linked list.
 */

#include "list.h"
#include "new.h"


const void * Set = 0;


void * new (const void * type, ...) {
	struct Node * element = node_create(0);

	return (void *) element;
}

void delete(void * _item) {
	struct Node * list = _item;

	list_destroy(list);
}

void * add
	
