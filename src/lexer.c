/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:10:04 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/25 00:17:48 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void add_node(t_lexer **head,int type,char *str)
{
    t_lexer *node;
    node = ft_lexer_new(str,type);
    ft_lstadd_back(head,node);
}

void lexer(t_tool *data)
{
    int i = 0;

    data->lexer_list = malloc(sizeof(t_lexer));
    if (!data->lexer_list)
        return;
    data->lexer_list->next = NULL;
    data->lexer_list->prev = NULL;
    data->lexer_list->str = NULL;
    data->lexer_list->type = 0;
    

    while (data->cmd[i] != '\0')
    {
        // Skip whitespace characters
        while (data->cmd[i] == ' ' || data->cmd[i] == '\t')
            i++;
        
        // Handle double character tokens (<<, >>)
        if (data->cmd[i] == '<' && data->cmd[i + 1] == '<')
        {
            // printf("hi %d\n", i);
            add_node(&data->lexer_list, HEREDOC, "<<");
            i += 2;
            continue;
        }
        if (data->cmd[i] == '>' && data->cmd[i + 1] == '>')
        {
            // printf("hi %d\n", i);
            add_node(&data->lexer_list, APPEND, ">>");
            i += 2;
            continue;
        }

        // Handle single character tokens (>, <)
        if (data->cmd[i] == '>')
        {
            // printf("hi %d\n", i);
            add_node(&data->lexer_list, REDIR_OUT, ">");
            i++;
            continue;
        }
        if (data->cmd[i] == '<')
        {
            // printf("hi %d\n", i);
            add_node(&data->lexer_list, REDIR_IN, "<");
            i++;
            continue;
        }
        if (data->cmd[i] == '|')
        {
            // printf("hi %d\n", i);
            add_node(&data->lexer_list, PIPE, "|");
            i++;
            continue;
        }

        // Increment to move to the next character
        i++;
    }
    
}


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