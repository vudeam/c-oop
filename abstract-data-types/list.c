#include <malloc.h>
#include <stddef.h>

#include "list.h"


/**
 * Implementation of list.
 *
 * NOTE: generic pointers (void *) are prefixed with an underscore.
 */


struct Node * node_create(void * _data) {
	struct Node * element = malloc(sizeof(struct Node));
	
	element->next = 0;
	element->data = _data;

	return element;
}

void list_destroy(struct Node * list) {
	struct Node * buf;
	while (list) {
		buf = list;
		list = list->next;
		free(buf);
	}
}

void list_prepend(struct Node ** old, void * _data) {
	struct Node * element = node_create(_data);

	element->next = *old;
	*old = element;
}

void list_append(struct Node ** old, void * _data) {
	if (! *old)
		list_prepend(old, _data);
	else
		list_last(*old)->next = node_create(_data);
}

size_t list_length(const struct Node * list) {
	size_t len = 0;
	for (const struct Node * buf = list;
			 buf;
			 buf = buf->next, len++);

	return len;
}

struct Node * list_last(struct Node * list) {
	struct Node * buf;
	for (buf = list;
			 buf && buf->next;
			 buf = buf->next);

	return buf;
}

const struct Node * list_node_at(const struct Node * list, size_t idx) {
	const struct Node * buf = list;
	size_t i = 0;

	for (;
			 buf && idx;
			 buf = buf->next, i--);

	return buf;        /* NULL if idx is out of bounds */
}

