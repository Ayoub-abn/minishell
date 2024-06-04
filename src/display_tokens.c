/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:55:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/04 18:02:18 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_token(t_tokens token)
{
	// printf("%d\n",token);
	if (token == 0)
		return ("WORD");
	else if (token == 1)
		return ("PIPE");
	else if (token == 2)
		return ("REDIR_IN");
	else if (token == 3)
		return ("REDIR_OUT");
	else if (token == 4)
		return ("HEREDOC");
	else if (token == 5)
		return ("APPEND");
	else if (token == 6)
		return ("WHITESPACE");
	return ("A");
}

// void	display_token(t_lexer *lexer)
// {
// 	// t_lexer *temp;
// 	// temp = lexer;
// 	while (lexer)
// 	{
// 		printf("value (%s) \t key (%s)\n", lexer->str,get_token(lexer->tokens));
// 		lexer = lexer->next;
// 	}
// }
// void	display_token_command(t_command *lexer)
// {
// 	// t_lexer *temp;
// 	// temp = lexer;
// 	while (lexer)
// 	{
// 		// printf("value (%s) \t key (%s)\n", lexer->str,get_token(lexer->tokens));
// 		 printf("command = %s \t file_name = %s file_type = %s \n",lexer->cmd,lexer->file_name,get_token(lexer->file_type));
// 		lexer = lexer->next;
// 	}
// }
void	display_token(t_file *file)
{
	while (file)
	{
		printf("file_name : (%s) \tfile_type(%s)\n",file->file_name,get_token(file->file_type));
		file = file->next;
	}
}
