#include <stdio.h>
#include <setjmp.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#include "parse.h"
#include "value.h"


static void * sum (void);
static void * product (void);
static void * factor (void);

static enum tokens token;        /* current input symbol */

static jmp_buf onError;

static double number;            /* if NUMBER: numerical value */

static enum tokens scan (const char * buf) {        /* return token = next input symbol */
    static const char * bp;

    if (buf)
        bp = buf;        /* new input line */

    while (isspace(* bp))
        ++ bp;

    if (isdigit(* bp) || * bp == '.') {
        errno = 0;
        token = NUMBER, number = strtod(bp, (char **) & bp);

        if (errno == ERANGE)
            error("bad value: %s", strerror(errno));
    }
    else {
        token = * bp ? * bp ++ : 0;
    }

    return token;
}

static void * sum (void) {
    void * result = product();

    const void * type;

    for (;;) {
        switch (token) {
            case '+':
                type = Add;
                break;

            case '-':
                type = Sub;
                break;

            default:
                return result;
        }
        scan(0);
        result = new(type, result, product());
    }
}

static void * product (void) {        /* EXPERIMENTAL */
    void * result = factor();

    const void * type;

    for (;;) {
        switch (token) {
            case '*':
                type = Mul;
                break;

            default:
                return result;
        }
        scan(0);
        result = new(type, result, factor());        /* not sure about the last arg */
    }
}

static void * factor (void) {
    void * result;

    switch (token) {
        case '+':
            scan(0);
            return factor();

        case '-':
            scan(0);
            return new(Minus, factor());

        default:
            error("bad factor: '%c' 0x%x", token, token);

        case NUMBER:
            result = new(Value, number);
            break;

        case '(':
            scan(0);
            result = sum();
            if (token != ')') error("expecting ')'");
    }
    scan(0);
    return result;
}

int main (void) {
    volatile int errors = 0;
    char buf [BUFSIZ];

    if (setjmp(onError))
        ++ errors;

    /* while (gets(buf)) */
    while (fgets(buf, BUFSIZ, stdin))
        if (scan(buf)) {
            void * e = sum();

            if (token)
                error("trash after sum");

            process(e);
            delete(e);
        }

    return errors > 0;
}

void error (const char * fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap), putc('\n', stderr);
    va_end(ap);
    
    longjmp(onError, 1);
}

