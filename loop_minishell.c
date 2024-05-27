/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/26 22:01:30 by aabdenou         ###   ########.fr       */
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
		data->cmd = readline("minishell$ ");
		if(ft_strlen(data->cmd) > 0)
		{
			add_history(data->cmd);
			lexer(data);
			display_token(data->lexer_list);
		}
		// if(check_quotes(data))
			// perror("syntax error");
		// printf("%s\n", data->cmd);
		//handle signal dyal ctrl+D
	}
}