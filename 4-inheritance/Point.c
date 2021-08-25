#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include "new.r"
#include "Point.r"


void move (void * _self, int dx, int dy) {
    struct Point * self = _self;

    self -> x += dx, self -> y += dy;
}

static void * Point_ctor (void * _self, va_list * app) {
    struct Point * self = _self;

    self -> x = va_arg(* app, int);
    self -> y = va_arg(* app, int);

    return self;
}

static void Point_draw (const void * _self) {
    const struct Point * self = _self;

    printf("\".\" at %d,%d\n",
            self -> x,
            self -> y);
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

