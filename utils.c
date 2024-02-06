#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void write_error_and_exit() {
    write(2, "Error\n", 5);
    exit(1);
}

void    ft_strcpy(const char *src, char *dest, int length)
{
    int i;

    i = 0;
    while (i < length)
    {
        dest[i] = src[i];
        i++;
    }
    dest[length] = 0;
}

int ft_strlen(const char *str)
{
    int length;

    length = 0;

    while (str[length])
        length++;
    return (length);
}

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int	is_space(char str)
{
	if (str == ' ')
		return (1);
	else if (str == '\f')
		return (1);
	else if (str == '\n')
		return (1);
	else if (str == '\r')
		return (1);
	else if (str == '\t')
		return (1);
	else if (str == '\v')
		return (1);
	return (0);
}

int is_number(const char *str)
{
    int i;

	i = 0;
    while (str[i])
    {
        if (is_space(str[i]))
            i++;
        else if (str[i] == '-')
        {
            if (!is_digit(str[i + 1]))
                return 0;
            i += 2;
        }
        else if (!is_digit(str[i]))
            return 0;
        else
            i++;
    }

    return 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	sign = 1;
	num = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign < 0)
		num *= -1;
	return (num);
}