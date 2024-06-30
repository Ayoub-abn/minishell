/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_linkedlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:19:23 by merrahal          #+#    #+#             */
/*   Updated: 2024/06/30 17:02:06 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	search_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static t_env	*new_node(char *envp_line)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	lst->key = ft_substr(envp_line, 0, search_in(envp_line, '='));
	lst->value = ft_substr(envp_line, search_in(envp_line, '=') + 1, ft_strlen(envp_line));
	lst->next = NULL;
	return (lst);
}

static t_env	*get_last_node(t_env *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	add_back(t_env **head, t_env *new)
{
	if (!head)
		return ;
	if (head && *head)
	{
		get_last_node(*head)->next = new;
		return ;
	}
	*head = new;
}

t_env	*envp_to_list(char **envp)
{
	int		i;
	t_env	*list;

	i = 0;
	list = 0;
	while (envp[i])
	{
		add_back(&list, new_node(envp[i]));
        i++;
	}
	return (list);
}
