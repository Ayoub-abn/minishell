/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/08 17:42:59 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	loop_minishell(t_tool *data,t_env *env)
{
	// (void)data;
	// (void)env;
	t_command *command_list;
	
	while (1)
	{
		data->cmd = readline("minishell$ ");
		if (ft_strlen(data->cmd) > 0)
		{
			add_history(data->cmd);
			lexer(data);
			if (syntax_error(data))
			{
				free_link_list(&data->lexer_list);
				continue;
			}
			expand(data->lexer_list,env);
			// display_token_lexer(data->lexer_list);
			command_list = parser(data->lexer_list);
			
		}
		else if(!data->cmd)
		{
			// free_link_list_parser(&command_list);
			// free_link_list(&data->lexer_list);
			// free_link_list_env(&env);
			break;
		}
	}
	// 	// printf("%s\n", data->cmd);
	// 	//handle signal dyal ctrl+D
	// }
	// expand(env);

}
