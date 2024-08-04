#ifndef NNUM_H
#define NNUM_H

#include "_num.h"
#include <arm_neon.h>

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

_num *initNnum(uintmax_t u);
void free_num(_num *self);
void print_num(_num *self);
void addto(_num *self, _num *addend);
void subto(_num *self, _num *subtrahend);
void multo(_num *self, _num *factor);
void fdivto(_num *self, _num *divisor);
void modto(_num *self, _num *divisor);

#endif
