#include "_num.h"

/*
_num wrapNnum(uintmax_t u)
{
    _num newNnum;
    newNnum.type = 'N';
    Nnum newNnumData = initNnum(u);
    newNnum.data = &newNnumData;
    return newNnum;
}

_num copy_num(_num n)
{
    _num new_num;
    switch (new_num.type = n.type)
    {
    case 'N':
        // Nnum newNnum = copyNnum(*(Nnum *)n.data);
        // new_num.data = &newNnum;
        break;
    case 'Z':
        // Znum newZnum = copyZnum(*(Znum *)n.data);
        // new_num.data = &newZnum;
        break;
    case 'Q':
        // Qnum newQnum = copyQnum(*(Qnum *)n.data);
        // new_num.data = &newQnum;
        break;
    case 'R':
        // Rnum newRnum = copyRnum(*(Rnum *)n.data);
        // new_num.data = &newRnum;
        break;
    case 'C':
        // Cnum newCnum = copyCnum(*(Cnum *)n.data);
        // new_num.data = &newCnum;
        break;
    default:
        new_num.data = NULL;
    }
    return new_num;
}

void free_num(_num n)
{
    switch (n.type)
    {
    case 'N':
        freeNnum(*(Nnum *)n.data);
        break;
    case 'Z':
        // freeZnum(*(Znum *)n.data);
        break;
    case 'Q':
        // freeQnum(*(Qnum *)n.data);
        break;
    case 'R':
        // freeRnum(*(Rnum *)n.data);
        break;
    case 'C':
        // freeCnum(*(Cnum *)n.data);
        break;
    }
}

void print_num(_num n)
{
    switch (n.type)
    {
    case 'N':
        printNnum(*(Nnum *)n.data);
        break;
    case 'Z':
        // printZnum(*(Znum *)n.data);
        break;
    case 'Q':
        // printQnum(*(Qnum *)n.data);
        break;
    case 'R':
        // printRnum(*(Rnum *)n.data);
        break;
    case 'C':
        // printCnum(*(Cnum *)n.data);
        break;
    }
}

*/
