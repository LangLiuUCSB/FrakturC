#include "utils.h"

size_t bytes_alloc_max(void)
{
    size_t size = 1;
    uint8_t *temp = (uint8_t *)malloc(size);
    if (!temp)
        return 0;
    for (; temp; temp = (uint8_t *)malloc(size *= 2))
        free(temp);
    for (size_t extra = (size /= 2); extra;)
    {
        if ((temp = (uint8_t *)malloc(size += (extra >>= 1))))
            free(temp);
        else
            size -= extra;
    }
    return size;
}
