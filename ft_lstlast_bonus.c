/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:14:28 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/24 21:23:04 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lstlast(t_lexer *lst)
{
	t_lexer	*p;

	if (lst == NULL)
		return (NULL);
	p = lst;
	while (p->next != NULL)
		p = p->next;
	return (p);
}
