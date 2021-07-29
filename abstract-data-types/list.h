#ifndef LIST_H
#define LIST_H

#include <stddef.h>


/* list */
// extern const void * List;


struct Node {
	void * data;
	struct Node * next;
};


/* create first element of the list and return it */
struct Node * node_create(void * data);

/* free list memory */
void list_destroy(struct Node * list);

/* add element to the beginning of the list */
void list_prepend(struct Node ** old, void * data);

/* add element to the end of the list */
void list_append(struct Node ** old, void * data);

/* number of Nodes in the list */
size_t list_length(const struct Node * list);

/* last element in the list */
struct Node * list_last(struct Node * list);

/* find element with specified index */
const struct Node * list_node_at(const struct Node * list, size_t idx);

#endif

