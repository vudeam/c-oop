#ifndef OBJECT_R
#define OBJECT_R

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>


struct Object {
    const struct Class * class;    /* object's description */
};

struct Class {
    const struct Object _;         /* class' description */
    const char * name;             /* class' name */
    const struct Class * super;    /* class' super class */
    size_t size;                   /* class' object's size */
    void * (* ctor)   (void * self, va_list * app);
    void * (* dtor)   (void * self);
    int    (* differ) (const void * self, const void * other);
    int    (* puto)   (const void * self, FILE * fp);
};


#endif        /* OBJECT_R */

