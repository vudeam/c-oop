#include <stdarg.h>
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

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

