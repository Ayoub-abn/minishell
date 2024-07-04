/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:21:27 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/05 00:28:39 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int error(t_tokens error ,char error_char)
{
    if(error == QUOTES)
    {
        printf("bash: unexpected EOF while looking for matching `%c'\n",error_char);
        printf("bash: syntax error: unexpected end of file\n");
    }
    else if (error == PIPE && error_char == 'u')
    {
        printf("bash: syntax error: unexpected end of file\n");
        // exit(2);
    }
    else if (error == REDIR_IN)
        printf("bash: syntax error near unexpected token `newline'\n");
    else if(error == PIPE)
        printf("bash: syntax error near unexpected token `%c'\n",error_char);
    
    return(1);
}

int check_quotes(t_lexer *head)
{
    char quotes;
	while (head)
	{
        if(head->str[0] == '"' || head->str[0] == '\'')
        {
            quotes = head->str[0];
            //if str = ' or "               if last world is not " or ' 
            if(ft_strlen(head->str) == 1 || head->str[ft_strlen(head->str)- 1] != quotes)
				return(error(QUOTES,quotes));
        }
		head = head->next;
	}
	return(0);
}
int unexpected_token(t_lexer *head)
{
    // Loop until we find a (< ,<< ,> ,>> ,|)
    while (head)
    {
        if (head->tokens != WORD && head->tokens != WHITESPACE)
            break;
        head = head->next;
    }
    
    // If we reach the end of the list, there's no error
    if (!head)
        return 0;
    
    // Handle the case where the current token is a PIPE
    if (head->tokens == PIPE)
    {
        // A pipe cannot be the last token
        if (head->next == NULL)
            return(error(PIPE,'u'));
        
        // Skip any whitespace immediately following the pipe
        if (head->next->tokens == WHITESPACE)
            head = head->next;
        
        // A pipe cannot be followed only by whitespace
        if (head->next == NULL)
            return(error(PIPE,'u'));
        
        // Ensure the token after whitespace (if any) is not a pipe
        if (head->next->tokens == PIPE)
            return(error(PIPE,'u'));
    }
    // Handle the case for other special tokens
    else if (head->tokens != PIPE)
    {
        // Any other special token must be followed by a non-whitespace word
        if (head->next == NULL)
            return (error(REDIR_IN,'n'));
        
        // Skip any whitespace immediately following the special token
        if (head->next->tokens == WHITESPACE)
            head = head->next;
        
        // Ensure the token after whitespace (if any) is a word
        if (head->next == NULL || head->next->tokens != WORD)
        {
            if(head->next == NULL)
                return(error(PIPE,'|'));

            else if (head->next->tokens == WHITESPACE )
            {
                head = head->next;
                if(head->next == NULL)
                    return(error(REDIR_IN,'|'));
            }
            else if (head->next->tokens == PIPE )
            // mazl lkhedma hena
                return(error(PIPE,'|'));
        }
            
    }
    // If all checks pass, there is no unexpected token
    return 0;
}

// if fun return 1 ====>error 
// l << space ==> error 
// ls | ==>exit

int	syntax_error(t_tool *data)
{
	t_lexer	*head;

	head = data->lexer_list;
	//skip whitespace
	if(head->tokens == WHITESPACE)
		head = head->next;
	//check quotes
	if(check_quotes(head))
		return(1);
	//if the first node is pipe
	if(head->tokens == PIPE)
		return(error(PIPE,'|'));
	//Check other items
	while (head)
	{
		if(unexpected_token(head))
			return(1);
		head = head->next;
	}
	return(0);
}