#include <stdarg.h>
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

#include "Name.h"
#include "Var.r"
#include "Var.h"
#include "Type.h"
#include "parse.h"


static void * mkVar (va_list ap) {
    struct Var * node = calloc(1, sizeof(struct Var));
    const char * name = va_arg(ap, const char *);
    size_t len = strlen(name);

    assert(node);
    node -> _.name = malloc(len + 1);
    assert(node -> _.name);

    strcpy((void *) node -> _.name, name);
    node -> _.token = VAR;

    return node;
}

static double doVar (const void * tree) {
    return value(tree);
}

static void freeVar (void * tree) { }


static struct Type _Var = {
    "",
    & mkVar,
    & doVar,
    & freeVar
};

const void * Var = & _Var;

void initConst (void) {
    static const struct Var constants [] = {    /* like hoc */
        { & _Var, "PI",    CONST, 3.14159265358979323846 },
        /**
         * more TODO
         */
        0
    };

    const struct Var * vp;

    for (vp = constants; vp -> _.name; vp ++)
        install(vp);
}

