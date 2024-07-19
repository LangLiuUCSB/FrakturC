#include "_num.h"

_num *wrapNnum(uintmax_t ju)
{
    _num *newNnum = malloc(sizeof(_num));
    newNnum->type = 'N';
    newNnum->data = initNnum(ju);
    return newNnum;
}

_num *wrapZnum(intmax_t jd)
{
    _num *newNnum = malloc(sizeof(_num));
    newNnum->type = 'Z';
    newNnum->data = initZnum(jd);
    return newNnum;
}

_num *clone_num(_num *orig)
{
    _num *new_num = malloc(sizeof(_num));
    if (!new_num)
        return NULL;
    switch (new_num->type = orig->type)
    {
    case 'N':
        new_num->data = cloneNnum((Nnum *)orig->data);
        return new_num;
    case 'Z':
        new_num->data = cloneZnum((Znum *)orig->data);
        return new_num;
    case 'Q':
        // new_num->data = cloneQnum((Qnum *)orig->data);
        return new_num;
    case 'R':
        // new_num->data = cloneRnum((Rnum *)orig->data);
        return new_num;
    case 'C':
        // new_num->data = cloneCnum((Cnum *)orig->data);
        return new_num;
    }
    return NULL;
}

void free_num(_num *self)
{
    switch (self->type)
    {
    case 'N':
        freeNnum((Nnum *)self->data);
        break;
    case 'Z':
        freeZnum((Znum *)self->data);
        break;
    case 'Q':
        // freeQnum((Qnum *)self->data);
        break;
    case 'R':
        // freeRnum((Rnum *)self->data);
        break;
    case 'C':
        // freeCnum((Cnum *)self->data);
        break;
    }
    free(self);
}

void printb_num(_num *self)
{
    switch (self->type)
    {
    case 'N':
        printbNnum((Nnum *)self->data);
        return;
    case 'Z':
        printbZnum((Znum *)self->data);
        return;
    case 'Q':
        // printbQnum((Qnum *)self->data);
        return;
    case 'R':
        // printbRnum((Rnum *)self->data);
        return;
    case 'C':
        // printbCnum((Cnum *)self->data);
        return;
    }
}
