#ifndef POINT_H
#define POINT_H


extern const void * Point;        /* new(Point, x, y); */

struct Point {
    const void * class;
    int x, y;                  /* coordinates */
};

void move (void * point, int dx, int dy);


#endif        /* POINT_H */

