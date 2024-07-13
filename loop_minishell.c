/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/12 22:00:51 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void nongnu(int i)
{
    if (i == SIGINT)
    {
        write(0,"\n", 1 );
        rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
    }
}
void	loop_minishell(t_tool *data, t_env *env)
{
	t_command	*command_list;

	signal(SIGINT, nongnu);
    signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		data->cmd = readline("minishell$ ");
		if (ft_strlen(data->cmd) > 0)
		{
			add_history(data->cmd);
			lexer(data);
			// if (syntax_error(data))
			// {
			// 	printf("syntax error\n");
			// 	continue ;
			// }
			expand(data->lexer_list, env);
			// display_token_lexer(data->lexer_list);
			command_list = parser(data->lexer_list);
			// display_token_command(command_list);
			// if(ambiguous(command_list))
			// {
			// 	printf("syntax error1\n");
			// 	continue ;
			// }
			display_token_command(command_list);
			
			
			free(data->cmd);
		}
		else if (!data->cmd)
		{
			_free();
			// ba9i leak
			break ;
		}
	}
}
