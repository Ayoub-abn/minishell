/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:50:49 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/02 17:31:32 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"

// char **semi_key(char *str) 
// {
//     char ** list = ft_split_sp(str,"$'\" ");
//     // int i = 0;
//     // while (list[i])
//     // {
//     //     printf("hi [%s]\n",list[i++]);
//     // }
    
//     // // int i = 0;
//     // // i++;
//     // // int start = i;
//     // // char **key;
//     // // while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '\t' && str[i] != ' ' )
//     // //     i++;
//     // // key[0] = ft_substr(str, start, i-1);
//     // // if(str[i] != '\'' || str[i] != '"' || str[i] != '\t' || str[i] != ' ')
//     // // {
//     // //     i++;
//     // //     key[1] = 
//     // // }
//     // // char *line  = ft_substr(str, start, i-1);
//     return list; 
// }
char *to_expand(char *str)
{
    char *key;
    int i = 1;
    int start = i;
    while (str[i])
    {
        if(ft_isalpha(str[i]))
            i++;
        else
            break;
    }
    int end = i - 1;
    key = ft_substr(str,start,end);
    
    // printf("hi: %c\n",str[i-1]);
    return(key);
}
void expand(t_lexer *lexer, t_env *env)
{
    (void)env;
    // char **list;
    int i = 0;
    char *key;
    while (lexer)
    {
        if (lexer->tokens == WORD)
        {
            if(lexer->str[0] == '\'') // if First character is ' 
            {
                lexer = lexer->next; 
                continue;
            }
            i = 0;
            while (lexer->str[i])
            {
                if(lexer->str[i] == '$')
                {
                    char *str = lexer->str; 
                    // printf("%s----------\n",str);
                    key = to_expand(&lexer->str[i]);
                    while (env)
                    {
                        if (ft_strcmp(key, env->key) == 0) // If matching environment variable was found
                        {
                            lexer->str = env->value;
                            break;
                        }
                        if (env == NULL) // If no matching environment variable was found
                        {
                            lexer->str = "";
                            break;
                        }
                        env = env->next;
                    }
                }
                i++;
            }
            // printf("%s\n",key);
            
            // else if(lexer->str[0] == '"')
            // {
            //     list = semi_key(lexer->str);
            //     // i = 0;
            //     // while (list[i])
            //     // {
            //         if(list[0][0] == '$')
            //              lexer->str = list[0];
            //         // i++;
            //     // }
                
            // } // if First character is "
            // printf("%s\n",lexer->str);
            
            // if (lexer->str[0] == '$')
            // {
            //     int i = 1;
            //     char *to_expand;
            //     to_expand()
            //     while (env)
            //     {
            //         if (ft_strcmp(&lexer->str[i], env->key) == 0) // If matching environment variable was found
            //         {
            //             lexer->str = env->value;
            //             break;
            //         }
            //         env = env->next;
            //     }
            //     if (env == NULL) // If no matching environment variable was found
            //     {
            //         lexer->str = "";
            //     }
            // }
        }
        lexer = lexer->next;
    }
}
