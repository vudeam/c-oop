#ifndef LIST_H
#define LIST_H

#include <stddef.h>


struct Node {
	void * data;
	struct Node * next;
};


/**
 * create first element of the list and return it
 */
struct Node * node_create(const void * data);

/**
 * free list memory
 */
void list_destroy(struct Node * list);

/**
 * add element to the beginning of the list
 * returns data
 */
void * list_prepend(struct Node ** old, const void * data);

/**
 * add element to the end of the list
 * returns data
 */
void * list_append(struct Node ** old, const void * data);

/**
 * number of Nodes in the list
 */
size_t list_length(const struct Node * list);

/**
 * last element in the list
 */
struct Node * list_last(struct Node * list);

/**
 * find element with specified index
 */
const struct Node * list_node_at(const struct Node * list, size_t idx);

/**
 * check if element is present in the list
 * returns found element or NULL
 */
struct Node * list_find (const struct Node * list, const void * data);

/**
 * remove element from the list
 * returns removed data (NOT node)
 */
void * list_remove (struct Node ** list, const void * data);


#endif /* LIST_H */

