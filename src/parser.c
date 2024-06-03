/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:21:56 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/03 15:24:54 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_node_file(t_file **head, char *file_name, t_tokens type)
{
	t_file	*node;

	node = ft_file_new(file_name, type);
	ft_lstadd_back_file(head, node);
	display_token((*head));
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
	t_lexer	*head;
	t_file	*file;
	char	*command;

	command = NULL;
	// t_command	*command_list;
	// command = NULL;
	head = data->lexer_list;
	// command_list = malloc(sizeof(t_command));
	// command_list = NULL;
	while (head)
	{
		if (head->tokens != WORD && head->tokens != PIPE)
		{
			file = NULL;
			if (head->tokens == REDIR_IN || head->tokens == REDIR_OUT ||
				head->tokens == HEREDOC || head->tokens == APPEND)
			{
				handel_token(&head, &file, head->tokens);
			}
			else
				head = head->next;
		}
		else if (head->tokens == WORD)
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
		else
			head = head->next;
	}
	printf("command = (%s)\n", command);
}
