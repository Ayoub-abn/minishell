/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:55:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/11 18:49:39 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minishell.h"

char	*get_token(t_tokens token)
{
	if (token == 0)
		return ("WORD");
	else if (token == 1)
		return ("PIPE");
	else if (token == 2)
		return ("REDIR_IN");
	else if (token == 3)
		return ("REDIR_OUT");
	else if (token == 4)
		return ("HEREDOC");
	else if (token == 5)
		return ("APPEND");
	else if (token == 6)
		return ("WHITESPACE");
	return ("A");
}

void	display_token_lexer(t_lexer *lexer)
{
	while (lexer)
	{
		printf("value (%s) \t key (%s)\n", lexer->str,get_token(lexer->tokens));
		lexer = lexer->next;
	}
}
void display_token_command(t_command *command,  t_file *file )
{
    (void) file;
    int node = 1;
    
        while (command)
        {
            printf("command[%d]:\n", node);

            if (command->cmd)
            {
                int i = 0;
                while (command->cmd[i])
                {
                    printf("\tcontent[%d]: %s\n", i + 1, command->cmd[i]);
            	    // file = file->next;
                    i++;
             
                }
            }
            while (command->file)
            {
                printf("\tfile name: %s \tfile type: %s\n", command->file->file_name,get_token(command->file->file_type));   
                command->file = command->file->next;
            }
            node++;
            command = command->next;
        }

}




