/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:55:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/07 16:44:22 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_token(t_tokens token)
{
	// printf("%d\n",token);
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

// void	display_token(t_lexer *lexer)
// {
// 	// t_lexer *temp;
// 	// temp = lexer;
// 	while (lexer)
// 	{
// 		printf("value (%s) \t key (%s)\n", lexer->str,get_token(lexer->tokens));
// 		lexer = lexer->next;
// 	}
// }
// void	display_token_command(t_command *lexer)
// {
// 	// t_lexer *temp;
// 	// temp = lexer;
// 	while (lexer)
// 	{
// 		// printf("value (%s) \t key (%s)\n", lexer->str,get_token(lexer->tokens));
// 		 printf("command = %s \t file_name = %s file_type = %s \n",lexer->cmd,lexer->file_name,get_token(lexer->file_type));
// 		lexer = lexer->next;
// 	}
// }
void	display_token(t_file *file)
{
	while (file)
	{
		printf("file_name : (%s) \tfile_type(%s)\n",file->file_name,get_token(file->file_type));
		file = file->next;
	}
}

// void display_token_command(t_command *command,t_file *file)
// {
// 	(void) file;
//     int node = 1;
// 	// t_file *file = command->file;

// 	// while(file)
// 	// {
// 	// 	// printf("\t file name %s\n",file->file_name);
// 	// 	printf("\t file type %s\n",get_token(file->file_type));
// 	// 	file = file->next;
// 	// }

// 	// if(file->file_name)
// 	// 	printf("hi\n");

//     while (command)
//     {
//         printf("command[%d]:\n", node);
// 		printf("\t file name %s\n",get_token(command->file->file_type));
//         int i = 0;
//         while (command->cmd[i])
//         {
//             printf("\tcontent[%d]: %s\n", i + 1, command->cmd[i]);
//             i++;
//         }
//         node++;
//         command = command->next;
//     }
// }
void display_token_command(t_command *command, t_file *file)
{
    // t_file *current_file = file;
    int node = 1;

    // if (command)
    // {
        while (command)
        {
            printf("command[%d]:\n", node);

            if (command->cmd)
            {
                int i = 0;
                while (command->cmd[i])
                {
                    printf("\tcontent[%d]: %s\n", i + 1, command->cmd[i]);
                    i++;
                }
            }
			while (file)
       		{
            	printf("\tfile type: %s\n", get_token(file->file_type));
            	// Uncomment the following line if you need to display the file name as well
            	// printf("\tfile name: %s\n", file->file_name);
            	file = file->next;
        	}
            node++;
            command = command->next;
        }
    // }
    // else
    // {
    //     printf("\tNo commands present\n");
    // }

    // if (file)
    // {
        while (file)
        {
            printf("\tfile type: %s\n", get_token(file->file_type));
            // Uncomment the following line if you need to display the file name as well
            // printf("\tfile name: %s\n", file->file_name);
            file = file->next;
        }
    // }
    // else
    // {
    //     printf("\tNo files associated\n");
    // }
}




