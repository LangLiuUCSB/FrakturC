#include "Znum.h"

#define help printf("helpZnum\n")

Znum *initZnum(intmax_t jd)
{
    if (jd == INTMAX_MIN)
    {
        fprintf(stderr, "Error: Znum not allowed to be initialized to -2147483648\n");
        exit(1);
    }

    Znum *newZnum = malloc(sizeof(Znum)); // alloc Nnum

    if (!newZnum) // alloc fail check
        return NULL;

    if (jd & INTMAX_MIN) // negative integer
    {
        // reformat
        --jd;
        jd ^= -1l;

        // init .size and alloc .bytes
        uint8_t size = 0;
        for (uintmax_t i = jd << 1; i; i >>= 8)
            ++size;
        newZnum->bytes = (uint8_t *)malloc(newZnum->size = size);

        // init bytes
        uint8_t i = 0;
        for (; jd; jd >>= 8)
            newZnum->bytes[i++] = jd & 0xFF;
        if (newZnum->bytes[size - 1])
            newZnum->bytes[size - 1] ^= 0x80;
        else
            newZnum->bytes[size - 1] = 0x80;
    }
    else
    {
        // init .size and alloc .bytes
        uint8_t size = 0;
        for (uintmax_t i = jd << 1; i; i >>= 8)
            ++size;
        newZnum->bytes = (uint8_t *)malloc(newZnum->size = size);

        // init bytes
        for (uint8_t i = 0; i < size; ++i, jd >>= 8)
            newZnum->bytes[i] = jd & 0xFF;
    }

    return newZnum;
}

Znum *cloneZnum(Znum *orig)
{
    if (!orig) // original existence check
        return NULL;
    Znum *copyZnum = malloc(sizeof(Znum)); // alloc Nnum

    if (!copyZnum) // alloc fail check
        return NULL;

    copyZnum->bytes = (uint8_t *)malloc(copyZnum->size = orig->size); // init .size and alloc .bytes

    for (uint8_t i = 0; i < orig->size; ++i) // init bytes
        copyZnum->bytes[i] = orig->bytes[i];

    return copyZnum;
}

void freeZnum(Znum *self)
{
    free(self->bytes);
    free(self);
}

void printbZnum(Znum *self)
{
    printf("0b");
    if (!self->size) // .size greater than zero
    {
        printf("0\n");
        return;
    }
    size_t i = self->size - 1;
    uint8_t j = 7;
    // print most significant byte
    for (uint8_t noLeadingZero = 0; j < UINT8_MAX; --j)
        if (noLeadingZero || (noLeadingZero = (self->bytes[i] >> j) & 0x01))
            printf("%u", (self->bytes[i] >> j) & 0x01);
    // print other bytes
    for (--i; i != SIZE_MAX; --i)
        for (printf(","), j = 7; j < UINT8_MAX; --j)
            printf("%u", (self->bytes[i] >> j) & 0x01);
    printf("\n");
}

uint8_t isEqualZnum(Znum *self, Znum *other)
{
    if (self->size != other->size)
        return 0;
    for (size_t i = self->size - 1; i != SIZE_MAX; --i)
        if (self->bytes[i] != other->bytes[i])
            return 0;
    return 1;
}

void addtoZnums(Znum *self, Znum *addend)
{
    printf("Unfinished: void addtoZnums(Znum *self, Znum *addend)\n");
    (void)self, (void)addend;
    // addition
}
