#ifndef OBJECT_H
#define OBJECT_H

#include <stddef.h>
#include <stdio.h>


extern const void * Class;     /* new(Class, "name", super, size, sel, meth, ... 0); */
extern const void * Object;    /* new(Object); */

void *       new     (const void * class, ...);
void         delete  (void * self);

const void * classOf (const void * self);
size_t       sizeOf  (const void * self);

int          differ  (const void * self, const void * other);
int          puto    (const void * self, FILE * fp);


#endif        /* OBJECT_H */

