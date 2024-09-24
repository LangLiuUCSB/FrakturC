#include "utils.h"
#include "_num.h"


#define help printf("help\n")
#define ln printf("\n")

int main(void)
{
            _num *n1 = wrapNnum(UINTMAX_MAX);
            printx_num(n1);
            ln;
            print_size(n1);
            ln;

            _num *n2 = wrapNnum(UINTMAX_MAX);
            printx_num(n2);
            ln;
            print_size(n2);
            ln;

            subto_num(n1, n2);
            printx_num(n1);
            ln;
            print_size(n1);
            ln;

            free_num(n1);
            free_num(n2);

    ln;
    return EXIT_SUCCESS;
}
