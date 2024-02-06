#include "push_swap.h"
#include <limits.h>

int count_numbers(int argc, char **argv)
{
    int i;
    int count;

	count = 0;
	i = 1;
    while (i < argc)
        count += count_words(argv[i++]);
    return count;
}

void check_for_duplicates(int *numbers, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
			if (numbers[i] == numbers[j++])
				write_error_and_exit();
		i++;
	}
}

void check_for_not_numbers(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
        if (!is_number(argv[i++]))
                write_error_and_exit();
}

int *parse_args(int argc, char **argv, int count)
{
    int *result;
    int i;
    int j;
	int k;
    char **temp;

	i = 1;
	j = 0;
	result = (int *)malloc(sizeof(int) * count);
    while (i < argc)
    {
        temp = ft_split(argv[i++]);
		k = 0;
        while (temp[k])
            result[j++] = ft_atoi(temp[k++]);
        free(temp);
	}
    return (result);
}
