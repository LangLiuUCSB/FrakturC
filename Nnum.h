#ifndef NNUM_H
#define NNUM_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    uint8_t *bytes;
    size_t size;
} Nnum;

Nnum initNnum(uintmax_t i);

void printNnum(Nnum n);

Nnum copyNnum(Nnum n);

Nnum addNnums(Nnum n1, Nnum n2);
Nnum subtractNnums(Nnum n1, Nnum n2);

Nnum leftByteShiftNnum(Nnum n, size_t shiftPower);
Nnum rightByteShiftNnum(Nnum n, size_t shiftPower);

Nnum doubleNnum(Nnum n);
Nnum halfNnum(Nnum n);
Nnum leftBitShiftNnum(Nnum n, uint8_t shiftPower);
Nnum rightBitShiftNnum(Nnum n, uint8_t shiftPower);

#endif
