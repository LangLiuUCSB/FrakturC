#include "utils.h"
#include "_num.h"

#define help printf("help\n")

int main(void)
{

    /*
    Znum *n1;
    for (intmax_t jd = INTMAX_MIN + 1; jd; jd /= 2)
    {
        n1 = initZnum(jd);

        printf("%jd\n", jd);
        printbZnum(n1);
        printf("size: %zu\n", n1->size);

        freeZnum(n1);
    }

    */
    _num *n1 = wrapNnum(UINTMAX_MAX);
    Nprintx(((Nnum *)n1->data));

    _num *n2 = wrapNnum(UINTMAX_MAX);
    Nprintx(((Nnum *)n2->data));

    addto_num(n1, n2);
    Nprintx(((Nnum *)n1->data));
    printf("size: %zx\n\n", ((Nnum *)n1->data)->size);

    free_num(n1);
    free_num(n2);

    /*
    for (size_t i = 0; i < 15; ++i)
    {
        printf("%zx\n", b8x[i]);
    }
    */

    return EXIT_SUCCESS;
}
