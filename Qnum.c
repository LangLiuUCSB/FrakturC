#include "Qnum.h"

#define help printf("helpQnum\n")

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)

Qnum *Qinit(long double lf) // TODO finish
{
    printf("Unfinished: Qnum *Qinit(long double lf)\n");
    (void)lf;
    // initialization
    return NULL;
}

Qnum *Qclone(Qnum *orig) // TODO finish
{
    printf("Unfinished: Qnum *Qclone(Qnum *orig)\n");
    (void)orig;
    // duplication
    return NULL;
}

void Qfree(Qnum *self) // TODO finish
{
    printf("Unfinished: void Qfree(Qnum *self)\n");
    (void)self;
    // deallocation
}

void Qprintx(Qnum *self) // TODO finish
{
    printf("Unfinished: void Qprintx(Qnum *self)\n");
    (void)self;
    // debugger print
}

uint8_t Qequal(Qnum *self, Qnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Qequal(Qnum *self, Qnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Qnotequal(Qnum *self, Qnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Qnotequal(Qnum *self, Qnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Qgreater(Qnum *self, Qnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Qgreater(Qnum *self, Qnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Qlesser(Qnum *self, Qnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Qlesser(Qnum *self, Qnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Qgreaterorequal(Qnum *self, Qnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Qgreaterorequal(Qnum *self, Qnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Qlesserorequal(Qnum *self, Qnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Qlesserorequal(Qnum *self, Qnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

void Qaddto(Qnum *self, Qnum *addend) // TODO finish
{
    printf("Unfinished: void Qaddto(Qnum *self, Qnum *addend)\n");
    (void)self, (void)addend;
    // addition
}

void Qsubto(Qnum *self, Qnum *subtrahend) // TODO finish
{
    printf("Unfinished: void Qsubto(Qnum *self, Qnum *subtrahend)\n");
    (void)self, (void)subtrahend;
    // subtraction
}

void Qmulto(Qnum *self, Qnum *factor) // TODO finish
{
    printf("Unfinished: void Qmulto(Qnum *self, Qnum *factor)\n");
    (void)self, (void)factor;
    // multiplication
}

void Qdivto(Qnum *self, Qnum *divisor) // TODO finish
{
    printf("Unfinished: void Qdivto(Qnum *self, Qnum *divisor)\n");
    (void)self, (void)divisor;
    // division
}

void Qmodto(Qnum *self, Qnum *divisor) // TODO finish
{
    printf("Unfinished: void Qdivto(Qnum *self, Qnum *divisor)\n");
    (void)self, (void)divisor;
    // modulus
}
