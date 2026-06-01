#include<stdio.h>

/* Function Prototypes */

void printBits(int n);

int countOneBits(int n);

void checkEndian();

void printFloatBits(float f);

int main()
{
    int n;

    float f;

    /* Integer Part */

    printf("Enter an integer: ");

    scanf("%d",&n);

    printf("\nBits of integer:\n");

    printBits(n);

    printf("\n\nNumber of 1 bits = %d\n",
           countOneBits(n));

    /* Endian Check */

    printf("\nEndian Type:\n");

    checkEndian();

    /* Negative Integer */

    printf("\nBits of negative integer (%d):\n",-n);

    printBits(-n);

    /* Float Part */

    printf("\n\nEnter a floating point number: ");

    scanf("%f",&f);

    printf("\nBits of float:\n");

    printFloatBits(f);

    /* Negative Float */

    printf("\n\nBits of negative float:\n");

    printFloatBits(-f);

    return 0;
}

/* Function to print bits of integer */

void printBits(int n)
{
    for(int i=31;i>=0;i--)
    {
        printf("%d",(n>>i)&1);

        if(i%4==0)
        {
            printf(" ");
        }
    }
}

/* Function to count number of 1 bits */

int countOneBits(int n)
{
    int count=0;

    while(n)
    {
        count += n & 1;

        n = n >> 1;
    }

    return count;
}

/* Function to check endian */

void checkEndian()
{
    int x=1;

    char *p;

    p=(char*)&x;

    if(*p==1)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
}

/* Function to print float bits */

void printFloatBits(float f)
{
    int *p;

    p=(int*)&f;

    for(int i=31;i>=0;i--)
    {
        printf("%d",((*p)>>i)&1);

        if(i%4==0)
        {
            printf(" ");
        }
    }
}