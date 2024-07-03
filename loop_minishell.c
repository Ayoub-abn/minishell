/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/04 00:04:20 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	loop_minishell(t_tool *data,t_env *env)
{
	// (void)data;
	(void)env;
	
	while (1)
	{
		data->cmd = readline("minishell$ ");
		if (ft_strlen(data->cmd) > 0)
		{
			add_history(data->cmd);
			lexer(data);
			if (syntax_error(data))
				continue;
			expand(data->lexer_list,env);
			// display_token_lexer(data->lexer_list);
			/* t_command *command_list =  */parser(data->lexer_list);
			
		}
		else if(!data->cmd)
			break;
	}
	// 	// printf("%s\n", data->cmd);
	// 	//handle signal dyal ctrl+D
	// }
	// expand(env);

}