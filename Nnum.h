#ifndef NNUM_H
#define NNUM_H

#include "utils.h"

#if defined(_x86_64) || defined(_M_X64) || defined(i386) || defined(MIX86)
#include <immintrin.h>
#elif defined(ARM_NEON) || defined(__aarch64__)
#include <arm_neon.h>
#endif

typedef struct Nnum
{
    union
    {
        uint8_t *b8;
        uint16_t *b16;
        uint32_t *b32;
        uint64_t *b64;
#if defined(_x86_64) || defined(_M_X64) || defined(i386) || defined(MIX86)
        __m128i
#elif defined(ARM_NEON) || defined(__aarch64__)
        uint64x2_t
#endif
            *b64x2;
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
