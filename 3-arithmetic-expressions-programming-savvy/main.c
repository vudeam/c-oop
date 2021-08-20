#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>


static enum tokens token;        /* current input symbol */

static jmp_buf onError;

void error (const char * fmt, ...);

int main (void) {
    volatile int errors = 0;
    char buf [BUFSIZ];

    if (setjmp(onError))
        ++ errors;

    while (gets(buf))
        if (scan(buf)){
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

