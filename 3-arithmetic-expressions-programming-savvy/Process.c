#include <stdarg.h>
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

#include "value.h"
#include "Type.h"


/**************************************
 * value.h - ctor, dtor and process()
 *************************************/

void * new (const void * type, ...) {
    va_list ap;
    void * result;

    assert(type && ((struct Type *) type) -> new);

    va_start(ap, type);
    result = ((struct Type *) type) -> new(ap);
    * (const struct Type **) result = type;
    va_end(ap);

    return result;
}

static double exec (const void * tree) {
    return (* (struct Type **) tree) -> exec(tree);
}

void process (const void * tree) {
    printf("\t%g\n", exec(tree));
}

void delete (void * tree) {
    assert(tree && * (struct Type **) tree
            && (* (struct Type **) tree) -> delete);
    (* (struct Type **) tree) -> delete(tree);
}

/****************************************************************************/


/*************************************************************
 * struct Bin - binary operations (new(), exec() and delete()
 ************************************************************/

static void * mkBin (va_list ap) {
    struct Bin * node = malloc(sizeof(struct Bin));

    assert(node);

    node -> left  = va_arg(ap, void *);
    node -> right = va_arg(ap, void *);

    return node;
}

static void freeBin (void * tree) {
    delete(((struct Bin *) tree) -> left);
    delete(((struct Bin *) tree) -> right);
    free(tree);
}

/*
static void doBin (const void * tree) {
    exec(((struct Bin*) tree) -> left);
    exec(((struct Bin*) tree) -> right);
    printf(" %s", (* (struct Type **) tree) -> name);
}
*/

static double doAdd (const void * tree) {
    return exec(((struct Bin *) tree) -> left) +
        exec(((struct Bin *) tree) -> left);
}

static double doSub (const void * tree) {
    return exec(((struct Bin *) tree) -> left) -
        exec(((struct Bin *) tree) -> left);
}

static double doMul (const void * tree) {
    return exec(((struct Bin *) tree) -> left) *
        exec(((struct Bin *) tree) -> left);
}

/**
 * create binop descriptors
 */
static struct Type _Add = { "+", & mkBin, & doAdd, & freeBin };
static struct Type _Sub = { "-", & mkBin, & doSub, & freeBin };
static struct Type _Mul = { "*", & mkBin, & doMul, & freeBin };

const void * Add = & _Add;
const void * Sub = & _Sub;
const void * Mul = & _Mul;

/****************************************************************************/


/*******************************
 * struct Val - numerical value
 *******************************/

static void * mkVal (va_list ap) {
    struct Val * node = malloc(sizeof(struct Val));

    assert(node);

    node -> value = va_arg(ap, double);

    return node;
}

static double doVal (const void * tree) {
    /* printf(" %g", ((struct Val *) tree) -> value); */
    return ((struct Val *) tree) -> value;
}

static double doMns (const void * tree) {
    return -1 * ((struct Val *) tree) -> value;
}

/**
 * create value descriptors
 */
static struct Type _Value = { "", & mkVal, & doVal, & free };
static struct Type _Minus = { "", & mkVal, & doMns, & free };

const void * Value = & _Value;
const void * Minus = & _Minus;

/****************************************************************************/
 
