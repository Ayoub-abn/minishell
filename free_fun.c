/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:58:48 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/06 18:33:02 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_link_list(t_lexer **list)
{
	t_lexer	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
}
void	free_link_list_parser(t_command **list)
{
    t_command	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
}

void	free_link_list_env(t_env **list)
{
    t_env	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
}