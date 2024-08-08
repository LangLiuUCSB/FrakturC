#ifndef _NUM_H
#define _NUM_H

#include "Nnum.h"

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

_num wrapNnum(uintmax_t ju);
_num copy_num(_num n);

void free_num(_num n);
void print_num(_num n);

#endif
