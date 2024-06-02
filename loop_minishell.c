/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/02 23:09:25 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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
			{
				perror("syntax error");
				continue;
			}
			parser(data);
			// display_token(data->command->file);
			
			// display_token(data->lexer_list);
			// display_token_command(data->command);
		}
		// printf("%s\n", data->cmd);
		//handle signal dyal ctrl+D
	}
}