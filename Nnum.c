#include "Nnum.h"

_num *initNnum(uintmax_t n)
{
    // alloc for wrapper
    _num *new_num = (_num *)malloc(sizeof(_num));

    // init type char
    new_num->type = 'N';

    // alloc for data
    Nnum *newNnum = (Nnum *)malloc(sizeof(Nnum));

    // alloc for array of num in data
    uint8_t size = 0;
    for (uintmax_t i = n; i | 0; i >>= 8) // calc byte size of num
        size++;
    newNnum->arr8 = (uint8_t *)malloc(newNnum->size = size);

    // init array of num in data
    for (uint8_t i = 0; i < size; i++, n >>= 8)
        newNnum->arr8[i] = n & 0xFF;

    // init data void pointer
    new_num->data = newNnum;

    // init method pointers
    new_num->free_num = free_num;
    new_num->print_num = print_num;
    new_num->addto = addto;
    new_num->subto = subto;
    new_num->multo = multo;
    new_num->fdivto = fdivto;
    new_num->modto = modto;

    return new_num;
}

void free_num(_num *self)
{
    if (self)
    {
        free(((Nnum *)(self->data))->arr8);
        free(self->data);
        free(self);
    }
}

void print_num(_num *self)
{
    if (self)
    {
        Nnum *data = (Nnum *)(self->data);
        printf("0b");
        for (size_t i = 0; i < data->size; i++)
            printf("%02X", data->arr8[i]);
        printf("\n");
    }
}

void addto(_num *self, _num *addend)
{
    if (self || addend)
        ;
}

void subto(_num *self, _num *subtrahend)
{
    if (self || subtrahend)
        ;
}

void multo(_num *self, _num *factor)
{
    if (self || factor)
        ;
}

void fdivto(_num *self, _num *divisor)
{
    if (self || divisor)
        ;
}

void modto(_num *self, _num *divisor)
{
    if (self || divisor)
        ;
}
