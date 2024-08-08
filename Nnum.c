#include "Nnum.h"

#define help printf("help\n")

Nnum *initNnum(uintmax_t ju)
{
    Nnum *newNnum = malloc(sizeof(Nnum)); // alloc Nnum
    if (!newNnum)                         // alloc fail check
        return NULL;

    // init .size and alloc .bytes
    uint8_t size = 0;
    for (uintmax_t i = ju; i | 0; i >>= 8)
        size++;
    newNnum->bytes = (uint8_t *)malloc(newNnum->size = size);

    // init bytes
    for (uint8_t i = 0; i < size; i++, ju >>= 8)
        newNnum->bytes[i] = ju & 0xFF;

    return newNnum;
}

Nnum *copyNnum(Nnum *orig)
{
    if (!orig) // original existence check
        return NULL;
    Nnum *copy = malloc(orig->size);    // alloc Nnum
    if (copy)                           // alloc Nnum success check
        memcpy(copy, orig, orig->size); // copy memory
    return copy;
}

void freeNnum(Nnum *self)
{
    free(self->bytes);
    free(self);
}

void printNnum(Nnum *self)
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
    for (uint8_t noLeadingZero = 0; j < UINT8_MAX; j--)
        if (noLeadingZero || (noLeadingZero = (self->bytes[i] >> j) & 0x01))
            printf("%u", (self->bytes[i] >> j) & 0x01);
    i--;
    // print other bytes
    for (; i < SIZE_MAX; i--)
        for (printf(","), j = 7; j < UINT8_MAX; j--)
            printf("%u", (self->bytes[i] >> j) & 0x01);
    printf("\n");
}

/*
void addtoNnums(Nnum self, Nnum addend)
{
    if (self.size < addend.size)
    {
        self.bytes = realloc(self.bytes, (self.size = addend.size));
    }
    uint8_t carry = 0;
    for (size_t i = 0; i < addend.size; ++i)
    {
        carry = (self.bytes[i] += addend.bytes[i] + carry) < addend.bytes[i];
    }
    if (carry)
        (self.bytes = (uint8_t *)realloc(self.bytes, ++self.size))[self.size - 1] = 1;
}
*/
