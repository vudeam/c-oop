#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include "new.h"
#include "Object.h"
#include "Set.h"
#include "list.h"
#include "apply.h"


int print_node (void * node, va_list ap);

int main(void) {
	void * s = new(Set);
	void * a = add(s, new(Object));
	void * b = add(s, new(Object));
	void * c = new(Object);

	apply (s, print_node);

	if (contains(s, a) && contains(s, b))
		puts("ok");

	if (contains(s, c))
		puts("contains?");

	if (differ(a, add(s, a)))
			puts("differ?");
	
	if (contains(s, drop(s, a)))
		puts("drop?");

	delete(drop(s, b));
	delete(drop(s, c));

	puts("\n");

	return 0;
}

int print_node (void * _node, va_list ap) {
	struct Node * element = _node;

	printf ("ELEMENT:%p\tDATA:%p\tNEXT:%p\n",
			    (void *) element,
					(void *) element -> data,
					(void *) element -> next);

	return 1;
}

