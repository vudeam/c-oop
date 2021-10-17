/**
 * Implementation of Set using linked list.
 */

#include "list.h"
#include "new.h"
#include "apply.h"
#include "store.h"


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


/**************************
 * apply.h stuff goes here
 *************************/

int apply (const void * _list,
		       int (* action) (void * object, va_list ap),
					 ...) {
	const struct Node * list = _list;
	va_list args;
	size_t count_processed = 0;
 
 	va_start (args, action);
 	for (const struct Node * buf = list;
 			 buf && buf -> next;
 			 buf = buf -> next) {
		count_processed ++;
 		if (! action ((void *) buf, args))        /* break if action() returns 0 */
 			break;
	}
 	va_end (args);                              /* POSSIBLE ERROR (IDK) */
 	
	return count_processed;
}
/*********************************************************************************/


/**************************
 * store.h stuff goes here
 *************************/

int store (const void * _object, FILE * fp) {
	// return fwrite (_object, sizeof (* _object), 1, fp);
	return 0;        /* IDK */
}

int storev (const void * _object, va_list ap) {
	FILE * fp = va_arg (ap, FILE *);
	const char * fmt = va_arg (ap, const char *);

	return vfprintf (fp, fmt, ap);
}

/**********************************************************************************/

