#include <stdio.h>
#include <stdlib.h>

int mult_3(int n) {
    if (n % 3 == 0)
        return 0;
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }

    int num = atoi(argv[1]);
    int res = mult_3(num);
    if (res)
        printf("not mult of 3!\n");
    else
        printf("mult of 3!\n");
    return res;
}