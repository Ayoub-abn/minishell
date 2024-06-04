/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/04 18:15:02 by aabdenou         ###   ########.fr       */
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
            if (str[i] == '"' || str[i] == '\'' )
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

// static char	**free_list(char **str, int n)
// {
// 	while (n > 0)
// 		free(str[--n]);
// 	free(str);
// 	return (NULL);
// }

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char quote_char;
	int		i;
	int		j;
	int		n;
	int start = 0;
	int end = 0;


	printf("command %s\n",s);
	printf("arg %d\n",count_words(s,c));
	

	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	n = 0;

	while (s && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if(s[i] == '"' || s[i] == '\'')
		{
			quote_char = s[i];
			i++;
			start = i;
            while (s[i] && s[i] != quote_char)
                i++;
            if (s[i] == '"' || s[i] == '\'' )
                i++;
			end = i;
		}
		i++;
  		//  else if (s[i])
        // {
        //     while (s[i] != c && s[i] != quote_char && s[i])
        //         i++;
        // }
	}



	
	// while (s && s[i] != '\0')
	// {
	// 	while (s[i] == c)
	// 		i++;
	// 	if (s[i] == '\0')
	// 		break ;
	// 	j = 0;
	// 	while (s[i] != '\0' && s[i] != c && j++ >= 0)
	// 		i++;
	// 	ptr[n++] = ft_substr(s, i - j, j);
	// 	if (ptr[n - 1] == NULL)
	// 		return (free_list(ptr, n));
	// }
	// ptr[n] = NULL;
	// return (ptr);
	return(NULL);
}
