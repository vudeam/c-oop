#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "Atom.h"
#include "new.h"
#include "new.r"        /* private header which defined struct Class */


/************************
 * new.h stuff goes here
 ***********************/

void * new (const void * _class, ...) {
	const struct Class * class = _class;

	void * p = calloc (1, class -> size);
	assert (p);

	* (const struct Class **) p = class;        /* p now points to the beginning */
	                                            /* of the new memory area of the object */
	
	if (class -> ctor) {                        /* if a constructor part of the type description, */
		va_list ap;                               /* call it and return its result as the result of new() */

		va_start (ap, _class);
		p = class -> ctor (p, & ap);
		va_end (ap);
	}

	return p;
}

void delete (void * self) {
	const struct Class ** cp = self;

	if (self && * cp && (* cp) -> dtor)
		self = (* cp) -> dtor (self);

	free (self);
}

void * clone (const void * self) {        /* experimental implementation (not presented in the book) */
	const struct Class * const * cp = self;

	if (self && * cp && (* cp) -> clone)
		return (* cp) -> clone (self);

	return 0;
}

int differ (const void * self, const void * b) {
	const struct Class * const * cp = self;

	assert (self && * cp && (* cp) -> differ);

	return (* cp) -> differ (self, b);
}

size_t sizeOf (const void * self) {
	const struct Class * const * cp = self;

	assert (self && * cp);

	return (* cp) -> size;
}


/**************************************************************************************/


/***************************
 * Atom.h stuff goes here
 **************************/

static struct String * ring;        /* all of strings */

static void * String_ctor (void * _self, va_list * app) {
    struct String * self = _self;
    const char * text = va_arg (* app, const char *);

    self -> text = malloc (strlen (text) + 1);
    assert (self -> text);
    strcpy (self -> text, text);

    if (ring) {
        struct String * p = ring;

        do
            if (strcmp (p -> text, text) == 0) {
                ++ p -> count;
                free (self);

                return p;
            }
        while ((p = p -> next) != ring);
    }
    else
        ring = self;

    self -> next = ring -> next, ring -> next = self;
    self -> count = 1;

    return self;
}

static void * String_dtor (void * _self) {
    struct String * self = (void *) _self;

    if (-- self -> count > 0)
        return 0;        /* if an object does not want to be deleted, it returns NULL */
    
    assert (ring);

    if (ring == self)
        ring = self -> next;
    
    if (ring == self)
        ring = 0;
    else {
        struct String * p = ring;

        while (p -> next != self) {
            p = p -> next;
            assert (p != ring);
        }
        p -> next = self -> next;
    }

    free (self -> text), self -> text = 0;

    return self;
}


static void * String_clone (const void * _self) {
    struct String * self = (void *) _self;

    ++ self -> count;

    return self;
}

static int String_differ (const void * _self, const void * _b) {
    return _self != _b;
}


/**************************************************************************************/

/**
 * The Atom descriptor itself
 */
static const struct Class _String = {
    sizeof (struct String),
    & String_ctor,
    & String_dtor,
    & String_clone,
    & String_differ
};

const void * String = & _String;

