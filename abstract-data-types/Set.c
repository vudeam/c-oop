/**
 * Implementation of Set:
 * "If an object stores no information and if every object belongs to
 * at most one set, we can represent each object and each set as a small,
 * unique, positive integer values used as indices into an array heap[].
 * If and object in a member of a set, its array element contains the
 * integer value representing the set.
 * Objects, therefore, point to the set containing them.
 *
 * NOTE: Generic pointers (void *) are prefixed with and underscore.
 */

#include <stdarg.h>
#include <assert.h>

#if ! defined (MANY) || MANY < 1
#define MANY 10
#endif


static int heap [MANY];

void * new (const void * type, ...) {
	int * p;    /* & heap[1..] */

	for (p = heap + 1; p < heap + MANY; ++ p)
		if (! * p) break;

	assert(p < heap + MANY);
	
	* p = MANY;
	
	return p;
}

void delete (void * _item) {
	int * item = _item;

	if (item) {
		assert(item > heap && item < heap + MANY);
		* item = 0;
	}
}

void * add (void * _set, const void * _element) {
	int * set = _set;
	const int * element = _element;

	assert(set     > heap && set     < heap + MANY);
	assert(element > heap && element < heap + MANY);
	assert(* set == MANY);

	if (* element == MANY)
		* (int *) element = set - heap;
	else
		assert(* element == set - heap);

	return (void *) element;
}

void * find (const void * _set, const void * _element) {
	const int * set = _set;
	const int * element = _element;

	assert(set     > heap && set     < heap + MANY);
	assert(element > heap && element < heap + MANY);
	assert(* set == MANY);
	assert(* element);

	return * element == set - heap ? (void *) element : 0;
}

int contains (const void * _set, const void * _element) {
	return find (_set, _element) != 0;
}

void * drop (void * _set, const void * _element) {
	int * element = find(_set, _element);

	if (element)
		* element = MANY;
	
	return element;
}

/* Objects differ exactly when the array indicies representing them differ. */
int differ (const void * a, const void * b) {
	return a != b;
}

/* to keep our compiler happy */
const void * Set;
const void * Object;

/*
 *void * new (const void * type, ...) {
	int * p;     & heap[1..] 

	for (p = heap + 1; p < heap + MANY; ++ p)
		if (! * p) break;

	assert(p < heap + MANY);
	
	* p = MANY;
	
	return p;
}
*/

/*
int apply (const void * _set,
		int (* action) (void * object, va_list ap), ...) {
	va_list args;
	va_start(args, action);

	int * p;

	for (p = heap + 1; p < heap + MANY; ++ p) {
		if (! action((void *) p, args)) break;
	}

	va_end(args);

	assert(p < heap + MANY);

	return 
*/

