/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/11 17:31:29 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	while_split(int i, const char *str)
{
	char	quote_char;

	quote_char = str[i++];
	while (str[i] && str[i] != quote_char)
		i++;
	if (str[i] == quote_char)
		i++;
	return (i);
}

int	count_words(const char *str, char c)
{
	int (i), (count);
	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		if (str[i] != c)
			count++;
		while (str[i] && (str[i] != c || str[i] == '"' || str[i] == '\''))
		{
			if (str[i] == '"' || str[i] == '\'')
				i = while_split(i, str);
			else
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char **(ptr);
	int (i), (n), (start);
	i = 0;
	n = 0;
	ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
	gc_push(ptr);
	while (s && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && (s[i] != c || (s[i] == '"' || s[i] == '\'')))
		{
			if (s[i] == '"' || s[i] == '\'')
				i = while_split(i, s);
			else
				i++;
		}
		ptr[n++] = ft_substr(s, start, i - start);
		if (!ptr[n - 1])
			return (_free(), NULL);
	}
	return (ptr[n] = NULL, ptr);
}
