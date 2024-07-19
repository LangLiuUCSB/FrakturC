#include "utils.h"
#include "_num.h"

#define help printf("help\n")

int main(void)
{

    /*
    for (intmax_t jd = INTMAX_MIN + 1; jd; jd /= 2)
    {
        Znum *n1 = initZnum(jd);

        printf("%jd\n", jd);
        printbZnum(n1);
        printf("size: %zu\n", n1->size);

        freeZnum(n1);
    }

    */
    _num *n1 = wrapZnum(-72057594037927935);

    printf("%jd\n", -72057594037927935);
    printb_num(n1);
    printf("size: %zu\n", ((Znum *)n1->data)->size);
    printf("bytes[7]: %x\n", ((Znum *)n1->data)->bytes[7]);

    free_num(n1);

    return 0;
}
