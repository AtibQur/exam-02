#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s) {
   int n;
   for (n = 0; *s != '\0'; s++)
      n++;
   return n;
}

void multiply_strings(char* s1, char* s2) {
   int len1 = ft_strlen(s1);
   int len2 = ft_strlen(s2);

 int *result = malloc((len1 + len2) * sizeof(int));

    // Initizalize result to 0
   for (int i = 0; i < len1 + len2; i++)
      result[i] = 0;

        // Multiply
   for (int i = len1 - 1; i >= 0; i--) {
      int carry = 0;
      int a = s1[i] - '0';
      for (int j = len2 - 1; j >= 0; j--) {
         int b = s2[j] - '0';
         int prod = a * b + carry + result[i + j + 1];
         result[i + j + 1] = prod % 10;
         carry = prod / 10;
      }
      result[i] += carry;
   }

    // Find the first non-zero digit
   int i = 0;
   while (i < len1 + len2 - 1 && result[i] == 0)
      i++;

    // Write the result to STDOUT
   while (i < len1 + len2) {
      char c = result[i] + '0';
      write(1, &c, 1);
      i++;
   }

      free(result);
}

int main(int argc, char *argv[]) {
   if (argc != 3) {
      return 1;
   }
   multiply_strings(argv[1], argv[2]);
   write(1, "\n", 1);
}