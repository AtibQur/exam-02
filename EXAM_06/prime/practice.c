#include <stdio.h>
#include <stdlib.h>

void prime_nums(int n) {
    int i = 2;

    while (i * i <= n) {
        if (n % i != 0)
            i++;
        else {
            n /= i;
            printf("%d * ", i);
        }
    }
    printf("%d", i);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    
    int n = atoi(argv[1]);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    prime_nums(n);
    printf("\n");

    return 0;
}