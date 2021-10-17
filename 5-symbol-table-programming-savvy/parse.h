#ifndef PARSE_H
#define PARSE_H

#define ALNUM    "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
                 "abcdefghijklmnopqrstuvwxyz" \
                 "_" "0123456789"


enum tokens {
    NUMBER    = 1,
    VAR,
    CONST,
    LET,
    PLUS      = '+',
    MINUS     = '-',
    MULTIPLY  = '*',
    BRACKET_O = '(',
    BRACKET_C = ')'
};

void error (const char * fmt, ...);


#endif        /* PARSE_H */

