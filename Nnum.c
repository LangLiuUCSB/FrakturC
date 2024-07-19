#include "Nnum.h"

Nnum initNnum(uintmax_t n)
{
    Nnum newNnum;
    uint8_t size = 0;
    for (uintmax_t i = n; i | 0; i >>= 8)
        size++;
    newNnum.size = size;
    newNnum.bytes = (uint8_t *)malloc(size);
    for (uint8_t i = 0; i < size; i++, n >>= 8)
        newNnum.bytes[i] = n & 0xFF;
    return newNnum;
}

void printNnum(Nnum n)
{
    printf("0b");
    if (!n.size)
    {
        printf("0\n");
        return;
    }
    size_t i = n.size - 1;
    uint8_t j = 7;
    for (uint8_t noLeadingZero = 0; j < UINT8_MAX; j--)
        if (noLeadingZero || (noLeadingZero = (n.bytes[i] >> j) & 0x01))
            printf("%u", (n.bytes[i] >> j) & 0x01);
    i--;
    for (; i < SIZE_MAX; i--)
        for (printf(","), j = 7; j < UINT8_MAX; j--)
            printf("%u", (n.bytes[i] >> j) & 0x01);
    printf("\n");
}

Nnum copyNnum(Nnum n)
{
    Nnum newNnum;
    newNnum.size = n.size;
    newNnum.bytes = (uint8_t *)malloc(n.size);
    for (uint8_t i = 0; i < n.size; i++)
        newNnum.bytes[i] = n.bytes[i];
    return newNnum;
}

Nnum addNnums(Nnum n1, Nnum n2)
{
    Nnum sum;
    uint8_t carry = 0;
    if (n1.size > n2.size)
    {
        sum = copyNnum(n1);
        size_t i = 0;
        for (; i < n2.size; i++)
            carry = (sum.bytes[i] += n2.bytes[i] + carry) < n1.bytes[i];
        for (; i < n1.size; i++)
            if (carry)
                carry = !++sum.bytes[i];
    }
    else
    {
        sum = copyNnum(n2);
        size_t i = 0;
        for (; i < n1.size; i++)
            carry = (sum.bytes[i] += n1.bytes[i] + carry) < n2.bytes[i];
        for (; i < n2.size; i++)
            if (carry)
                carry = !++sum.bytes[i];
    }
    if (carry)
        (sum.bytes = (uint8_t *)realloc(sum.bytes, ++sum.size))[sum.size - 1] = 1;
    return sum;
}

Nnum subtractNnums(Nnum n1, Nnum n2)
{
    Nnum difference;
    uint8_t borrow = 0;
    if (n1.size > n2.size)
    {
        difference = copyNnum(n1);
        size_t i = 0;
        for (; i < n2.size; i++)
            borrow = (difference.bytes[i] -= n2.bytes[i] - borrow) > n1.bytes[i];
        for (; i < n1.size; i++)
            if (borrow)
                borrow = !--difference.bytes[i];
    }
    else
    {
        fprintf(stderr, "Error: Nnum cannot hold difference values lesser than zero\n");
        exit(1);
    }
    if (borrow)
        (difference.bytes = (uint8_t *)realloc(difference.bytes, --difference.size));
    return difference;
}

Nnum leftByteShiftNnum(Nnum n, size_t shiftPower)
{
    if (!shiftPower)
        return copyNnum(n);
    Nnum product;
    product.bytes = (uint8_t *)malloc((product.size = n.size + shiftPower));
    memset(product.bytes, 0x00, shiftPower);
    memcpy(product.bytes + shiftPower, n.bytes, n.size);
    return product;
}

Nnum rightByteShiftNnum(Nnum n, size_t shiftPower)
{
    if (!shiftPower)
        return copyNnum(n);
    Nnum quotient;
    quotient.bytes = (uint8_t *)malloc((quotient.size = n.size - shiftPower));
    memcpy(quotient.bytes, n.bytes + shiftPower, quotient.size);
    return quotient;
}

Nnum doubleNnum(Nnum n)
{
    Nnum product;
    if (n.bytes[n.size - 1] & 0x80)
        (product.bytes = (uint8_t *)malloc((product.size = n.size + 1)))[n.size] = 1;
    else
        product.bytes = (uint8_t *)malloc((product.size = n.size));
    product.bytes[0] = n.bytes[0] << 1;
    for (size_t i = 0; i < n.size; product.bytes[i] += n.bytes[i] << 1)
        if (n.bytes[i++] & 0x80)
            product.bytes[i] = 0x01;
    return product;
}

Nnum halfNnum(Nnum n)
{
    Nnum quotient;
    if (n.bytes[n.size - 1] >> 1)
        (quotient.bytes = (uint8_t *)malloc((quotient.size = n.size)))[n.size - 1] = n.bytes[n.size - 1] >> 1;
    else
        quotient.bytes = (uint8_t *)malloc((quotient.size = n.size - 1));
    for (size_t i = n.size - 1; i < SIZE_MAX; quotient.bytes[i] += n.bytes[i] >> 1)
        if (n.bytes[i--] & 0x01)
            quotient.bytes[i] = 0x80;
    return quotient;
}

Nnum leftBitShiftNnum(Nnum n, uint8_t shiftPower)
{
    if (!shiftPower)
        return copyNnum(n);
    if (shiftPower > 7)
    {
        fprintf(stderr, "Error: Cannot bitshift by more or equal number of bits than there are in a byte\n");
        exit(1);
    }
    uint8_t carryBits = 0x80 >> (shiftPower - 1);
    uint8_t carryPower = 8 - shiftPower;
    Nnum product;
    if (n.bytes[n.size - 1] & carryBits)
        (product.bytes = (uint8_t *)malloc((product.size = n.size + 1)))[n.size] = n.bytes[n.size - 1] >> carryPower;
    else
        product.bytes = (uint8_t *)malloc((product.size = n.size));
    product.bytes[0] = n.bytes[0] << shiftPower;
    for (size_t i = 0; i < n.size; product.bytes[i] += n.bytes[i] << shiftPower)
        if (n.bytes[i++] & carryBits)
            product.bytes[i] = n.bytes[n.size - 1] >> carryPower;
    return product;
}

Nnum rightBitShiftNnum(Nnum n, uint8_t shiftPower)
{
    if (!shiftPower)
        return copyNnum(n);
    if (shiftPower > 7)
    {
        fprintf(stderr, "Error: Cannot bitshift by more or equal number of bits than there are in a byte\n");
        exit(1);
    }
    uint8_t borrowBits = 0x01 << (shiftPower - 1);
    uint8_t borrowPower = 8 - shiftPower;
    Nnum quotient;
    if (n.bytes[n.size - 1] >> shiftPower)
        (quotient.bytes = (uint8_t *)malloc((quotient.size = n.size)))[n.size - 1] = n.bytes[n.size - 1] >> shiftPower;
    else
        quotient.bytes = (uint8_t *)malloc((quotient.size = n.size - 1));
    for (size_t i = n.size - 1; i < SIZE_MAX; quotient.bytes[i] += n.bytes[i] >> shiftPower)
        if (n.bytes[i--] & borrowBits)
            quotient.bytes[i] = n.bytes[i + 1] << borrowPower;
    return quotient;
}
