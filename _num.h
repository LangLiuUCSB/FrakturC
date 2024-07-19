#ifndef _NUM_H
#define _NUM_H

#include "Nnum.h"
#include "Znum.h"

typedef struct _num
{
    char type;
    void *data;
    // void (*addto)(struct _num *self, struct _num *addend);
    // void (*subto)(struct _num *self, struct _num *subtrahend);
    // void (*multo)(struct _num *self, struct _num *factor);
    // void (*fdivto)(struct _num *self, struct _num *divisor);
    // void (*modto)(struct _num *self, struct _num *divisor);
} _num;

_num *wrapNnum(uintmax_t ju);
_num *wrapZnum(intmax_t jd);

_num *clone_num(_num *orig);

void free_num(_num *self);
void printb_num(_num *self);

#endif
