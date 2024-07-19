#include "Nnum.h"

#define help printf("helpNnum\n")

Nnum *initNnum(uintmax_t ju)
{
    Nnum *newNnum = malloc(sizeof(Nnum)); // alloc Nnum

    if (!newNnum) // alloc fail check
        return NULL;

    // init .size and alloc .bytes
    uint8_t size = 0;
    for (uintmax_t i = ju; i; i >>= 8)
        ++size;
    newNnum->bytes = (uint8_t *)malloc(newNnum->size = size);

    // init bytes
    for (uint8_t i = 0; ju; ju >>= 8)
        newNnum->bytes[i++] = ju & 0xFF;

    return newNnum;
}

Nnum *cloneNnum(Nnum *orig)
{
    if (!orig) // original existence check
        return NULL;
    Nnum *copyNnum = malloc(sizeof(Nnum)); // alloc Nnum

    if (!copyNnum) // alloc fail check
        return NULL;

    copyNnum->bytes = (uint8_t *)malloc(copyNnum->size = orig->size); // init .size and alloc .bytes

    for (uint8_t i = 0; i < orig->size; ++i) // init bytes
        copyNnum->bytes[i] = orig->bytes[i];

    return copyNnum;
}

void freeNnum(Nnum *self)
{
    free(self->bytes);
    free(self);
}

void printbNnum(Nnum *self)
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

uint8_t isEqualNnum(Nnum *self, Nnum *other)
{
    if (self->size != other->size)
        return 0;
    for (size_t i = self->size - 1; i != SIZE_MAX; --i)
        if (self->bytes[i] != other->bytes[i])
            return 0;
    return 1;
}

void addtoNnums(Nnum *self, Nnum *addend)
{
    if (self->size < addend->size) // preop resize check
        self->bytes = realloc(self->bytes, (self->size = addend->size));

    // addition
    uint8_t carry = 0;
    for (size_t i = 0; i < addend->size; ++i)
        carry = (self->bytes[i] += addend->bytes[i] + carry) < addend->bytes[i];

    if (carry) // postop resize check
        (self->bytes = (uint8_t *)realloc(self->bytes, ++self->size))[self->size - 1] = 1;
}

void subtoNnums(Nnum *self, Nnum *subtrahend)
{
    if (self->size < subtrahend->size) // preop negative check
    {
        fprintf(stderr, "Error: Nnum cannot store difference values lesser than zero\n");
        exit(1);
    }

    // subtraction
    uint8_t borrow = 0;
    size_t i = 0;
    for (uint8_t currbyte; i < subtrahend->size; ++i)
        borrow = (currbyte = self->bytes[i]) < (self->bytes[i] -= subtrahend->bytes[i] + borrow);
    while (borrow && i < self->size)
        borrow = --self->bytes[i++] == 0xFF;

    if (borrow) // postop negative check
    {
        fprintf(stderr, "Error: Nnum cannot store difference values lesser than zero\n");
        exit(1);
    }

    // resize away empty bytes
    size_t empties = 0;
    for (--i; !self->bytes[i] && i < SIZE_MAX; --i)
        ++empties;
    self->bytes = (uint8_t *)realloc(self->bytes, self->size -= empties);
}

void multoNnums(Nnum *self, Nnum *factor)
{
    if (!factor->size) // zero factor check
    {
        self->bytes = (uint8_t *)realloc(self->bytes, self->size -= 0);
        return;
    }

    // preop resize check

    // multiplication

    // postop resize check
}
