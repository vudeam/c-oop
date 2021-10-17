#ifndef APPLY_H
#define APPLY_H

#include <stdarg.h>

/**
 * Calls action() for each element in set and passes the rest of the argument list.
 * The action() must not chaange set but it may return zero (0) to terminate apply() early.
 *
 * apply() returns true if all elements were processed.
 */


int apply (const void * set,
		       int (* action) (void * object, va_list ap),
					 ...);


#endif /* APPLY_H */

