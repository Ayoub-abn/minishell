#include "minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_management_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:19:23 by merrahal          #+#    #+#             */
/*   Updated: 2024/06/30 13:38:23 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if(!envp || !*envp)
		return NULL;
	while (envp[i])
	{
		add_back(&list, new_node(envp[i]));
        i++;
	}
	return (list);
}

int	env_lstsize(t_env *lst)
{
	t_env	*p;
	int		i;

	i = 0;
	p = lst;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}


char **list_to_envp(t_env *list)
{
	char *tmp_key;
	char **line;
	int i = 0;

	line = malloc(sizeof(char *) * env_lstsize(list) + 1);
	while (list)
	{
		tmp_key = list->key;
		tmp_key = ft_strjoin(tmp_key, "=");
		line[i++] = ft_strjoin(tmp_key, list->value);
		list = list->next;
	}
	line[i] = NULL;
	return (line);
}

int main(int ac, char **av, char **envp)
{
    (void) ac;
    (void) av;
    t_env *list = envp_to_list(envp);
	t_env *tmp_list = list;
    // while (tmp_list)
    // {
    //     printf("key = %s", tmp_list->key);
    //     printf(" value = %s\n", tmp_list->value);
    //     tmp_list = tmp_list->next;
    // }
	char **env = list_to_envp(list);
    int i = -1;
	while (env[++i])
        printf("%s\n", env[i]);
}
