/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/11 16:54:32 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// l"s -al" ==> exm no val




int count_words(const char *str, char c)
{
    int i = 0, count = 0;
    char quote_char;

    while (str && str[i])
    {
        // Skip delimiters
        while (str[i] == c)
            i++;
        // If we reached the end of the string, break
        if (str[i] == '\0')
            break;
        // Increment word count
        if (str[i] != c)
            count++;
        // Traverse the word
        while (str[i] && (str[i] != c || str[i] == '"' || str[i] == '\''))
        {
            if (str[i] == '"' || str[i] == '\'')
            {
                quote_char = str[i++];
                while (str[i] && str[i] != quote_char)
                    i++;
                if (str[i] == quote_char)
                    i++;
            }
            else
                i++;
        }
    }
    return count;
}

char **free_list(char **str, int n)
{
    while (n > 0)
        free(str[--n]);
    free(str);
    return NULL;
}

// Main split function
char **ft_split(char const *s, char c)
{
    char **ptr;
    int i = 0;
	int n = 0;
	int start;
    char quote_char;

    ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!ptr)
        return NULL;

    while (s && s[i] != '\0')
    {
        // Skip delimiters
        while (s[i] == c)
            i++;
        // If we reached the end of the string, break
        if (s[i] == '\0')
            break;
        // Mark the start of the word
        start = i;
        // Traverse the word
        while (s[i] && (s[i] != c || (s[i] == '"' || s[i] == '\'')))
        {
            if (s[i] == '"' || s[i] == '\'')
            {
                quote_char = s[i++];
                while (s[i] && s[i] != quote_char)
                    i++;
                if (s[i] == quote_char)
                    i++;
            }
            else
                i++;
        }
        // Create the substring for the current word
        ptr[n++] = ft_substr(s, start, i - start);
        if (!ptr[n - 1])
            return free_list(ptr, n);
    }
    ptr[n] = NULL;
    return (ptr);
}
