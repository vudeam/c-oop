#ifndef PARSE_H
#define PARSE_H


enum tokens {
    NUMBER    = 1,
    PLUS      = '+',
    MINUS     = '-',
    MULTIPLY  = '*',
    BRACKET_O = '(',
    BRACKET_C = ')'
};

void error (const char * fmt, ...);


#endif        /* PARSE_H */

