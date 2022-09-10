#include <stdio.h>
//#include "ft_split.c"
#include "test.c"

int main(void)
{
	char	*arr;
	char	**test;
	int		i;

	i = 0;
	arr = "If there are 	\n \t \vno spaces, than everything's fine!";
	test = ft_split(arr);
	while (test[i])
	{
		printf("%s", test[i]);
		i++;
	}
	return (0);
}