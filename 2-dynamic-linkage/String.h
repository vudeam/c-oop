#ifndef STRING_H
#define STRING_H


/**
 * Declaration of String.
 *
 */
struct String {
	const void * class;        /* must be first */
	char *       text;
};

extern const void * String;


#endif    /* STRING_H */

