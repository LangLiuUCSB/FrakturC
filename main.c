#include "utils.h"
#include "_num.h"

#define help printf("help\n")
#define ln printf("\n")

int main(void)
{
    int8_t num = -128;
    // lower limit is -128
    // upper limit is 127
    printf("%hhx", num);

    ln;
    return EXIT_SUCCESS;
}
