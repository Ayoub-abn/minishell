/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/27 19:59:49 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_quotes(t_tool *data)
{
	t_lexer *head = data->lexer_list;

	// int s = 0;
	// int d = 0;


	while (head)
	{
		if(head->str[0] == '"')
		{
			if(head->str[ft_strlen(head->str) - 1] != '"')
				return(1);
			// printf("%c\n",head->str[ft_strlen(head->str) - 1]);
		}
		if(head->str[0] == '\'')
		{
			if(head->str[ft_strlen(head->str) - 1] != '\'')
				return(1);
		}
		// while (head->str[i])
		// {
		// 	if(head->str[i] == '"')
		// 		s++;
		// 	else if (head->str[i] == '\'')
		// 		d++;
		// 	i++;
		// }
		// if ((s % 2 == 0 && s > 0) || (d % 2 == 0 && d > 0))
		// 	return(0);
		head = head->next;
	}
	return(0);
	
}
void	loop_minishell(t_tool *data)
{
	while (1)
	{
		data->cmd = readline("minishell$ ");
		if(ft_strlen(data->cmd) > 0)
		{
			add_history(data->cmd);
			lexer(data);
			// display_token(data->lexer_list);
		}
		if(check_quotes(data))
			perror("syntax error");
		// printf("%s\n", data->cmd);
		//handle signal dyal ctrl+D
	}
}