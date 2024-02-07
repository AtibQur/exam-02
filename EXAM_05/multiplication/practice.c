#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s) {
    int i;
    for (i = 0; s != '\0'; s++) {
        i++;
    }
    return i;
}

void multiply_string(char *s1, char *s2) {
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);

    int *result = malloc((len1 + len2) * sizeof(int));
    for (int i = 0; i < len1 + len2; i++) {
        result[i] = 0;
    }

}