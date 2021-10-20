#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>


extern const void * Class;     /* new(Class, "name", super, size, sel, meth, ... 0); */
extern const void * Object;    /* new(Object); */

void *       new     (const void * class, ...);
void         delete  (void * self);

const void * classOf (const void * self);
size_t       sizeOf  (const void * self);

void *       ctor    (void * self, va_list * app);
void *       dtor    (void * self);
int          differ  (const void * self, const void * other);
int          puto    (const void * self, FILE * fp);

const void * super   (const void * self);


#endif        /* OBJECT_H */

