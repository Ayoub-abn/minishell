/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:09:34 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/11 18:30:26 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_malloc	**get_head(void)
{
	static t_malloc	*head;

	return (&head);
}

void	add_back_to_gc(t_malloc *new)
{
	t_malloc	**head;
	t_malloc	*tmp;

	head = get_head();
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	gc_push(void *address_to_save)
{
	t_malloc	**head;
	t_malloc	*node;

	head = get_head();
	if (!address_to_save)
		error_exit(1, "malloc");
	node = malloc(sizeof(t_malloc));
	if (!node)
		error_exit(1, "malloc");
	node->address_to_save = address_to_save;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
		add_back_to_gc(node);
}

void	_free(void)
{
	t_malloc	*tmp;
	t_malloc	**head;
	t_malloc	*next;

	head = get_head();
	tmp = *head;
	while (tmp)
	{
		free(tmp->address_to_save);
		tmp->address_to_save = NULL;
		tmp = tmp->next;
	}
	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
