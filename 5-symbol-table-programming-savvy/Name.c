#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

#include "Name.r"
#include "Name.h"
#include "parse.h"

#define NAMES    8UL    /* initial allotment of Names table entries */


static void initNames (void) {
    static const struct Name names [] = {
        { 0, "let", LET },
        0
    };

    const struct Name * np;
    for (np = names; np -> name; np ++) install(np);
}

void * binary (const void * key,
               void *       _base,
               size_t *     nelp,
               size_t       width,
               int          (* cmp) (const void * key, const void * elt)) {

    size_t nel = * nelp;
#   define base    (* (char **) & _base)
    char * lim = base + nel * width;
    char * high;

    if (nel > 0) {
        for (high = lim - width; base <= high; nel >>= 1) {
            char * mid = base + (nel >> 1) * width;
            int c = cmp(key, mid);

            if (c < 0)
                high = mid - width;
            else if (c > 0)
                base = mid + width, --nel;
            else
                return (void *) mid;
        }
        /**
         * at this point we either found a table element and returned its address,
         * or base is now the address where key should be in the table
         */
        memmove(base + width, base, lim - base);
    }
    ++ * nelp;

    return memcpy(base, key, width);
#   undef base
}

static int cmp (const void * _key, const void * _elt) {    /* compare a key to a Name table element */
    const char *        const * key = _key;
    const struct Name * const * elt = _elt;

    return strcmp(* key, (* elt) -> name);
}

static struct Name ** search (const char ** name) {
    static const struct Name ** names;    /* dynamic table */
    static size_t used, max;

    if (used >= max) {
        names = names
            ? realloc(names, (max *= 2) * sizeof(* names))    /* NOLINT - clang-tidy goes crazy about sizeof() */
            : malloc((max = NAMES) * sizeof(* names));        /* NOLINT - clang-tidy goes crazy about sizeof() */
        assert(names);
    }

    return binary(name, names, & used, sizeof(* names), & cmp); /* NOLINT - clang-tidy goes crazy about sizeof() */
}

/**
 * looks for the input symbol to be screened.
 * if the pointer to the text of the symbol is entered in the symbol table,
 * we need to replace it by an entry describing the new identidier
 */
int screen (const char * name) {
    struct Name ** pp = search(& name);

    if (* pp == (void *) name)    /* entered name */
        * pp = new(Var, name);

    symbol = * pp;

    return (* pp) -> token;
}

/**
 * accept Name and let serach() find it in the symbol table.
 * install() is supposed to deal only with new symbols,
 * so we should always be able to enter the object in place of its name.
 * otherwise, if search() really finds the symbol, we are in trouble
 */
void install (const void * np) {
    const char * name = ((struct Name *) np) -> name;
    struct Name ** pp = search(& name);

    if (* pp != (void *) name) error("can not install name twice: %s", name);

    * pp = (struct Name *) np;
}

