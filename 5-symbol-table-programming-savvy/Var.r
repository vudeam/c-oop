#ifndef VAR_R
#define VAR_R

#include "Name.r"


/**
 * declaration of a subclass - Var
 */
struct Var {
    struct Name _;
    double value;
};

#define value(tree)    (((struct Var *) tree) -> value)    /* accessor */


#endif        /* VAR_R */

