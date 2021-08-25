#ifndef POINT_R
#define POINT_R

/**
 * accessors for x and y coordinates
 * can be applied to a pointer to any object
 * that starts with a struct Point
 */
#define x(p)    (((const struct Point *)(p)) -> x)
#define y(p)    (((const struct Point *)(p)) -> y)

/**
 * setters
 */
#define set_x(p,v)    (((struct Point *)(p)) -> x = (v))
#define set_y(p,v)    (((struct Point *)(p)) -> y = (v))

/**
 * declaration of Point
 */
struct Point {
    const void * class;
    int x, y;                  /* coordinates */
};


#endif

