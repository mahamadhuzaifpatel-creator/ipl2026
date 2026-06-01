#include <stdio.h>

struct Bitfield
{
    unsigned int firstbit  : 1;  // 1 bit
    unsigned int secondbit : 1;  // 1 bit
    unsigned int value     : 3;  // 3 bits
};

int main()
{
    struct Bitfield a;
    unsigned int x, y, z;

    printf("Enter firstbit (0 or 1): ");
    scanf("%u", &x);

    printf("Enter secondbit (0 or 1): ");
    scanf("%u", &y);

    printf("Enter value (0 to 7): ");
    scanf("%u", &z);

    /* Assign values to bit-fields */
    a.firstbit = x;
    a.secondbit = y;
    a.value = z;

    printf("\nStored Values:\n");
    printf("firstbit  = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);
    printf("value     = %u\n", a.value);

    return 0;
}