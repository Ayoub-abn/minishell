/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:21:56 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/09 19:39:58 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_quotes(char *arg)
{
	int		i;
	int		j;
	char	quote_char;
	char	*str;

	if(arg == NULL)
		return("");
	i = 0;
	j = 0;
	str = malloc(ft_strlen(arg) * (sizeof(char) + 1));
	if (!str)
		return (NULL);
	while (arg[i])
	{
		if (arg[i] == '"' || arg[i] == '\'')
		{
			quote_char = arg[i];
			i++;
			while (arg[i] && arg[i] != quote_char)
				str[j++] = arg[i++];
			if (arg[i])
				i++; // Skip the closing quote
		}
		else
			str[j++] = arg[i++];
	}
	str[j] = '\0';
	return (str);
}

void	add_node_file(t_file **head, char *file_name, t_tokens type)
{
	t_file	*node;

	node = ft_file_new(file_name, type);
	ft_lstadd_back_file(head, node);
	// display_token((*head));
}
// void	add_node_command(t_command **head, char *command)
void	add_node_command(t_command **head,t_file **file_head, char *command)
{
	t_command	*node;
	// int i = 0;
	// printf("%s\n",remove_quotes(command));
	// node = ft_command_new(remove_quotes(command),(*file_head));
	node = ft_command_new(command,(*file_head));
	ft_lstadd_back_command(head, node);
	// display_token_command((*head));
}
void	handel_token(t_lexer **head, t_file **file, t_tokens type)
{
	char	*file_name;
	t_file	*node;

	(void)file;
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
	// add_node_file(file, file_name, type);
	node = ft_file_new(file_name, type);
	// printf("%s\n",node->file_name);
	// printf("%d\n",node->file_type);
	// free(file_name);
}

void	parser(t_lexer *data, t_command *command_list)
{
	t_lexer	*head;
	char	*command;
	t_file	*file;
	char *file_name;
	t_file *node;

	command = NULL;
	head = data;
	command_list = NULL;
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
						command = ft_strjoin(command, " ");
					head = head->next;
				}
			}
			else if (head->tokens != WORD)
			{
				if (head->tokens == REDIR_IN)
				{
					file_name = NULL;
					if (head->next && head->next->tokens == WHITESPACE)
						head = head->next;
					head = head->next;
					while (head && head->tokens == WORD)
					{
						// Skip any whitespace within the file name
						if (head->tokens == WHITESPACE)
							break ;
						// Append the current token's string to file_name
						file_name = ft_strjoin(file_name, head->str);
						// Move to the next token
						head = head->next;
					}
					node = ft_file_new(remove_quotes(file_name), REDIR_IN);
					ft_lstadd_back_file(&file, node);
				}
				else if (head->tokens == REDIR_OUT)
				{
					file_name = NULL;
					if (head->next && head->next->tokens == WHITESPACE)
						head = head->next;
					head = head->next;
					while (head && head->tokens == WORD)
					{
						// Skip any whitespace within the file name
						if (head->tokens == WHITESPACE)
							break ;
						// Append the current token's string to file_name
						file_name = ft_strjoin(file_name, head->str);
						// Move to the next token
						head = head->next;
					}
					node = ft_file_new(remove_quotes(file_name), REDIR_OUT);
					ft_lstadd_back_file(&file, node);
				}
				else if (head->tokens == HEREDOC)
				{
					file_name = NULL;
					if (head->next && head->next->tokens == WHITESPACE)
						head = head->next;
					head = head->next;
					while (head && head->tokens == WORD)
					{
						// Skip any whitespace within the file name
						if (head->tokens == WHITESPACE)
							break ;
						// Append the current token's string to file_name
						file_name = ft_strjoin(file_name, head->str);
						// Move to the next token
						head = head->next;
					}
					node = ft_file_new(remove_quotes(file_name), HEREDOC);
					ft_lstadd_back_file(&file, node);
				}
				else if (head->tokens == APPEND)
				{
					file_name = NULL;
					if (head->next && head->next->tokens == WHITESPACE)
						head = head->next;
					head = head->next;
					while (head && head->tokens == WORD)
					{
						// Skip any whitespace within the file name
						if (head->tokens == WHITESPACE)
							break ;
						// Append the current token's string to file_name
						file_name = ft_strjoin(file_name, head->str);
						// Move to the next token
						head = head->next;
					}
					node = ft_file_new(remove_quotes(file_name), APPEND);
					ft_lstadd_back_file(&file, node);
				}
				// if (head->tokens == REDIR_IN || head->tokens == REDIR_OUT ||
				// 	head->tokens == HEREDOC || head->tokens == APPEND)
				// {
				// 	handel_token(&head, &file, head->tokens);
				// 	// handel_token(&head, &command_list->file, head->tokens);
				// }
				else
					head = head->next;
			}
		}
		// add_node_command(&command_list, command);
		add_node_command(&command_list,&file ,command);
		command = NULL;
		file = NULL;
		if (head && head->tokens == PIPE)
		{
			head = head->next;
		}
	}
	display_token_command(command_list, file);
}
