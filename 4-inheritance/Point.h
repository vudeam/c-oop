#ifndef POINT_H
#define POINT_H


extern const void * Point;        /* new(Point, x, y); */
extern const void * Circle;       /* new(Circle, x, y, rad); */

void move (void * point, int dx, int dy);


#endif        /* POINT_H */

