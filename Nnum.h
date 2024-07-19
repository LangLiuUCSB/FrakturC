#ifndef NNUM_H
#define NNUM_H

#include "utils.h"

typedef struct Nnum
{
    uint8_t *bytes;
    size_t size;
} Nnum;

Nnum *initNnum(uintmax_t ju);
Nnum *cloneNnum(Nnum *orig);

void freeNnum(Nnum *self);
void printbNnum(Nnum *self);

uint8_t isEqualNnum(Nnum *self, Nnum *other);

void addtoNnums(Nnum *self, Nnum *addend);
void subtoNnums(Nnum *self, Nnum *subtrahend);
void multoNnums(Nnum *self, Nnum *factor);

#endif
