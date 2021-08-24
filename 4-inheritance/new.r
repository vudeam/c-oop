#ifndef CLASS_H
#define CLASS_H

#include <stddef.h>
#include <stdarg.h>


/**
 * Declaration of Class.
 *
 * PRIVATE DEFINITION HEADER
 *
 * It contains:
 *
 * - size:   The length that new() allocates for an object.
 *
 * - ctor:   Points to the constructor called by new() which recieves
 *           the allcated memory and the rest of the argument list
 *           passed to new() originally.
 *
 * - dtor:   Points to the destructor called by delete() which recieves
 *           the object to be destroyed.
 *
 * - clone:  Points to a copy functions which recieves
 *           the object to be copied.
 *
 * - differ: Points to a function which compares its object
 *           to smth else.
 */
struct Class {
    size_t        size;
    void *        (* ctor) (void * self, va_list * app);
    void *        (* dtor) (void * self);
    void          (* draw) (const void * self);
};


#endif        /* CLASS_H */

