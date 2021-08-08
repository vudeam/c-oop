#include <malloc.h>
#include <stddef.h>

#include "list.h"


/**
 * Implementation of list.
 *
 * NOTE: generic pointers (void *) are prefixed with an underscore.
 */


struct Node * node_create(const void * _data) {
	struct Node * element = malloc(sizeof(struct Node));
	
	element->next = 0;
	element->data = (void *) _data;

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

void * list_prepend(struct Node ** old, const void * _data) {
	struct Node * element = node_create(_data);

	element->next = *old;
	*old = element;

	return (void *) _data;
}

void * list_append(struct Node ** old, const void * _data) {
	/*
	if (! *old)
		list_prepend(old, _data);
	else
		list_last(*old)->next = node_create(_data);
	*/

	struct Node * element = node_create (_data);
	element -> next = 0;

	struct Node * tail = list_last (*old);
	if (tail)
		tail -> next = element;
	else
		*old = element;

	return (void *) _data;
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
	/*
	const struct Node * buf = list;
	size_t i = 0;

	for (;
			 buf && idx;
			 buf = buf->next, i--);

	return buf;
	*/

	const struct Node * buf = list;
	if (! buf) return 0;

	for (size_t i = 0; i < idx; i ++) {
		if (! buf) return 0;
		buf = buf -> next;
	}

	return buf;
}

struct Node * list_find (const struct Node * list, const void * data) {
	for (const struct Node * buf = list;
			 buf;
			 buf = buf->next) {
		if (buf->data == data) return (struct Node *) buf;
	}

	return 0;
}

/**
 * helper function for list_remove()
 * returns new head
 */
struct Node * list_remove_head (struct Node * list) {
	struct Node * buf = list -> next;

	//void * freed_data = list -> data;

	free (list);

	return buf;        /* new head */
}

void * list_remove (struct Node ** list, const void * data) {
	/*
	struct Node * found = list_find (list, data);

	if (! found) return 0;

	if (found == list) {
		list = list -> next;
	}
	else if (found == list_last (list)) {
		const struct Node * pre_tail = list_node_at (list, list_length (list) - 1);

		pre_tail -> next = 0;
	}
	else { }
	*/

	struct Node * found = list_find (* list, data);

	if (! found) return 0;
	if (* list == found) { /* remove the head */
		void * freed_data = (* list) -> data;
		* list = list_remove_head (* list);

		return freed_data;
	}

	struct Node * buf = * list;

	while (buf -> next != found) {
		buf = buf -> next;
	}

	buf -> next = found -> next;
	void * freed_data = buf -> data;
	free (buf);

	return freed_data;
}

