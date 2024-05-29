/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/29 14:57:15 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_quotes(t_lexer *head)
{
	while (head)
	{
		if(head->str[0] == '"')
		{
			if(ft_strlen(head->str) == 1 || head->str[ft_strlen(head->str)				- 1] != '"')
				return(1);
		}
		if(head->str[0] == '\'')
		{
			if(ft_strlen(head->str) == 1 || head->str[ft_strlen(head->str)		- 1] != '\'')
				return(1);
		}
		head = head->next;
	}
	return(0);
}
// if fun return 1 ====>error 
int unexpected_token(t_lexer *head)
{
	//Continuing loop Until you find (<,<<,>,>>,|)
	while (head)
	{
		if(head->tokens != WORD && head->tokens != WHITESPACE )
			break;
		head = head->next;
	}
	if(!head)
		return(0);
	else 
	{
		//nothing after the token
		if(head->next == NULL)
			return(1);
		//skip space
		if (head->next->tokens == WHITESPACE)
			head = head->next;
		//nothing after space
		if(head->next == NULL)
			return(1);
		//check if node after space is not a word 
		if (head->next->tokens != WORD)
			return (1);
	}
	return(0);
}
// if fun return 1 ====>error 
int	syntax_error(t_tool *data)
{
	t_lexer	*head;

	head = data->lexer_list;
	//skype whitespace
	if(head->tokens == WHITESPACE)
		head = head->next;
	//check quotes
	if(check_quotes(head))
		return(1);
	//if the first node is pipe
	if(head->tokens == PIPE)
		return(1);
	//Check other items
	while (head)
	{
		if(unexpected_token(head))
			return(1);
		head = head->next;
	}
	return(0);
}
void	loop_minishell(t_tool *data)
{
	while (1)
	{
		data->cmd = readline("minishell$ ");
		if (ft_strlen(data->cmd) > 0)
		{
			add_history(data->cmd);
			lexer(data);
			if (syntax_error(data))
				perror("syntax error");
			// display_token(data->lexer_list);
		}
		// printf("%s\n", data->cmd);
		//handle signal dyal ctrl+D
	}
}