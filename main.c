#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "utils.h"
#include "Nnum.h"

int main(void)
{
    Nnum *n1 = initNnum(69);
    Nnum *n2 = initNnum(420);
    Nnum *n3 = initNnum(69 + 420);

    printNnum(n1);
    printNnum(n2);
    printNnum(n3);

    printf("%zuhelp\n", n1->size);

    // Nnum sum = addNnums(n1, n2);
    // printNnum(sum);

    freeNnum(n1);
    freeNnum(n2);
    freeNnum(n3);

    return 0;
}
