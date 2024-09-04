#ifndef NNUM_H
#define NNUM_H

#include "utils.h"

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)
#include <arm_neon.h> // SSE2

typedef struct Nnum
{
    union
    {
        uint8_t *b8;
        uint16_t *b16;
        uint32_t *b32;
        uint64_t *b64;
        uint64x2_t *b64x2;
    };
    size_t size;
} Nnum;

Nnum *Ninit(uintmax_t ju);
Nnum *Nclone(Nnum *orig);
void Nfree(Nnum *self);
void Nprintx(Nnum *self);

uint8_t Nequal(Nnum *self, Nnum *other);
uint8_t Nnotequal(Nnum *self, Nnum *other);
uint8_t Ngreater(Nnum *self, Nnum *other);
uint8_t Nlesser(Nnum *self, Nnum *other);
uint8_t Ngreaterorequal(Nnum *self, Nnum *other);
uint8_t Nlesserorequal(Nnum *self, Nnum *other);

void Naddto(Nnum *self, Nnum *addend);

void Nsubto(Nnum *self, Nnum *subtrahend);
void Nmulto(Nnum *self, Nnum *factor);
void Ndivto(Nnum *self, Nnum *divisor);
void Ndivto(Nnum *self, Nnum *divisor);

#endif
