/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:51 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/08 18:10:53 by aabdenou         ###   ########.fr       */
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
void	ft_lstadd_back_file(t_file **lst, t_file *new)
{
	
	t_file	*last;

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
	// printf("%p\n",lst);
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
	// new->prev = tmp;
}
void	ft_lstadd_back_command(t_command **lst, t_command *new)
{
	
	t_command	*last;

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