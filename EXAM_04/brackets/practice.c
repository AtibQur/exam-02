#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

void brackets(char *str)
{
    int r = 0;
    int s = 0;
    int c = 0;

    int len = ft_strlen(str);
    char next[len + 1];
    int i = 0;

    while (*str)
    {
        if (*str == '(')
            r++;
        if (*str == '[')
            s++;
        if (*str == '{')
            c++;
        if (*str == '(' || *str == '[' || *str == '{')
        {
            i++;
            next[i] = *str;
        }

        if ((*str == ')' && r == 0) || (*str == ']' && s == 0) || (*str == '}' && c == 0))
        {
            ft_putstr("Error\n");
            return ;
        }

        if (*str == ')' && next[i] == '(')
            r--;
        if (*str == ']' && next[i] == '[')
            s--;
        if (*str == '}' && next[i] == '{')
            c--;
        if (*str == ')' || *str == ']' || *str == '}')
            i--;
        str++;
    }

    if (r == 0 && s == 0 && c == 0)
        ft_putstr("OK\n");
    else
        ft_putstr("Error\n");
}

int main(int argc, char **argv) {
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            brackets(argv[i]);
        }
    }
    else
        ft_putstr("\n");
    return 0;
}