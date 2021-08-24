#include <malloc.h>
#include <stdarg.h>
#include <assert.h>

#include "new.r"
#include "new.h"


void * new (const void * _class, ...) {
    const struct Class * class = _class;

    void * item = calloc(1, class -> size);
    assert(item);

    * (const struct Class **) item = class;
    
    if (class -> ctor) {
        va_list ap;

        va_start(ap, _class);
        item = class -> ctor(item, & ap);
        va_end(ap);
    }

    return item;
}

void delete (void * _self) {
    const struct Class ** cp = _self;

    if (_self && * cp && (* cp) -> dtor) {
        _self = (* cp) -> dtor(_self);
    }

    free(_self);
}

void draw (const void * self) {
    const struct Class * const * cp = self;
    assert(self && * cp && (* cp) -> draw);

    (* cp) -> draw(self);
}

