#include "Cnum.h"

#define help printf("helpCnum\n")

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)

Cnum *Cinit(Rnum *re, Rnum *im) // TODO finish
{
    printf("Unfinished: Cnum *Cinit(long double lf)\n");
    (void)re, (void)im;
    // initialization
    return NULL;
}

Cnum *Cclone(Cnum *orig) // TODO finish
{
    printf("Unfinished: Cnum *Cclone(Cnum *orig)\n");
    (void)orig;
    // duplication
    return NULL;
}

void Cfree(Cnum *self) // TODO finish
{
    printf("Unfinished: void Cfree(Cnum *self)\n");
    (void)self;
    // deallocation
}

void Cprintx(Cnum *self) // TODO finish
{
    printf("Unfinished: void Cprintx(Cnum *self)\n");
    (void)self;
    // debugger print
}

uint8_t Cequal(Cnum *self, Cnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Cequal(Cnum *self, Cnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Cnotequal(Cnum *self, Cnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Cnotequal(Cnum *self, Cnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Cgreater(Cnum *self, Cnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Cgreater(Cnum *self, Cnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Clesser(Cnum *self, Cnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Clesser(Cnum *self, Cnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Cgreaterorequal(Cnum *self, Cnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Cgreaterorequal(Cnum *self, Cnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Clesserorequal(Cnum *self, Cnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Clesserorequal(Cnum *self, Cnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

void Caddto(Cnum *self, Cnum *addend) // TODO finish
{
    printf("Unfinished: void Caddto(Cnum *self, Cnum *addend)\n");
    (void)self, (void)addend;
    // addition
}

void Csubto(Cnum *self, Cnum *subtrahend) // TODO finish
{
    printf("Unfinished: void Csubto(Cnum *self, Cnum *subtrahend)\n");
    (void)self, (void)subtrahend;
    // subtraction
}

void Cmulto(Cnum *self, Cnum *factor) // TODO finish
{
    printf("Unfinished: void Cmulto(Cnum *self, Cnum *factor)\n");
    (void)self, (void)factor;
    // multiplication
}

void Cdivto(Cnum *self, Cnum *divisor) // TODO finish
{
    printf("Unfinished: void Cdivto(Cnum *self, Cnum *divisor)\n");
    (void)self, (void)divisor;
    // division
}

void Cmodto(Cnum *self, Cnum *divisor) // TODO finish
{
    printf("Unfinished: void Cdivto(Cnum *self, Cnum *divisor)\n");
    (void)self, (void)divisor;
    // modulus
}
