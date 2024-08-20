#ifndef CNUM_H
#define CNUM_H

#include "utils.h"
#include "Rnum.h"

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)
#include <arm_neon.h> // SSE2

typedef struct Cnum
{
    Rnum *re;
    Rnum *im;
} Cnum;

Cnum *Cinit(Rnum *re, Rnum *im); // TODO finish
Cnum *Cclone(Cnum *orig);
void Cfree(Cnum *self);
void Cprintx(Cnum *self);

uint8_t Cequal(Cnum *self, Cnum *other);
uint8_t Cnotequal(Cnum *self, Cnum *other);
uint8_t Cgreater(Cnum *self, Cnum *other);
uint8_t Clesser(Cnum *self, Cnum *other);
uint8_t Cgreaterorequal(Cnum *self, Cnum *other);
uint8_t Clesserorequal(Cnum *self, Cnum *other);

void Caddto(Cnum *self, Cnum *addend);
void Csubto(Cnum *self, Cnum *subtrahend);
void Cmulto(Cnum *self, Cnum *factor);
void Cdivto(Cnum *self, Cnum *divisor);
void Cdivto(Cnum *self, Cnum *divisor);

#endif
