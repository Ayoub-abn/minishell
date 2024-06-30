/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_for_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:13:51 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/30 16:07:52 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	count_words_2(const char *str, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str && str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			while (str[i] && str[i] != c)
// 				i++;
// 		}
// 		else
// 			i++;
// 		count++;
// 	}
// 	return (count);
// }

static char	**free_list_2(char **str, int n)
{
	while (n > 0)
		free(str[--n]);
	free(str);
	return (NULL);
}

char	**ft_split_for_equal(char const *s,char c)
{
    char **ptr;
    int i = 0;
    int start = 0;

    ptr = malloc(3 * sizeof(char *));
    if (!ptr)
        return NULL;

    // Find the first occurrence of '='
    while (s[i] != '\0' && s[i] != c)
        i++;

    // Create the first substring
    ptr[0] = ft_substr(s, start, i - start);
    if (!ptr[0])
        return free_list_2(ptr, 1);

    // Move past the first '='
    if (s[i] == '=')
        i++;

    // Create the second substring
    ptr[1] = ft_substr(s, i, ft_strlen(s) - i);
    if (!ptr[1])
        return free_list_2(ptr, 2);

    // Null-terminate the array
    ptr[2] = NULL;

    return ptr;
}