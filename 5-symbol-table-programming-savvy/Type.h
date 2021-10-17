#ifndef TYPE_H
#define TYPE_H

#include <stdarg.h>

#include "Name.r"

#define funct(tree)    (((struct Math *) left(tree)) -> funct)


struct Type {
    const char * name;
    void *       (* new)    (va_list ap);
    double       (* exec)   (const void * tree);
    void         (* delete) (void * tree);
};

struct Bin {
    const void * type;
    void * left, * right;
};

struct Unr {            /* represents unary operation */
    const void * type;
    void * arg;
};

struct Val {
    const void * type;
    double value;
};

struct Math {
    struct Name _;
    double (* funct) (double);
};

#endif        /* TYPE_H */

