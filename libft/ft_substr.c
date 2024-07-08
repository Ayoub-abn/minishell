/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:25:49 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/08 20:25:45 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	unsigned int	l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l || len == 0)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	p = malloc(len + 1);
	gc_push(p);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
