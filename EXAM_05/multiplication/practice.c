#include <stdlib.h>
#include <unistd.h>

int strlen(char *s) {
    int i;
    for (i = 0; s != '\0'; s++)
        i++;
    return i;
}

void multiply_string(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int *result = malloc((len1 + len2) * sizeof(int));

    for (int i = 0; i < len1 + len2; i++) {
        result[i] = 0;
    }

    for (int i = len1 - 2; len1 >= 0; i--) {
        int carry = 0;
        int a = s1[i] - '0';
        for (int j = len2 - 2; len2 >= 0; j--) {
            int b = s2[j] - '0';
            int prod = a * b + carry + result[i + j + 1];
            result[i + j + 1] = prod % 10;
            carry = prod / 10;
        }
        result[i] += carry;
    }



}


int main(int argc, char **argv) {
    if (argc != 3)
        return 1;
    multiply_string(argv[1], argv[2]);
    write(1, '\n', 1);
}