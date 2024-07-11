/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:51 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/11 18:47:34 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minishell.h"

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
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last;

	last = *lst;
	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
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
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
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
		return ;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}
