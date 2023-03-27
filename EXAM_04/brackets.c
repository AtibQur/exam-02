#include <unistd.h>

int open_b(char c)
{
	if (c == 40 || c == 91 || c == 123)
		return (1);
	return (0);
}

int	closing_b(char c)
{
	if (c == 41 || c == 93 || c == 125)
		return (1);
	return (0);
}

int which_close(char c)
{
	if (c == 40)
		return (41);
	if (c == 91)
		return (93);
	if (c == 123)
		return (125);
	return (0);
}

int	start_loop(char *str, int *i)
{
	int b_close = which_close(str[*i]);
	int b_open = str[*i];
	int count = 0;
	while (str[*i])
	{
		if (str[*i] == b_open)
			count++;
		if (str[*i] == b_close)
		{
			count--;
			if (count == 0)
				return (1);
		}
		(*i)++;
	}
	return (0);
}

int	check_brackets(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (closing_b(str[i]))
			return (0);
		if (open_b(str[i]))
		{
			int res = start_loop(str, &i);
			if (res == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 2);
		return (0);
	}
	int i = 1;
	while (i < argc)
	{
		int res = check_brackets(argv[i]);
		if (res == 0)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
		i++;
	}
	return (0);
}
