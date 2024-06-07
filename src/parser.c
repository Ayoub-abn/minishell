/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:21:56 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/07 18:23:57 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_node_file(t_file **head, char *file_name, t_tokens type)
{
	t_file	*node;

	node = ft_file_new(file_name, type);
	ft_lstadd_back_file(head, node);
	// display_token((*head));
}
void	add_node_command(t_command **head, char *command)
{
	t_command	*node;

	// int i = 0;
	// printf("HI\n");
	node = ft_command_new(command);
	ft_lstadd_back_command(head, node);
	// display_token_command((*head));
}
void	handel_token(t_lexer **head, t_file **file, t_tokens type)
{
	char	*file_name;

	file_name = NULL;
	if ((*head)->next && (*head)->next->tokens == WHITESPACE)
		(*head) = (*head)->next;
	(*head) = (*head)->next;
	while ((*head) && (*head)->tokens == WORD)
	{
		// Skip any whitespace within the file name
		if ((*head)->tokens == WHITESPACE)
			break ;
		// Append the current token's string to file_name
		file_name = ft_strjoin(file_name, (*head)->str);
		// Move to the next token
		(*head) = (*head)->next;
	}
	add_node_file(file, file_name, type);
	free(file_name);
}

void	parser(t_tool *data)
{
	t_lexer		*head;
	char		*command;
	t_command	*command_list;

	command = NULL;
	head = data->lexer_list;
	// command_list = malloc(sizeof(t_command));
	command_list = NULL;
	// command_list->file = NULL;
	// t_file		*file;
	t_file		*file;
	// file = command_list->file;
	// file = malloc(sizeof(t_file));
	file = NULL;
	
	
	
	while (head)
	{
		while (head && head->tokens != PIPE)
		{
			if (head->tokens == WORD)
			{
				while (head && head->tokens == WORD)
				{
					command = ft_strjoin(command, head->str);
					if (head->next && head->next->tokens == WHITESPACE)
					{
						command = ft_strjoin(command, " ");
					}
					head = head->next;
				}
			}
			else if (head->tokens != WORD)
			{
				
				if (head->tokens == REDIR_IN || head->tokens == REDIR_OUT ||
					head->tokens == HEREDOC || head->tokens == APPEND)
				{
					handel_token(&head, &file, head->tokens);
					// handel_token(&head, &command_list->file, head->tokens);
				}
				else
					head = head->next;
			}	
		}
		add_node_command(&command_list, command);
		command = NULL;
		if (head && head->tokens == PIPE)
			head = head->next;
		// printf("%s\n",command);
	}
	display_token_command(command_list,file);
	// display_token_command(command_list);
	// display_token(file);
	
	// add_node_command(&command_list,command);
	// char **command_arg = ft_split(command,' ');
	// int i = 0;
	// while (command_arg[i])
	// {
	// printf("command_arg = (%s)\n", command_arg[i++]);
	// }
}
