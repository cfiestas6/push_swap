#include "push_swap.h"

int count_words(const char *str)
{
    int count;
    int in_word;
    int i;

    count = 0;
    in_word = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (str[i] == ' ')
                in_word = 0;
        i++;
    }
    return (count);
}

char **allocate_words(int words)
{
    char **result;

    result = (char **)malloc((words + 1) * sizeof(char *));
    if (!result)
        exit(1);
    return (result);
}

void process_word(const char *str, char **result, int *index, int len)
{
    char *word;

    word = (char *)malloc(len + 1);
    if (!word)
        exit(1);
    ft_strcpy(str, word, len);
    word[len] = 0;
    result[*index] = word;
    (*index)++;
}


char **ft_split(const char *str)
{
    char **result;
    int index;
    int len;
    int i;

    result = allocate_words(count_words(str));
    index = 0;
    len = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != 0)
            len++;
        else if (len > 0)
        {
            process_word(str + i - len, result, &index, len);
            len = 0; 
        }
        i++;
    }
    if (len > 0)
        process_word(str + i - len, result, &index, len);
    result[index] = NULL;
    return (result);
}
