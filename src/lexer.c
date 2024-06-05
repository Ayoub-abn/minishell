/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:10:04 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/04 23:38:14 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_node(t_lexer **head, t_tokens type, char *str)
{
	t_lexer	*node;
	node = ft_lexer_new(str, type);
	if (!node)
	{
		//memory problem
		return ;
	}
	ft_lstadd_back(head, node);
}
int	is_string(t_tool *data, int i)
{
	int		start;
	int		end;
	char	*line;

	start = i;
	//handel dabble quotes
    if(data->cmd[i] == 39)
    {
        i++;
        while (data->cmd[i] != '\0' && data->cmd[i] != 39)
            i++;
		//cmd[i] != '\0'
		if(data->cmd[i])
			i++;
    }
	//handel single quotes
	else if (data->cmd[i] == 34)
	{
		i++;
        while (data->cmd[i] != '\0' && data->cmd[i] != 34)
            i++;
		//cmd[i] != '\0'
		if(data->cmd[i])
			i++;
	}
    else
    {
        while (data->cmd[i] != '\0' && data->cmd[i] != ' '
				&& data->cmd[i] != '\t' && data->cmd[i] != '<'
				&& data->cmd[i] != '>' && data->cmd[i] != '|'
				&& data->cmd[i] != 39 && data->cmd[i] != 34)
                i++;
    }
    end = i;
    line = ft_substr(data->cmd, start, end - start);
    add_node(&data->lexer_list, WORD, line);
	return (i);
}

void	lexer(t_tool *data)
{
	int		i;

	data->lexer_list = malloc(sizeof(t_lexer));
	if (!data->lexer_list)
		return ;
	data->lexer_list = NULL;
	i = 0;
	while (data->cmd[i])
	{
		// handle whitespace characters
		if (data->cmd[i] == ' ' || data->cmd[i] == '\t')
		{
			add_node(&data->lexer_list, WHITESPACE, " ");
			while (data->cmd[i] && (data->cmd[i] == ' ' || data->cmd[i] == '\t'))
				i++;
			if (!data->cmd[i])
				break ;
		}
		// Handle double character tokens (<<, >>)
		else if (data->cmd[i] == '<' && data->cmd[i + 1] == '<')
		{
			add_node(&data->lexer_list, HEREDOC, "<<");
			i += 2;
		}
		else if (data->cmd[i] == '>' && data->cmd[i + 1] == '>')
		{
			add_node(&data->lexer_list, APPEND, ">>");
			i += 2;
		}
		// Handle single character tokens (>, <)
		else if (data->cmd[i] == '>' && data->cmd[i + 1] != '>')
		{
			add_node(&data->lexer_list, REDIR_OUT, ">");
			i++;
		}
		else if (data->cmd[i] == '<' && data->cmd[i + 1] != '<')
		{
			add_node(&data->lexer_list, REDIR_IN, "<");
			i++;
		}
		// Handle pipe token (|)
		else if (data->cmd[i] == '|')
		{
			add_node(&data->lexer_list, PIPE, "|");
			i++;
		}
		// Handle string
		else
			i = is_string(data,i);
	}
}
