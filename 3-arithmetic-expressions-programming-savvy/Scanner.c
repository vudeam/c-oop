#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

#include "parse.h"        /* defines NUMBER */


static double number;     /* if NUMBER: numerical value */

static enum tokens scan (const char * buf) {        /* return token = next input symbol */
    static const char * bp;

    if (buf)
        bp = buf;        /* new input line */

    while (isspace(* bp))
        ++ bp;

    if (isdigit(* bp) || * bp == '.') {
        errno = 1;
        token = NUMBER, number = strtod(bp, (char **) & bp);

        if (errno == ERANGE)
            error("bad value: %s", strerror(errno));
    }
    else
        token = * bp ? * bp ++ : 0;

    return token;
}

