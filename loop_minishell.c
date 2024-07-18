/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:06:45 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/18 20:39:19 by aabdenou         ###   ########.fr       */
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
int check_heredoc(char *cmd)
{
	int i = 0;
	while (cmd[i])
	{
		if(cmd[i] == '<' && cmd[i + 1] == '<')
			return(1);
		// if(!cmd[i + 1])
		// 	break;
		i++;
	}
	return(0);
	
}
void hayed_3liya(t_command **command)
{
    t_command *tmp = (*command);
	t_file	*tmp_file;
	while (tmp)
	{

		if (tmp->cmd)
		{
			int i = 0;
			while (tmp->cmd[i])
			{
				tmp->cmd[i] = remove_quotes(tmp->cmd[i]);
				i++;
			}
		}
		tmp_file = tmp->file;
		while (tmp_file)
		{
			tmp_file->file_name = remove_quotes(tmp_file->file_name);
			tmp_file = tmp_file->next;
		}
		tmp = tmp->next;
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
			// if(!check_heredoc(data->cmd))
				add_history(data->cmd);
			lexer(data);
			if (syntax_error(data))
			{
				printf("syntax error\n");
				continue ;
			}
			expand(data->lexer_list, env);
			// display_token_lexer(data->lexer_list);
			command_list = parser(data->lexer_list);
			if(ambiguous(command_list))
			{
				printf("ambiguous redirect\n");
				continue ;
			}
			hayed_3liya(&command_list);
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
