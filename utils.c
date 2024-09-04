#include "utils.h"

size_t bytes_alloc_max(void)
{
    size_t size = 1;
    uint8_t *largeArray = (uint8_t *)malloc(size);
    if (!largeArray)
        return 0;
    for (; largeArray; largeArray = (uint8_t *)malloc(size *= 2))
        free(largeArray);
    for (size_t extra = (size /= 2); extra;)
    {
        if ((largeArray = (uint8_t *)malloc(size += (extra >>= 1))))
            free(largeArray);
        else
            size -= extra;
    }
    return size;
}

uint64_t fibonnaci(size_t n)
{
    if (!n)
        return 0;

    if (n < 3)
        return 1;

    uint64_t fib1 = 1;
    uint64_t fib2 = 1;
    uint64_t fib3 = fib1 + fib2;
    for (size_t i = 3; i < n; ++i)
    {
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }
    return fib3;
}
