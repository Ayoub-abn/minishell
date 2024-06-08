/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:19:58 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/08 23:50:09 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexer_new(char *str,t_tokens type)
{
	t_lexer	*new_node;
	// static int i; 

	new_node = malloc(sizeof(t_lexer));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str;
	new_node->tokens = type;
	// new_node->i = i++;
	new_node->next = NULL;
	// new_node->prev = NULL;
	return (new_node);
}
t_file	*ft_file_new(char *file_name,t_tokens type)
{
	t_file	*new_node;

	new_node = malloc(sizeof(t_file));
	if (new_node == NULL)
		return (NULL);
	new_node->file_name = file_name;
	new_node->file_type = type;
	new_node->next = NULL;
	// new_node->prev = NULL;
	return (new_node);
}
t_command	*ft_command_new(char *command ,t_file *file)
{
	t_command	*new_node;
	char **command_arg = ft_split(command,' ');
	if (!command_arg)
		return (NULL);
	int i = 0;
	while (command_arg[i])
		i++;
	// printf("%d\n",i);
	new_node = malloc(sizeof(t_command));
	if (new_node == NULL)
		return (NULL);
	new_node->cmd = malloc(sizeof(char *) * (i + 1));
	if (!new_node->cmd)
		return (NULL);
	i = 0;
	while (command_arg[i])
	{
		new_node->cmd[i] = remove_quotes( command_arg[i]);
		// printf("%s\n",new_node->cmd[i]);
		i++;
	}
	// printf("%s\n",new_node->cmd[i]);
	new_node->cmd[i] = NULL;
	new_node->file = file;
	new_node->next = NULL;
	// new_node->prev = NULL;
	return (new_node);
}
