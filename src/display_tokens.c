/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:55:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/25 00:02:35 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_token(int token)
{
    char *str[6];
    str[0] = "WORD";
    str[1] = "PIPE";
    str[2] = "REDIR_IN";
    str[3] = "REDIR_OUT";
    str[4] = "HEREDOC";
    str[5] = "APPEND";
    return (str[token]);
}

void display_token(t_lexer *lexer)
{
    t_lexer *temp;
    
    temp = lexer;
    while(temp)
    {
        printf("value (%s) \t key (%s)\n",temp->str, get_token(temp->type));
        temp = temp->next;
    }
}
