/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:51 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/27 12:10:50 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_lexer **lst, t_lexer *new)
{
	
	t_lexer	*last;

	last = *lst;
	
	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		// new->prev = NULL;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
	// new->prev = tmp;
}
