#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void multilpy(char *s1, char *s2) {
    bool neg1 = false;
    bool neg2 = false;
    if (s1[0] == '-') {
        neg1 = true;
        s1++;
    }
    if (s2[0] == '-') {
        neg2 = true;
        s2++;
    }

    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int *result = malloc((len1 + len2) * sizeof(int));

    for (int i = 0; i < len1 + len2; i++)
        result[i] = 0;

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int a = s1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--) {
            int b = s2[j] - '0';
            int drag = a * b + carry + result[i + j + 1];
            result[i + j + 1] = drag % 10;
            carry = drag / 10;
        }
        result[i] += carry;
    }

    int i = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;
    
    if ((!neg1 && neg2) || (neg1 && !neg2))
        write(1, "-", 1);

    while (i < len1 + len2) {
        char c = result[i] + '0';
        write(1, &c, 1);
        i++;
    }
    free(result);
}

int main(int argc, char **argv) {
    if (argc != 3)
        return 1;
    multilpy(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}