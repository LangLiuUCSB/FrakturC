#ifndef NNUM_H
#define NNUM_H

#include "_num.h"

#if defined(__ARM_NEON) || defined(__aarch64__)
#include <arm_neon.h> // SSE2

typedef struct Nnum
{
    union
    {
        uint8_t *arr8;
        uint16_t *arr16;
        uint32_t *arr32;
        uint64_t *arr64;
        uint8x16_t *arr8x16;
    };
    size_t size;
    _num operators;
} Nnum;

Nnum *initNnum(uintmax_t u);
void free_num(_num *self);

void print_num(_num *self);

_num *Nadd(_num *AN1, _num *AN2);
void Naddto(_num *self, _num *addend);

_num *Nsub(_num *AN1, _num *AN2);
void Nsubto(_num *self, _num *subtrahend);

_num *Nmul(_num *AN1, _num *AN2);
void Nmulto(_num *self, _num *factor);

_num *Nfdiv(_num *AN1, _num *AN2);
void Nfdivto(_num *self, _num *divisor);

_num *Nmod(_num *AN1, _num *AN2);
void Nmodto(_num *self, _num *divisor);

#else
#error "Unsupported architecture. This program requires SSE2 or NEON support."
#endif

#endif
