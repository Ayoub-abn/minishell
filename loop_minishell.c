/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/30 16:38:24 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	loop_minishell(t_tool *data,char **env)
{
	(void)data;
	// // (void)env;
	
	// while (1)
	// {
	// 	data->cmd = readline("minishell$ ");
	// 	if (ft_strlen(data->cmd) > 0)
	// 	{
	// 		add_history(data->cmd);
	// 		lexer(data);
	// 		if (syntax_error(data))
	// 		{
	// 			// display_token_lexer(data->lexer_list);
	// 			// perror("syntax error");
	// 			continue;
	// 		}
	// 		// display_token_lexer(data->lexer_list);
	// 		parser(data->lexer_list,data->command);
			
	// 	}
	// 	// printf("%s\n", data->cmd);
	// 	//handle signal dyal ctrl+D
	// }
	expand(env);
	// t_env *tmp;
    // while (head)
    // {
    //     tmp = head;
    //     head = head->next;
    //     free(tmp->key);
    //     free(tmp->value);
    //     free(tmp);
    // }
}