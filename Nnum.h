#ifndef NNUM_H
#define NNUM_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nnum
{
    uint8_t *bytes;
    size_t size;
} Nnum;

Nnum *initNnum(uintmax_t ju);
Nnum *copyNnum(Nnum *orig);

void freeNnum(Nnum *self);
void printNnum(Nnum *self);

// void addtoNnums(Nnum *self, Nnum *addend);

#endif
