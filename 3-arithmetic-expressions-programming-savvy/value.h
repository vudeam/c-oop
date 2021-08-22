#ifndef VALUE_H
#define VALUE_H


extern const void * Add;
extern const void * Sub;
extern const void * Mul;
extern const void * Value;        /* numerical value */
extern const void * Minus;        /* unary minus */
/*
 * more TODO
 */

void * new (const void * type, ...);

void process (const void * tree);

void delete (void * tree);


#endif        /* VALUE_H */

