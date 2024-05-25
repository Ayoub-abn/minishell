/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:51 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/25 18:12:11 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




void	ft_lstadd_back(t_lexer **lst, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = *lst;
	
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
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	// new->prev = tmp;
}
