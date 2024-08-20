#ifndef ZNUM_H
#define ZNUM_H

#include "utils.h"

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)
#include <arm_neon.h> // SSE2

typedef struct Znum
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
} Znum;

Znum *Zinit(intmax_t jd);
Znum *Zclone(Znum *orig);
void Zfree(Znum *self);
void Zprintx(Znum *self);

uint8_t Zequal(Znum *self, Znum *other);
uint8_t Znotequal(Znum *self, Znum *other);
uint8_t Zgreater(Znum *self, Znum *other);
uint8_t Zlesser(Znum *self, Znum *other);
uint8_t Zgreaterorequal(Znum *self, Znum *other);
uint8_t Zlesserorequal(Znum *self, Znum *other);

void Zaddto(Znum *self, Znum *addend);
void Zsubto(Znum *self, Znum *subtrahend);
void Zmulto(Znum *self, Znum *factor);
void Zdivto(Znum *self, Znum *divisor);
void Zdivto(Znum *self, Znum *divisor);

#endif
