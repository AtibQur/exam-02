#include <stdio.h>
#include <stdlib.h>

// Function to print the prime factors of a positive integer
void print_prime_factors(int n)
{
    int i = 2;
    while (i * i <= n) 
    {
        if (n % i != 0) 
            i++;
        else 
        {
            n /= i;
            printf("%d*", i);
        }
    }
    if (n > 1) 
        printf("%d", n); // Print the last factor without an asterisk
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <positive integer>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]); // Convert argument from string to integer
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    print_prime_factors(n);
    printf("\n"); // Print a newline after the factors

    return 0;
}

/*
gcc fprime.c -o fprime
*/