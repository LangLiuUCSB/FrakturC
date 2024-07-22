#include "Nnum.h"

Nnum *initNnum(uintmax_t n)
{
    Nnum *newNnum = (Nnum *)malloc(sizeof(Nnum));
    uint8_t size = 0;
    for (uintmax_t i = n; i | 0; i >>= 8)
        size++;
    newNnum->arr8 = (uint8_t *)malloc(newNnum->size = size);
    for (uint8_t i = 0; i < size; i++, n >>= 8)
        newNnum->arr8[i] = n & 0xFF;
    newNnum->operators.free_num = free_num;
    newNnum->operators.print_num = print_num;
    return newNnum;
}

void free_num(_num *self)
{
    if (self)
    {
        free(((Nnum *)self)->arr8);
        free(self);
    }
}

void print_num(_num *self)
{
    if (self)
    {
        Nnum *num = (Nnum *)self;
        printf("0b");
        for (size_t i = 0; i < num->size; i++)
            printf("%02X", num->arr8[i]);
        printf("\n");
    }
}
