#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prime_num(int n) {
    int i = 2;

    while (i * i <= n) {
        if (n % i != 0) {
            i++;
        }
        else {
            n /= i;
            printf("%d*", i);
        }
    }
    if (n > 0)
        printf("%d", n);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("\n");
        return 1;
    }

    int num = atoi(argv[1]);
    if (num == 1) {
        printf("1");
        return 0;
    }

    prime_num(num);
    printf("\n");

    return 0;
}