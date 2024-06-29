/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:36:16 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/23 17:50:10 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lst;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}
