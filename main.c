#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "utils.h"
#include "Nnum.h"

int main(void)
{
    _num *n1 = initNnum(0x11111111);
    n1->print_num(n1);

    n1->free_num(n1);

    return 0;
}
