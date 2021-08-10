#ifndef ATOM_H
#define ATOM_H


/**
 * Declaration of Atom.
 *
 * An Atom is a unique string object;
 * if two atoms contain the same string, they are identical.
 */
struct String {
    const void *    class;        /* must be first */
    char *          text;
    struct String * next;
    unsigned        count;
};

extern const void * String;


#endif    /* ATOM_H */

