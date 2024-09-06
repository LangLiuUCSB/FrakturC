#ifndef RNUM_H
#define RNUM_H

#include "utils.h"
#include "MAST.h"

typedef struct Rnum
{
    MASTnode *exprRoot;
} Rnum;

Rnum *Rinit(char *form); // TODO finish
Rnum *Rclone(Rnum *orig);
void Rfree(Rnum *self);
void Rprintx(Rnum *self);

uint8_t Requal(Rnum *self, Rnum *other);
uint8_t Rnotequal(Rnum *self, Rnum *other);
uint8_t Rgreater(Rnum *self, Rnum *other);
uint8_t Rlesser(Rnum *self, Rnum *other);
uint8_t Rgreaterorequal(Rnum *self, Rnum *other);
uint8_t Rlesserorequal(Rnum *self, Rnum *other);

void Raddto(Rnum *self, Rnum *addend);
void Rsubto(Rnum *self, Rnum *subtrahend);
void Rmulto(Rnum *self, Rnum *factor);
void Rdivto(Rnum *self, Rnum *divisor);
void Rdivto(Rnum *self, Rnum *divisor);

#endif
