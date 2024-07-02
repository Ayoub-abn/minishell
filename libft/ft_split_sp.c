/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:54:44 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/01 23:58:05 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int    is_separator(char c, char *sep)
{
    int    i;

    i = 0;
    while (sep[i])
    {
        if (sep[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static int    ft_countwords(char *str, char *sep)
{
    int    count;

    count = 0;
    while (*str)
    {
        while (is_separator(*str, sep) && *str)
            str++;
        if (!is_separator(*str, sep) && *str)
            count++;
        while (!is_separator(*str, sep) && *str)
            str++;
    }
    return (count);
}

static int    is_allocation_safe(char **allocatedArray, int position,
        int word_len)
{
    int    i;

    i = 0;
    allocatedArray[position] = (char *)malloc(sizeof(char) * word_len);
    // gc_push(allocatedArray[position]);
    return (1);
}

static int    ft_fill(char **allocatedArray, char const *givenString,
        char *separator)
{
    int    word_len;
    int    i;
    int    j;

    i = 0;
    while (*givenString)
    {
        j = 0;
        word_len = 0;
        while (*givenString && is_separator(*givenString, separator))
            givenString++;
        while (givenString[j] && !is_separator(givenString[j++], separator))
            word_len++;
        if (word_len)
        {
            if (!is_allocation_safe(allocatedArray, i, word_len + 1))
                return (0);
            ft_strlcpy(allocatedArray[i], givenString, word_len + 1);
        }
        while (*givenString && !is_separator(*givenString, separator))
            givenString++;
        i++;
    }
    return (1);
}

char    **ft_split_sp(char const *s, char *c)
{
    char    **splited;
    int        words;

    if (s[0] == '\0' || !s)
    {
        return (NULL);
    }
    words = ft_countwords((char *)s, c);
    splited = (char **)malloc((words + 1) * sizeof(char *));
    // gc_push(splited);
    splited[words] = NULL;
    if (!ft_fill(splited, s, c))
        return (NULL);
    return (splited);
}