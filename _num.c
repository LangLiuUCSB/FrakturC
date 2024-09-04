#include "_num.h"

_num *wrapNnum(uintmax_t ju)
{
    _num *newNnum = malloc(sizeof(_num));
    newNnum->numType = 'N';
    newNnum->data = Ninit(ju);
    return newNnum;
}

_num *wrapZnum(intmax_t jd)
{
    _num *newZnum = malloc(sizeof(_num));
    newZnum->numType = 'Z';
    newZnum->data = Zinit(jd);
    return newZnum;
}

_num *clone_num(_num *orig) // TODO finish
{
    _num *copy_num = malloc(sizeof(_num));
    if (!copy_num)
        return NULL;
    switch (copy_num->numType = orig->numType)
    {
    case 'N':
        copy_num->data = Nclone((Nnum *)orig->data);
        return copy_num;
    case 'Z':
        copy_num->data = Zclone((Znum *)orig->data);
        return copy_num;
    case 'Q':
        // copy_num->data = Qclone((Qnum *)orig->data);
        return copy_num;
    case 'R':
        // copy_num->data = Rclone((Rnum *)orig->data);
        return copy_num;
    case 'C':
        // copy_num->data = Cclone((Cnum *)orig->data);
        return copy_num;
    }
    return NULL;
}

void free_num(_num *self) // TODO finish
{
    switch (self->numType)
    {
    case 'N':
        Nfree((Nnum *)self->data);
        break;
    case 'Z':
        Zfree((Znum *)self->data);
        break;
    case 'Q':
        // Qfree((Qnum *)self->data);
        break;
    case 'R':
        // Rfree((Rnum *)self->data);
        break;
    case 'C':
        // Cfree((Cnum *)self->data);
        break;
    }
    free(self);
}

void printx_num(_num *self) // TODO finish
{
    switch (self->numType)
    {
    case 'N':
        Nprintx((Nnum *)self->data);
        return;
    case 'Z':
        Zprintx((Znum *)self->data);
        return;
    case 'Q':
        // Qprintx((Qnum *)self->data);
        return;
    case 'R':
        // Rprintx((Rnum *)self->data);
        return;
    case 'C':
        // Cprintbx((Cnum *)self->data);
        return;
    }
}

void addto_num(_num *self, _num *other) // TODO finish
{
    if (self->numType == 'N' && other->numType == 'N')
    {
        Naddto((Nnum *)self->data, (Nnum *)other->data);
        return;
    }
}

void print_size(_num *self)
{
    switch (self->numType)
    {
    case 'N':
        printf("Nsize: %zu", ((Nnum *)self->data)->size);
        return;
    case 'Z':
        printf("Zsize: %zu", ((Znum *)self->data)->size);
        return;
    case 'Q':
        // numerator size and denominator size
        return;
    case 'R':
        // size of AST
        return;
    case 'C':
        // size of real AST and imaginary AST
        return;
    }
}
