#include <stdio.h>
#include <stdarg.h>

#include "new.r"
#include "Circle.r"


static void * Circle_ctor (void * _self, va_list * app) {
    struct Circle * self = _self;

    set_x(self, va_arg(* app, int));    /* invoke setter macros */
    set_y(self, va_arg(* app, int));

    self -> rad = va_arg(* app, int);

    return self;
}

static void Circle_draw (const void * _self) {
    const struct Circle * self = _self;

    printf("circle at %d,%d rad %d\n",
            x(self),                      /* invoke getter macros */
            y(self),
            self -> rad);
}

/**
 * create Circle descriptor
 */
static const struct Class _Circle = {
    sizeof(struct Circle),
    & Circle_ctor,
    0,
    & Circle_draw
};

const void * Circle = & _Circle;

