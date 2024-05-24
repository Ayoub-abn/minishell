/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:05:44 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/22 22:06:09 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**array_cpy(char **env)
{
	char	**array;
	int		i;

	i = 0;
	while (env[i])
		i++;
	array = malloc((i + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		array[i] = ft_strdup(env[i]);
		if (array[i] == NULL)
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
