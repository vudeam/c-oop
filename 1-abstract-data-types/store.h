#ifndef STORE_H
#define STORE_H

#include <stdio.h>
#include <stdarg.h>


/**
 * writes a description of an object to the file pointer
 *
 * returns number of characrets written
 */
int store (const void * object, FILE * fp);

/**
 * writes a description of an object to the file pointer extracted
 * from va_args
 *
 * returns number of characters written
 */
int storev (const void * object, va_list ap);


#endif /* STORE_H */

