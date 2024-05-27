/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:55:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/27 12:11:05 by aabdenou         ###   ########.fr       */
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
	return ("A");
	// char *str[6];
	// str[0] = "WORD";
	// str[1] = "PIPE";
	// str[2] = "REDIR_IN";
	// str[3] = "REDIR_OUT";
	// str[4] = "HEREDOC";
	// str[5] = "APPEND";
	// return (str[token]);
}

void	display_token(t_lexer *lexer)
{
	// t_lexer *temp;
	// temp = lexer;
	while (lexer)
	{
		printf("value (%s) \t key (%s)\n", lexer->str,get_token(lexer->tokens));
		lexer = lexer->next;
	}
}
