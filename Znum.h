#ifndef ZNUM_H
#define ZNUM_H

#include "utils.h"

typedef struct Znum
{
    uint8_t *bytes;
    size_t size;
} Znum;

Znum *initZnum(intmax_t jd);
Znum *cloneZnum(Znum *orig);

void freeZnum(Znum *self);
void printbZnum(Znum *self);

uint8_t isEqualZnum(Znum *self, Znum *other);

void addtoZnums(Znum *self, Znum *addend);
void subtoZnums(Znum *self, Znum *subtrahend);
void multoZnums(Znum *self, Znum *factor);

#endif
