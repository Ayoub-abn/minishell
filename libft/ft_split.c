/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/04 19:42:08 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;
	char quote_char;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if(str[i] == '"' || str[i] == '\'')
		{
			quote_char = str[i];
			i++;
            while (str[i] && str[i] != quote_char)
                i++;
            if (str[i] == quote_char)
                i++;
            count++;
		}
  		 else if (str[i])
        {
            count++;
            while (str[i] != c && str[i] != quote_char && str[i])
                i++;
        }
	}
	return (count);
}

static char	**free_list(char **str, int n)
{
	while (n > 0)
		free(str[--n]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char *line;
	char quote_char;
	int		i;
	int		n;
	int start;
	int end;

	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	n = 0;

	while (s && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if(s[i] == '\0')
			break;
		if(s[i] == '"' || s[i] == '\'')
		{
			quote_char = s[i];
			start = i;
			i++;
            while (s[i] && s[i] != quote_char)
                i++;
			end = i + 1;
			if (s[i] == quote_char)
                i++;
		}
  		 else if (s[i])
        {
			start = i;
            while (s[i] != c && s[i] != quote_char && s[i])
                i++;
			end = i;
        }
		ptr[n++] = ft_substr(s, start, end - start);
		if (ptr[n - 1] == NULL)
			return (free_list(ptr, n));
	}
	ptr[n] = NULL;
	return (ptr);
}
