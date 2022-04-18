/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:40:49 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/18 11:01:11 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int whitespaces(char s)
{
    return (s == 32 || s == 9 || s == 10 || s == 11)

}
static int  ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}
static  int ft_count(char *str, char c)
{
    int i;
    int count;
    int word;
    i = 0;
    count = 0;
    word = 0;
    while (str[i] == c && str[i])
        i++;
    while (str[i])
    {
        if (str[i] != c && str[i])
            word = 1;
        if (str[i] == c)
        {
            while (str[i] == c && str[i])
                i++;
            if (str[i])
                count++;
        }
        else
            i++;
    }
    return (count + word);
}
static char *ft_cpy(char *str, char chr)
{
    int     i;
    char    *array;
    i = 0;
    array = 0;
    while (str[i] == chr)
        i++;
    while (str[i] && str[i] != chr)
        i++;
    array = (char *)malloc(sizeof(char) * (i + 1));
    if (!array)
        return (0);
    i = 0;
    while (str[i] && str[i] != chr)
    {
        array[i] = str[i];
        i++;
    }
    array[i] = '\0';
    return (array);
}
char    **ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     strings;
    char    **arr;
    i = 0;
    j = 0;
    if (!s)
        return (0);
    strings = ft_count((char *)s, c);
    arr = malloc(sizeof(char *) * (strings + 1));
    if (!arr)
        return (0);
    while (i < strings)
    {
        while (s[0] == c)
            s++;
        arr[j] = ft_cpy((char *)s, c);
        j++;
        s = s + f_strlen(arr[i]);
        i++;
    }
    arr[i] = NULL;
    return (arr);
}
