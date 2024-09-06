#ifndef _NUM_H
#define _NUM_H

#include "Nnum.h"
#include "Znum.h"
#include "Qnum.h"
#include "Rnum.h"
#include "Cnum.h"

typedef struct _num
{
    char numType;
    void *data;
} _num;


_num *wrapNnum(uintmax_t ju);
_num *wrapZnum(intmax_t jd);
_num *clone_num(_num *orig);
void free_num(_num *self);
void printx_num(_num *self);

uint8_t equal_num(Nnum *self, Nnum *other);
uint8_t notequal_num(Nnum *self, Nnum *other);
uint8_t greater_num(Nnum *self, Nnum *other);
uint8_t lesser_num(Nnum *self, Nnum *other);
uint8_t greaterorequal_num(Nnum *self, Nnum *other);
uint8_t lesserorequal_num(Nnum *self, Nnum *other);

void addto_num(_num *self, _num *addend);
void subto_num(_num *self, _num *subtrahend);
void multo_num(_num *self, _num *factor);
void divto_num(_num *self, _num *divisor);
void modto_num(_num *self, _num *divisor);

void print_size(_num *self);

#endif
