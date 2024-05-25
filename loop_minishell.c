/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/25 18:14:19 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_quotes(t_tool *data)
{
	int i = 0;
	int s = 0;
	int d = 0;
	while (data->cmd[i])
	{
		if(data->cmd[i] == 34)
			d++;
		if(data->cmd[i] == 39)
			s++;
		i++;
	}
	if ((s > 0 && s % 2 != 0) || (d > 0 && d % 2 != 0) )
		return(1);
	return(0);
}
void	loop_minishell(t_tool *data)
{
	while (1)
	{
		  	// data->lexer_list->next = NULL;
    		// data->lexer_list->prev = NULL;
    		// data->lexer_list->str = NULL;
		data->cmd = readline("minishell$ ");
		if(ft_strlen(data->cmd) > 0)
			add_history(data->cmd);
		// if(check_quotes(data))
			// perror("syntax error");
		lexer(data);
		display_token(data->lexer_list);
		// printf("%s\n", data->cmd);
		//handle signal dyal ctrl+D
	}
}