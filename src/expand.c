/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:50:49 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/30 23:38:50 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"

void expand(t_lexer *lexer, t_env *env)
{
    while (lexer)
    {
        if (lexer->tokens == WORD)
        {
            if(lexer->str[0] == '\'') // if First character is ' 
            {
                lexer = lexer->next; 
                continue;
            }
            else if(lexer->str[0] == '"') // if First character is "
                lexer->str = remove_quotes(lexer->str);
            if (lexer->str[0] == '$')
            {
                int i = 1;
                while (env)
                {
                    if (ft_strcmp(&lexer->str[i], env->key) == 0) // If matching environment variable was found
                    {
                        lexer->str = env->value;
                        break;
                    }
                    env = env->next;
                }
                if (env == NULL) // If no matching environment variable was found
                {
                    lexer->str = "";
                }
            }
        }
        lexer = lexer->next;
    }
}
