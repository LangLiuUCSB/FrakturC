#include "Znum.h"

#define help printf("helpZnum\n")

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)

Znum *Zinit(intmax_t jd) //* questionable need for SIMD support
{
    if (jd == INTMAX_MIN)
    {
        perror("Error: Zinit(-2147483648) is not allowed");
        exit(EXIT_FAILURE);
    }
    Znum *newZnum = malloc(sizeof(Znum)); // alloc Nnum
    if (!newZnum)
    {
        perror("Error: memory allocation for new Znum failed");
        exit(EXIT_FAILURE);
    }
    if (jd & INTMAX_MIN) // negative integer
    {
        // reformat
        jd--;
        jd = ~jd;
        // init .size and alloc .bytes
        uint8_t size = 0;
        for (uintmax_t i = jd << 1; i; i >>= 8)
            ++size;
        newZnum->b8 = (uint8_t *)malloc(newZnum->size = size);
        // init bytes
        uint8_t i = 0;
        for (; jd; jd >>= 8)
            newZnum->b8[i++] = jd & 0xFF;
        if (newZnum->b8[size - 1])
            newZnum->b8[size - 1] ^= 0x80;
        else
            newZnum->b8[size - 1] = 0x80;
    }
    else // positive integer
    {
        // init .size and alloc .bytes
        uint8_t size = 0;
        for (uintmax_t i = jd << 1; i; i >>= 8)
            ++size;
        newZnum->b8 = (uint8_t *)malloc(newZnum->size = size);
        // init bytes
        for (uint8_t i = 0; i < size; ++i, jd >>= 8)
            newZnum->b8[i] = jd & 0xFF;
    }
    return newZnum;
}

Znum *Zclone(Znum *orig) // TODO improve: support SIMD
{
    if (!orig) // original existence check
        return NULL;
    Znum *copyZnum = malloc(sizeof(Znum)); // alloc Nnum
    if (!copyZnum)
    {
        perror("Error: memory allocation for new Znum failed");
        exit(EXIT_FAILURE);
    }
    // init .size and alloc .bytes
    copyZnum->b8 = (uint8_t *)malloc(copyZnum->size = orig->size);
    // init bytes
    for (uint8_t i = 0; i < orig->size; ++i)
        copyZnum->b8[i] = orig->b8[i];
    return copyZnum;
}

void Zfree(Znum *self)
{
    if (self)
    {
        if (self->b8)
        {
            free(self->b8);
            self->b8 = NULL;
        }
        free(self);
        self = NULL;
    }
}

void Zprintx(Znum *self)
{
    switch (self->size & 7)
    {
    case 0:
        printf("0x");
        break;
    case 1:
        printf("0x%x",
               self->b8[self->size - 1]);
        break;
    case 2:
        printf("0x%x",
               self->b16[(self->size >> 1) - 1]);
        break;
    case 3:
        printf("0x%x%x",
               self->b8[self->size - 1],
               self->b16[(self->size >> 1) - 1]);
        break;
    case 4:
        printf("0x%x",
               self->b32[(self->size >> 2) - 1]);
        break;
    case 5:
        printf("0x%x%x",
               self->b8[self->size - 1],
               self->b32[(self->size >> 2) - 1]);
        break;
    case 6:
        printf("0x%x%x",
               self->b16[(self->size >> 1) - 1],
               self->b32[(self->size >> 2) - 1]);
        break;
    case 7:
        printf("0x%x%x%x",
               self->b8[self->size - 1],
               self->b16[(self->size >> 1) - 1],
               self->b32[(self->size >> 2) - 1]);
        break;
    }
    for (size_t i = (self->size >> 3) - 1; i != SIZE_MAX; --i)
        printf("%lx", self->b64[i]);
    printf("\n");
}

uint8_t Zequal(Znum *self, Znum *other)
{
    if (self->size != other->size)
        return 0;
    for (size_t i = (self->size >> 3) - 1; i != SIZE_MAX; --i)
        if (self->b64[i] != other->b64[i])
            return 0;
    switch (self->size & 7)
    {
    case 0:
        return 1;
    case 1:
        return self->b8[self->size - 1] == other->b8[self->size - 1];
    case 2:
        return self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1];
    case 3:
        return self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1] &&
               self->b8[self->size - 1] == other->b8[self->size - 1];
    case 4:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1];
    case 5:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1] &&
               self->b8[self->size - 1] == other->b8[self->size - 1];
    case 6:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1] &&
               self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1];
    case 7:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1] &&
               self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1] &&
               self->b8[self->size - 1] == other->b8[self->size - 1];
    }
    perror("Error: Zequal failed");
    exit(EXIT_FAILURE);
    return 0;
}

uint8_t Znotequal(Znum *self, Znum *other)
{
    if (self->size != other->size)
        return 1;
    for (size_t i = (self->size >> 3) - 1; i != SIZE_MAX; --i)
        if (self->b64[i] != other->b64[i])
            return 1;
    switch (self->size & 7)
    {
    case 0:
        return 0;
    case 1:
        return self->b8[self->size - 1] != other->b8[self->size - 1];
    case 2:
        return self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1];
    case 3:
        return self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1] ||
               self->b8[self->size - 1] != other->b8[self->size - 1];
    case 4:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1];
    case 5:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1] ||
               self->b8[self->size - 1] != other->b8[self->size - 1];
    case 6:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1] ||
               self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1];
    case 7:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1] ||
               self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1] ||
               self->b8[self->size - 1] != other->b8[self->size - 1];
    }
    perror("Error: Znotequal failed");
    exit(EXIT_FAILURE);
    return 0;
}

uint8_t Zgreater(Znum *self, Znum *other) // TODO finish
{
    printf("Unfinished: uint8_t Zgreater(Znum *self, Znum *other)\n");
    (void)self, (void)other;
    return 0;
}

uint8_t Zlesser(Znum *self, Znum *other) // TODO finish
{
    printf("Unfinished: uint8_t Zlesser(Znum *self, Znum *other)\n");
    (void)self, (void)other;
    return 0;
}

uint8_t Zgreaterorequal(Znum *self, Znum *other) // TODO finish
{
    printf("Unfinished: uint8_t Zgreaterorequal(Znum *self, Znum *other)\n");
    (void)self, (void)other;
    return 0;
}

uint8_t ZlesserorequalNnum(Znum *self, Znum *other) // TODO finish
{
    printf("Unfinished: uint8_t ZlesserorequalNnum(Znum *self, Znum *other)\n");
    (void)self, (void)other;
    return 0;
}

void Zaddto(Znum *self, Znum *addend) // TODO finish
{
    printf("Unfinished: void Zaddto(Znum *self, Znum *addend)\n");
    (void)self, (void)addend;
    // addition
}

void Zsubto(Znum *self, Znum *subtrahend) // TODO finish
{
    printf("Unfinished: void Zsubto(Znum *self, Znum *subtrahend)\n");
    (void)self, (void)subtrahend;
    // subtraction
}

void Zmulto(Znum *self, Znum *factor) // TODO finish
{
    printf("Unfinished: void Zmulto(Znum *self, Znum *factor)\n");
    (void)self, (void)factor;
    // multiplication
}

void Zdivto(Znum *self, Znum *divisor) // TODO finish
{
    printf("Unfinished: void Zdivto(Znum *self, Znum *divisor)\n");
    (void)self, (void)divisor;
    // division
}

void Zmodto(Znum *self, Znum *divisor) // TODO finish
{
    printf("Unfinished: void Zmodto(Znum *self, Znum *divisor)\n");
    (void)self, (void)divisor;
    // modulus
}
