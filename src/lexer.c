/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:10:04 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/26 16:33:48 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_node(t_lexer **head, t_tokens type, char *str)
{
	t_lexer	*node;

	// printf("%d\n",type);
	// printf("str = %s\n",str);
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
    if(data->cmd[i] == 39)
    {
        i++;
        while (data->cmd[i] != '\0' && data->cmd[i] != 39)
            i++;
        i++;
    }
	else if (data->cmd[i] == 34)
	{
		i++;
        while (data->cmd[i] != '\0' && data->cmd[i] != 34)
            i++;
        i++;
	}
    else if(ft_isalpha(data->cmd[i]))
    {
        while (data->cmd[i] != '\0' 
				&& data->cmd[i] != ' '
				&& data->cmd[i] != '\t' 
				&& data->cmd[i] != '<'
				&& data->cmd[i] != '>'
				&& data->cmd[i] != '|'
				&& data->cmd[i] != 39
				&& data->cmd[i] != 34)
                i++;
    }
    end = i;
    line = ft_substr(data->cmd, start, end - start);
    // printf("line %s \n",line);
    add_node(&data->lexer_list, WORD, line);
	return (i);
}

void	lexer(t_tool *data)
{
	int		i;

	data->lexer_list = malloc(sizeof(t_lexer));
	if (!data->lexer_list)
		return ;
	data->lexer_list->next = NULL;
	data->lexer_list->prev = NULL;
	data->lexer_list->str = NULL;
	// data->lexer_list->tokens = 0;
	i = 0;
	while (data->cmd[i])
	{
		// Skip whitespace characters
		while (data->cmd[i] && (data->cmd[i] == ' ' || data->cmd[i] == '\t'))
			i++;
		// if (data->cmd[i] == 39 || data->cmd[i] == 34)
		// {
		// 	// printf("hi\n");
		//     i = is_string(data,i);
		// }
		// while (data->cmd[i] && (data->cmd[i] == ' ' || data->cmd[i] == '\t'))
		// 	i++;
		if (!data->cmd[i])
			break ;
		// Handle double character tokens (<<, >>)
		else if (data->cmd[i] == '<' && data->cmd[i + 1] == '<')
		{
			add_node(&data->lexer_list, HEREDOC, "<<");
			i += 2;
			// continue ;
		}
		else if (data->cmd[i] == '>' && data->cmd[i + 1] == '>')
		{
			add_node(&data->lexer_list, APPEND, ">>");
			i += 2;
			// continue ;
		}
		// Handle single character tokens (>, <)
		else if (data->cmd[i] == '>' && data->cmd[i + 1] != '>')
		{
			add_node(&data->lexer_list, REDIR_OUT, ">");
			i++;
			// continue ;
		}
		else if (data->cmd[i] == '<' && data->cmd[i + 1] != '<')
		{
			add_node(&data->lexer_list, REDIR_IN, "<");
			i++;
			// continue ;
		}
		else if (data->cmd[i] == '|')
		{
			add_node(&data->lexer_list, PIPE, "|");
			i++;
			// continue ;
		}
		// Handle string
		else
		{
			i = is_string(data,i);
			// continue ;
		}
		// Increment to move to the next character 
		// i++;
	}
}


///////////////ba9 khas n9ad 

// minishell$ "lsa  a" a
// value ((null)) 	 key (WORD)
// value ("lsa) 	 key (WORD)
// value () 	 key (WORD)
// value (a") 	 key (WORD)
// value (a) 	 key (WORD)


// t_lexer *lexer(char *line)
// {
//     while (line[i])
//     {
//         //skip_white_space(&i)
//         //is_pipe(&i)
//         //skip_white_space(&i)
//         //is_rederictions(&i);// > < >> <<
//         //skip_white_space(&i)
//         //is_command(&i);
//     }
// }