/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:41:49 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/18 11:34:17 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool    ft_is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n' || c == '\r');
}

int ft_split_count_word(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (ft_is_whitespace(str[i]))
            i++;
        if (str[i] == '\0')
            break ;
        while (!ft_is_whitespace(str[i]) && str[i] != '\0')
            i++;
        count++;
    }
    return (count);
}

char    *ft_str_n_dup(char *str, int n)
{
    int     i;
    char    *dup;

    if (!(dup = (char *)malloc((n + 1) * sizeof(char))))
        return (NULL);
    i = 0;
    while (str[i] && i < n)
    {
        dup[i] = str[i];
        i++;
    }
    while (i < n + 1)
    {
        dup[i] = '\0';
        i++;
    }
    return (dup);
}

char    **ft_split(char *str)
{
    int i;
    int words;
    char    *start;
    char    **arr;

    i = 0;
    words = ft_split_count_word(str);
    if (!(arr = (char **)malloc((words + 1) * sizeof(char *) )))
        return (NULL);
    while (i < words)
    {
        while (ft_is_whitespace(*str))
            str++;
        if (*str == '\0')
            break ;
        start = str;
        while (!ft_is_whitespace(*str) && *str != '\0')
            str++;
        arr[i] = ft_str_n_dup(start, str - start);
        i++;
    }
    arr[i] = 0;
    return (arr);
}
