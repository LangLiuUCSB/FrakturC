#include "Rnum.h"

#define help printf("helpRnum\n")

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)

Rnum *Rinit(char *form) // TODO finish
{
    printf("Unfinished: Rnum *Rinit(long double lf)\n");
    (void)form;
    // initialization
    return NULL;
}

Rnum *Rclone(Rnum *orig) // TODO finish
{
    printf("Unfinished: Rnum *Rclone(Rnum *orig)\n");
    (void)orig;
    // duplication
    return NULL;
}

void Rfree(Rnum *self) // TODO finish
{
    printf("Unfinished: void Rfree(Rnum *self)\n");
    (void)self;
    // deallocation
}

void Rprintx(Rnum *self) // TODO finish
{
    printf("Unfinished: void Rprintx(Rnum *self)\n");
    (void)self;
    // debugger print
}

uint8_t Requal(Rnum *self, Rnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Requal(Rnum *self, Rnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Rnotequal(Rnum *self, Rnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Rnotequal(Rnum *self, Rnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Rgreater(Rnum *self, Rnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Rgreater(Rnum *self, Rnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Rlesser(Rnum *self, Rnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Rlesser(Rnum *self, Rnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Rgreaterorequal(Rnum *self, Rnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Rgreaterorequal(Rnum *self, Rnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

uint8_t Rlesserorequal(Rnum *self, Rnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Rlesserorequal(Rnum *self, Rnum *other)\n");
    (void)self, (void)other;
    // comparation
    return 0;
}

void Raddto(Rnum *self, Rnum *addend) // TODO finish
{
    printf("Unfinished: void Raddto(Rnum *self, Rnum *addend)\n");
    (void)self, (void)addend;
    // addition
}

void Rsubto(Rnum *self, Rnum *subtrahend) // TODO finish
{
    printf("Unfinished: void Rsubto(Rnum *self, Rnum *subtrahend)\n");
    (void)self, (void)subtrahend;
    // subtraction
}

void Rmulto(Rnum *self, Rnum *factor) // TODO finish
{
    printf("Unfinished: void Rmulto(Rnum *self, Rnum *factor)\n");
    (void)self, (void)factor;
    // multiplication
}

void Rdivto(Rnum *self, Rnum *divisor) // TODO finish
{
    printf("Unfinished: void Rdivto(Rnum *self, Rnum *divisor)\n");
    (void)self, (void)divisor;
    // division
}

void Rmodto(Rnum *self, Rnum *divisor) // TODO finish
{
    printf("Unfinished: void Rdivto(Rnum *self, Rnum *divisor)\n");
    (void)self, (void)divisor;
    // modulus
}
