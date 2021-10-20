#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <malloc.h>
#include <assert.h>

#include "Object.r"
#include "Object.h"


/**
 * "public" definitions
 */

const void * classOf (const void * _self) {
    const struct Object * self = _self;

    assert(self && self -> class);
    return self -> class;
}

size_t sizeOf (const void * _self) {
    const struct Class * class = classOf(_self);

    return class -> size;
}


/**
 * Object-specific definitions
 */

static void * Object_ctor (void * _self, va_list * app) {
    return _self;
}

static void * Object_dtor (void * _self) {
    return _self;
}

static int Object_differ (const void * _self, const void * _other) {
    return _self == _other;        /* like that ? */
}

static int Object_puto (const void * _self, FILE * fp) {
    const struct Class * class = classOf(_self);

    return fprintf(fp, "%s at %p\n", class -> name, _self);
}

