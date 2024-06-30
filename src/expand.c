/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:50:49 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/01 00:52:25 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"

char *semi_key(char *str) {
    int i = 0;
    i++;
    int start = i;
    while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '\t' && str[i] != ' ' )
        i++;
    char *line  = ft_substr(str, start, i-1);
    // if (line != NULL) {
    //     printf("%s\n", line); // Print the result
    // }
    return line; 
}
void expand(t_lexer *lexer, t_env *env)
{
    (void)env;
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
                lexer->str = semi_key(lexer->str);
            // printf("%s\n",lexer->str);
            
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
