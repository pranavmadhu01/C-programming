#include <stdio.h>
#include <stdlib.h>
int loop_rolling(int n);
int loop_unrolling(int n);
int main()
{
    int n;
    printf("Enter the number to demonstrate.\n");
    scanf("%d", &n);
    int bits = 0;
    do
    {
        printf("Enter the choice.\n");
        printf("1. For loop rolling\n");
        printf("2. For loop unrolling\n");
        printf("3. Press any other key for exitinf the program\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bits = loop_rolling(n);
            printf("The number of bits is %d", bits);
            break;
        case 2:
            bits = loop_unrolling(n);
            printf("The number of bits is %d", bits);
            break;
        default:
        {
            printf("Invalid choice.\n");
            exit(0);
        }
        }
    } while (1);
    return 0;
}

int loop_rolling(int n)
{
    int iterations = 0, bits = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        n >>= 1;
        iterations++;
    }
    printf("The number of iterations is %d", iterations);
    return bits;
}
int loop_unrolling(int n)
{
    int iterations = 0, bits = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        if (n & 2)
            bits++;
        if (n & 4)
            bits++;
        if (n & 8)
            bits++;
        n >>= 4;
        iterations++;
    }
    printf("The number of iterations is %d", iterations);
    return bits;
}