#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "utils.h"
#include "Nnum.h"

int main(void)
{
    Nnum *n1 = initNnum(0x11111111);
    print_num((_num *)n1);

    free_num((_num *)n1);

    return 0;
}
