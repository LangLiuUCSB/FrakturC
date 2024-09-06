#ifndef QNUM_H
#define QNUM_H

#include "utils.h"
#include "Nnum.h"
#include "Znum.h"

typedef struct Qnum
{
    Znum *numerator;
    Nnum *denomitor;
} Qnum;

Qnum *Qinit(long double lf); // TODO finish
Qnum *Qclone(Qnum *orig);
void Qfree(Qnum *self);
void Qprintx(Qnum *self);

uint8_t Qequal(Qnum *self, Qnum *other);
uint8_t Qnotequal(Qnum *self, Qnum *other);
uint8_t Qgreater(Qnum *self, Qnum *other);
uint8_t Qlesser(Qnum *self, Qnum *other);
uint8_t Qgreaterorequal(Qnum *self, Qnum *other);
uint8_t Qlesserorequal(Qnum *self, Qnum *other);

void Qaddto(Qnum *self, Qnum *addend);
void Qsubto(Qnum *self, Qnum *subtrahend);
void Qmulto(Qnum *self, Qnum *factor);
void Qdivto(Qnum *self, Qnum *divisor);
void Qdivto(Qnum *self, Qnum *divisor);

#endif
