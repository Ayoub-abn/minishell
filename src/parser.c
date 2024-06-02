/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:21:56 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/02 22:53:42 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_node_file(t_file **head, char *file_name, t_tokens type)
{
	t_file	*node;

	node = ft_file_new(file_name, type);
	// printf("(%s) (%d)\n", node->file_name, node->file_type);
	// printf("file_name : (%s) \tfile_type(%s)\n",node->file_name,get_token(node->file_type));
	ft_lstadd_back_file(head, node);
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

void	display_token(t_file *file)
{
	// t_lexer *temp;
	// temp = lexer;
	while (file)
	{
		printf("file_name : (%s) \tfile_type(%s)\n",file->file_name,get_token(file->file_type));
		file = file->next;
	}
}

void	parser(t_tool *data)
{
	t_lexer	*head;
	t_file	*file;
	// char	*file_name;

	// char	*command;
	// t_command	*command_list;
	// command = NULL;
	head = data->lexer_list;
	// command_list = malloc(sizeof(t_command));
	// command_list = NULL;
	while (head)
	{
		// if (head->tokens == WORD)
		//     {
		//         while (head /* || head->next->tokens != WORD
		//			|| head->next->tokens != WHITESPACE */)
		//         {
		//             if(head == WORD)
		//             {
		//                 command = ft_strjoin(command, head->str);
		//                 if (head->next == NULL)
		//                      break ;
		//                 if (head->next->tokens == WHITESPACE)
		//                     command = ft_strjoin(command, " ");
		//             }
		//             head = head->next;
		//         }
		//     }
		if (head->tokens != WORD && head->tokens != PIPE)
		{
			file = NULL;
			if (head->tokens == REDIR_IN)
			{
				
				handel_token(&head, &file, REDIR_IN);
				// file_name = NULL;
				// if (head->next && head->next->tokens == WHITESPACE)
				// 	head = head->next;
				// head = head->next;
				// while (head && head->tokens == WORD)
				// {
				// 	// Skip any whitespace within the file name
				// 	if (head->tokens == WHITESPACE)
				// 		break ;
				// 	// Append the current token's string to file_name
				// 	file_name = ft_strjoin(file_name, head->str);
				// 	// Move to the next token
				// 	head = head->next;
				// }
				// add_node_file(&file, file_name, REDIR_IN);
				// free(file_name);
				continue ;
			}
			if(head->tokens == REDIR_OUT)
			{
				handel_token(&head, &file, REDIR_OUT);
				continue;
			}
			if(head->tokens == HEREDOC)
			{
				handel_token(&head, &file, HEREDOC);
				continue;
			}
			if(head->tokens == APPEND)
			{
				handel_token(&head, &file, APPEND);
				continue;
			}
			display_token(file);
		}
		head = head->next;
	}
}
