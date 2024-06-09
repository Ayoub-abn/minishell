/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:21:27 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/09 17:36:35 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				return(1);
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
            return 1;
        
        // Skip any whitespace immediately following the pipe
        if (head->next->tokens == WHITESPACE)
            head = head->next;
        
        // A pipe cannot be followed only by whitespace
        if (head->next == NULL)
            return 1;
        
        // Ensure the token after whitespace (if any) is not a pipe
        if (head->next->tokens == PIPE)
            return 1;
    }
    // Handle the case for other special tokens
    else if (head->tokens != PIPE)
    {
        // Any other special token must be followed by a non-whitespace word
        if (head->next == NULL)
            return 1;
        
        // Skip any whitespace immediately following the special token
        if (head->next->tokens == WHITESPACE)
            head = head->next;
        
        // Ensure the token after whitespace (if any) is a word
        if (head->next == NULL || head->next->tokens != WORD)
            return 1;
    }
    
    // If all checks pass, there is no unexpected token
    return 0;
}

// if fun return 1 ====>error 
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
		return(1);
	//Check other items
	while (head)
	{
		if(unexpected_token(head))
			return(1);
		head = head->next;
	}
	return(0);
}