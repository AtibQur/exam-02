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

int	whitespace(char c)
{
	if (c == 32 || s == 9 || s == 10 || s == 11)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str++;
	return (i);
}

int	ft_count(char *str)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (whitespace(str[i]) && str[i])
	{
		if (!(whitespace(str[i]) && str[i])
			word = 1;
		if (whitespace(str[i]))
		{
			while (whitespace(str[i]) && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}

char	*ft_cpy(char *str)
{
	int		i;
	char	*arr;

	i = 0;
	arr = 0;
	while (whitespace(arr[i]))
		i++;
}


char    **ft_split(char const *s)
{
	int		i;
	int		j;
	int		strings;
	char	**arr;
	
	i = 0;
	j = 0
	if (!s)
		return (0);
	strings = ft_count((char *)s);
	arr = malloc(sizeof(char *) * (strings + 1));
	if (!arr)
		return (0);
	while (i < strings)
	{
		arr[j] = ft_cpy((char *)s);
		i++;
	}
}