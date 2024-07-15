/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:10:04 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/14 22:58:19 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minishell.h"

void	add_node(t_lexer **head, t_tokens type, char *str)
{
	t_lexer	*node;

	node = ft_lexer_new(str, type);
	ft_lstadd_back(head, node);
}

int	while_is_str(char *cmd, int i)
{
	while (cmd[i] != '\0' && cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != '<'
		&& cmd[i] != '>' && cmd[i] != '|' && cmd[i] != '"' && cmd[i] != '\'')
		i++;
	return (i);
}

int	is_string(t_tool *data, int i)
{
	char	*line;

	int (start), (end);
	start = i;
	if (data->cmd[i] == '"')
	{
		i++;
		while (data->cmd[i] != '\0' && data->cmd[i] != '"')
			i++;
		if (data->cmd[i])
			i++;
	}
	else if (data->cmd[i] == '\'')
	{
		i++;
		while (data->cmd[i] != '\0' && data->cmd[i] != '\'')
			i++;
		if (data->cmd[i])
			i++;
	}
	else
		i = while_is_str(data->cmd, i);
	end = i;
	line = ft_substr(data->cmd, start, end - start);
	return (add_node(&data->lexer_list, WORD, line), i);
}

int	add_whitespace(int i, t_tool **data)
{
	add_node(&(*data)->lexer_list, WHITESPACE, " ");
	while ((*data)->cmd[i] && ((*data)->cmd[i] == ' '
			|| (*data)->cmd[i] == '\t'))
		i++;
	if (!(*data)->cmd[i])
		return (-1);
	return (i);
}

void	lexer(t_tool *data)
{
	int	i;

	data->lexer_list = NULL;
	i = 0;
	while (data->cmd[i])
	{
		if (data->cmd[i] == ' ' || data->cmd[i] == '\t')
		{
			i = add_whitespace(i, &data);
			if (i == -1)
				break ;
		}
		else if (data->cmd[i] == '<' && data->cmd[i + 1] == '<')
			(add_node(&data->lexer_list, HEREDOC, "<<"), i += 2);
		else if (data->cmd[i] == '>' && data->cmd[i + 1] == '>')
			(add_node(&data->lexer_list, APPEND, ">>"), i += 2);
		else if (data->cmd[i] == '>' && data->cmd[i + 1] != '>')
			(add_node(&data->lexer_list, REDIR_OUT, ">"), i++);
		else if (data->cmd[i] == '<' && data->cmd[i + 1] != '<')
			(add_node(&data->lexer_list, REDIR_IN, "<"), i++);
		else if (data->cmd[i] == '|')
			(add_node(&data->lexer_list, PIPE, "|"), i++);
		else
			i = is_string(data, i);
	}
}
