#include "Nnum.h"

#define help printf("helpNnum\n")

// TODO #if defined(__ARM_NEON) || defined(__aarch64__)

Nnum *Ninit(uintmax_t ju) //* questionable need for SIMD support
{
    Nnum *newNnum = malloc(sizeof(Nnum)); // alloc Nnum
    if (!newNnum)
    {
        perror("Error: memory allocation for new Nnum failed");
        return newNnum;
    }
    // init .size and alloc .bytes
    uint8_t size = 0;
    for (uintmax_t i = ju; i; i >>= 8)
        ++size;
    newNnum->b8 = malloc(newNnum->size = size);
    // init bytes
    for (uint8_t i = 0; ju; ju >>= 8)
        newNnum->b8[i++] = ju & 0xFF;
    return newNnum;
}

Nnum *Nclone(Nnum *orig) // TODO improve: support SIMD
{
    if (!orig) // original existence check
        return NULL;
    Nnum *copyNnum = malloc(sizeof(Nnum)); // alloc Nnum
    if (!copyNnum)
    {
        perror("Error: memory allocation for clone Nnum failed\n");
        return copyNnum;
    }
    // init .size and alloc .bytes
    copyNnum->b8 = malloc(copyNnum->size = orig->size);
    // init bytes
    for (uint8_t i = 0; i < orig->size; ++i)
        copyNnum->b8[i] = orig->b8[i];
    return copyNnum;
}

void Nfree(Nnum *self)
{
    if (self)
    {
        if (self->b8)
        {
            free(self->b8);
            self->b8 = NULL;
        }
        free(self);
        self = NULL;
    }
}

void NprintxV2(Nnum *self) //! bug: significant zeros not printed
{
    switch (self->size & 7)
    {
    case 0:
        printf("0x");
        break;
    case 1:
        printf("0x%x",
               self->b8[self->size - 1]);
        break;
    case 2:
        printf("0x%x",
               self->b16[(self->size >> 1) - 1]);
        break;
    case 3:
        printf("0x%x%x",
               self->b8[self->size - 1],
               self->b16[(self->size >> 1) - 1]);
        break;
    case 4:
        printf("0x%x",
               self->b32[(self->size >> 2) - 1]);
        break;
    case 5:
        printf("0x%x%x",
               self->b8[self->size - 1],
               self->b32[(self->size >> 2) - 1]);
        break;
    case 6:
        printf("0x%x%x",
               self->b16[(self->size >> 1) - 1],
               self->b32[(self->size >> 2) - 1]);
        break;
    case 7:
        printf("0x%x%x%x",
               self->b8[self->size - 1],
               self->b16[(self->size >> 1) - 1],
               self->b32[(self->size >> 2) - 1]);
        break;
    }
    for (size_t i = (self->size >> 3) - 1; i != SIZE_MAX; --i)
        printf("%llx", self->b64[i]);
    printf("\n");
}

void Nprintx(Nnum *self) //* V3
{
    if (!self->size)
    {
        printf("0");
        return;
    }
    for (size_t i = self->size - 1; i != SIZE_MAX; --i)
        if (self->b8[i] >> 4)
            printf("%x", self->b8[i]);
        else
            printf("0%x", self->b8[i]);
}

uint8_t Nequal(Nnum *self, Nnum *other)
{
    if (self->size != other->size)
        return 0;
    for (size_t i = (self->size >> 3) - 1; i != SIZE_MAX; --i)
        if (self->b64[i] != other->b64[i])
            return 0;
    switch (self->size & 7)
    {
    case 0:
        return 1;
    case 1:
        return self->b8[self->size - 1] == other->b8[self->size - 1];
    case 2:
        return self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1];
    case 3:
        return self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1] &&
               self->b8[self->size - 1] == other->b8[self->size - 1];
    case 4:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1];
    case 5:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1] &&
               self->b8[self->size - 1] == other->b8[self->size - 1];
    case 6:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1] &&
               self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1];
    case 7:
        return self->b32[(self->size >> 2) - 1] == other->b32[(self->size >> 2) - 1] &&
               self->b16[(self->size >> 1) - 1] == other->b16[(self->size >> 1) - 1] &&
               self->b8[self->size - 1] == other->b8[self->size - 1];
    }
    perror("Error: Nequal failed");
    exit(EXIT_FAILURE);
    return 0;
}

uint8_t Nnotequal(Nnum *self, Nnum *other)
{
    if (self->size != other->size)
        return 1;
    for (size_t i = (self->size >> 3) - 1; i != SIZE_MAX; --i)
        if (self->b64[i] != other->b64[i])
            return 1;
    switch (self->size & 7)
    {
    case 0:
        return 0;
    case 1:
        return self->b8[self->size - 1] != other->b8[self->size - 1];
    case 2:
        return self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1];
    case 3:
        return self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1] ||
               self->b8[self->size - 1] != other->b8[self->size - 1];
    case 4:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1];
    case 5:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1] ||
               self->b8[self->size - 1] != other->b8[self->size - 1];
    case 6:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1] ||
               self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1];
    case 7:
        return self->b32[(self->size >> 2) - 1] != other->b32[(self->size >> 2) - 1] ||
               self->b16[(self->size >> 1) - 1] != other->b16[(self->size >> 1) - 1] ||
               self->b8[self->size - 1] != other->b8[self->size - 1];
    }
    perror("Error: Nnotequal failed");
    exit(EXIT_FAILURE);
    return 0;
}

uint8_t Ngreater(Nnum *self, Nnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Ngreater(Nnum *self, Nnum *other)\n");
    (void)self, (void)other;
    return 0;
}

uint8_t Nlesser(Nnum *self, Nnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Nlesser(Nnum *self, Nnum *other)\n");
    (void)self, (void)other;
    return 0;
}

uint8_t Ngreaterorequal(Nnum *self, Nnum *other) // TODO finish
{
    printf("Unfinished: uint8_t Ngreaterorequal(Nnum *self, Nnum *other)\n");
    (void)self, (void)other;
    return 0;
}

uint8_t NlesserorequalNnum(Nnum *self, Nnum *other) // TODO finish
{
    printf("Unfinished: uint8_t NlesserorequalNnum(Nnum *self, Nnum *other)\n");
    (void)self, (void)other;
    return 0;
}

void Naddto(Nnum *self, Nnum *addend)
{
    if (addend->size == 0) // additive identity check
        return;
    if (self->size == 0) // pseudo clone check
    {
        Nfree(self);
        self = Nclone(addend);
        return;
    }
    if (self->size < addend->size) // preop resize check
    {
        self->b8 = realloc(self->b8, addend->size);
        if (!self->b8)
        {
            perror("Error: memory reallocation for Nnum failed (preop)\n");
            return;
        }
        memset(self->b8 + self->size, 0, addend->size);
        self->size = addend->size;
    }
    // addition
    uint8_t carry = 0;
    for (size_t i = 0; i < (addend->size >> 4); ++i)
    {
        self->b64x2[i] = vaddq_u64(self->b64x2[i], addend->b64x2[i]);
        self->b64[2 * i] += carry;
        carry = (self->b64[2 * i] < addend->b64[2 * i]) ||
                (carry && (self->b64[2 * i] == addend->b64[2 * i]));
        self->b64[2 * i + 1] += carry;
        carry = (self->b64[2 * i + 1] < addend->b64[2 * i + 1]) ||
                (carry && (self->b64[2 * i + 1] == addend->b64[2 * i + 1]));
    }
    switch (addend->size & 15)
    {
    case 0:
        break;
    case 1:
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 2:
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        break;
    case 3:
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 4:
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        break;
    case 5:
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 6:
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        break;
    case 7:
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 8:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry &&
                 (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        break;
    case 9:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 10:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        break;
    case 11:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 12:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        break;
    case 13:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    case 14:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        break;
    case 15:
        self->b64[(addend->size >> 3) - 1] += addend->b64[(addend->size >> 3) - 1] + carry;
        carry = (self->b64[(addend->size >> 3) - 1] < addend->b64[(addend->size >> 3) - 1]) ||
                (carry && (self->b64[(addend->size >> 3) - 1] == addend->b64[(addend->size >> 3) - 1]));
        self->b32[(addend->size >> 2) - 1] += addend->b32[(addend->size >> 2) - 1] + carry;
        carry = (self->b32[(addend->size >> 2) - 1] < addend->b32[(addend->size >> 2) - 1]) ||
                (carry && (self->b32[(addend->size >> 2) - 1] == addend->b32[(addend->size >> 2) - 1]));
        self->b16[(addend->size >> 1) - 1] += addend->b16[(addend->size >> 1) - 1] + carry;
        carry = (self->b16[(addend->size >> 1) - 1] < addend->b16[(addend->size >> 1) - 1]) ||
                (carry && (self->b16[(addend->size >> 1) - 1] == addend->b16[(addend->size >> 1) - 1]));
        self->b8[addend->size - 1] += addend->b8[addend->size - 1] + carry;
        carry = (self->b8[addend->size - 1] < addend->b8[addend->size - 1]) ||
                (carry && (self->b8[addend->size - 1] == addend->b8[addend->size - 1]));
        break;
    }
    for (size_t i = addend->size; i < self->size; ++i)
    {
        self->b8[i] += carry;
        carry = !self->b8[i];
    }
    if (carry) // postop resize check
    {
        self->b8 = realloc(self->b8, ++self->size);
        if (!self->b8)
        {
            perror("Error: memory reallocation for Nnum failed (postop)\n");
            return;
        }
        self->b8[self->size - 1] = 1;
    }
}

void NaddtoOLD(Nnum *self, Nnum *addend) //* not used
{
    if (addend->size == 0) // additive identity check
        return;
    if (self->size == 0) // pseudo clone check
    {
        Nfree(self);
        self = Nclone(addend);
        return;
    }
    if (self->size < addend->size) // preop resize check
    {
        self->b8 = realloc(self->b8, addend->size);
        if (!self->b8)
        {
            perror("Error: memory reallocation for Nnum failed\n");
            return;
        }
        memset(self->b8 + self->size, 0, addend->size);
        self->size = addend->size;
    }
    // addition
    uint8_t carry = 0;
    size_t i = 0;
    for (; i < addend->size; ++i)
    {
        self->b8[i] += addend->b8[i] + carry;
        carry = (self->b8[i] < addend->b8[i]) ||
                (carry && (self->b8[i] == addend->b8[i]));
    }
    for (; i < self->size; ++i)
    {
        self->b8[i] += carry;
        carry = !self->b8[i];
    }
    if (carry) // postop resize check
    {
        self->b8 = realloc(self->b8, ++self->size);
        if (!self->b8)
        {
            perror("Error: memory reallocation for Nnum failed\n");
            return;
        }
        self->b8[self->size - 1] = 1;
    }
}

void Nsubto(Nnum *self, Nnum *subtrahend) // TODO improve: support SIMD
{
    if (self->size < subtrahend->size) // preop negative check
    {
        perror("Error: Nnum cannot hold negative values\n");
        free(self->b8);
        self->b8 = NULL;
        return;
    }

    // subtraction
    uint8_t borrow = 0;
    size_t i = 0;
    for (uint8_t currbyte; i < subtrahend->size; ++i)
        borrow = (currbyte = self->b8[i]) < (self->b8[i] -= subtrahend->b8[i] + borrow); //! bug borrow comparison
    while (borrow && i < self->size)
        borrow = --self->b8[i++] == 0xFF;

    if (borrow) // postop negative check
    {
        perror("Error: Nsubto cannot return difference lesser than zero");
        free(self->b8);
        self->b8 = NULL;
        return;
    }

    // resize away empty bytes
    size_t empties = 0;
    for (--i; !self->b8[i] && i < SIZE_MAX; --i)
        ++empties;
    self->b8 = realloc(self->b8, self->size -= empties);
}

void Nmulto(Nnum *self, Nnum *factor) // TODO finish
{
    printf("Unfinished: void Nmulto(Nnum *self, Nnum *factor)\n");
    if (!factor->size) // zero factor check
    {
        self->b8 = realloc(self->b8, self->size -= 0);
        return;
    }

    // preop resize check

    // multiplication

    // postop resize check
}

void Ndivto(Nnum *self, Nnum *divisor) // TODO finish
{
    printf("Unfinished: void Ndivto(Nnum *self, Nnum *divisor)\n");
    (void)self, (void)divisor;
    // division
}

void Nmodto(Nnum *self, Nnum *divisor) // TODO finish
{
    printf("Unfinished: void Ndivto(Nnum *self, Nnum *divisor)\n");
    (void)self, (void)divisor;
    // modulus
}
