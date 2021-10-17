#ifndef SET_H
#define SET_H


extern const void * Set;

/**
 * add element to the set
 * returns added element (NULL means some error)
 */
void * add (void * set, const void * element);

/**
 * look for an element and return whatever is present in the set
 * or NULL
 */
void * find (const void * set, const void * element);

/**
 * locate element, remove it from the set and return the removed DATA (not element)
 */
void * drop (void * set, const void * element);

/**
 * convert the result of find() into a truth value
 */
int contains (const void * set, const void * element);


#endif /* SET_H */

