#ifndef _NUM_H
#define _NUM_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _num
{
    char type;
    void *data;
    void (*free_num)(struct _num *self);
    void (*print_num)(struct _num *self);
    void (*addto)(struct _num *self, struct _num *addend);
    void (*subto)(struct _num *self, struct _num *subtrahend);
    void (*multo)(struct _num *self, struct _num *factor);
    void (*fdivto)(struct _num *self, struct _num *divisor);
    void (*modto)(struct _num *self, struct _num *divisor);
} _num;

void free_num(_num *self);

void print_num(_num *self);

_num *add(_num *AN1, _num *AN2);
void addto(_num *self, _num *addend);

_num *sub(_num *AN1, _num *AN2);
void subto(_num *self, _num *subtrahend);

_num *mul(_num *AN1, _num *AN2);
void multo(_num *self, _num *factor);

_num *fdiv(_num *AN1, _num *AN2);
void fdivto(_num *self, _num *divisor);

_num *mod(_num *AN1, _num *AN2);
void modto(_num *self, _num *divisor);

#endif
