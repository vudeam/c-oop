#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include "new.r"
#include "new.h"
#include "Point.r"
#include "Point.h"


void move (void * _self, int dx, int dy) {
    struct Point * self = _self;

    set_x(self, x(self) + dx);
    set_y(self, y(self) + dy);
}

static void * Point_ctor (void * _self, va_list * app) {
    struct Point * self = _self;

    set_x(self, va_arg(* app, int));
    set_y(self, va_arg(* app, int));

    return self;
}

static void Point_draw (const void * _self) {
    const struct Point * self = _self;

    printf("\".\" at %d,%d\n",
            x(self),
            y(self));
}


/**
 * create Point descriptor
 */
static const struct Class _Point = {
    sizeof(struct Point),
    & Point_ctor,
    0,
    & Point_draw
};

const void * Point = & _Point;

