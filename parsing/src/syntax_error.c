/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:21:27 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/15 16:06:07 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minishell.h"

int	check_whitespace(t_lexer **head)
{
	if ((*head)->next->tokens == WHITESPACE)
		(*head) = (*head)->next;
	if ((*head)->next == NULL)
		return (1);
	return (0);
}

int	after_pipe(t_lexer **head)
{
	if ((*head)->next == NULL)
		return (1);
	if (check_whitespace(head))
		return (1);
	// Ensure the token after whitespace (if any) is a word
	if ((*head)->next->tokens != WORD)
	{
		if ((*head)->next->tokens != WORD)
			return (1);
		if (((*head)->tokens == HEREDOC || (*head)->tokens == APPEND)
			&& ((*head)->next->tokens != WORD))
			return (1);
	}
	return (0);
}

int	check_quotes(t_lexer *head)
{
	char	quotes;

	while (head)
	{
		if (head->str[0] == '"' || head->str[0] == '\'')
		{
			quotes = head->str[0];
			// if str = ' or "               if last world is not " or '
			if (ft_strlen(head->str) == 1 || head->str[ft_strlen(head->str)
					-1] != quotes)
				return (1);
		}
		head = head->next;
	}
	return (0);
}

int	unexpected_token(t_lexer *head)
{
	while (head)
	{
		if ((head->tokens != WORD && head->tokens != WHITESPACE))
			break ;
		head = head->next;
	}
	if (!head)
		return (0);
	if (head->tokens == PIPE)
	{
		if (head->next == NULL)
			return (1);
		if (check_whitespace(&head))
			return (1);
		if (head->next->tokens == PIPE)
			return (1);
	}
	// Handle the case for other special tokens
	else if (head->tokens != PIPE)
	{
		if (after_pipe(&head))
			return (1);
	}
	return(0);
}

int ambiguous(t_command *command)
{
	t_command *tmp = command;
	t_file	*tmp_file;
	int i ;
    while (tmp)
	{
		tmp_file = tmp->file;
		while (tmp_file)
		{
			i = 0;
			if(ft_strcmp(tmp_file->file_name,"") == 0)
				return(1);
			while (tmp_file->file_name[i])
			{
				if(tmp_file->file_name[i] == ' ' && tmp_file->file_name[i + 1] && tmp_file->quotes == false)
					return(1);
				i++;
			}
			tmp_file = tmp_file->next;
		}
		tmp = tmp->next;
	}
	return(0);
}

int	syntax_error(t_tool *data)
{
	t_lexer	*head;

	head = data->lexer_list;
	if (head->tokens == WHITESPACE)
		head = head->next;
	if (!head)
		return (0);
	if (check_quotes(head))
		return (1);
	if (head->tokens == PIPE)
		return (1);
	while (head)
	{
		if (unexpected_token(head))
			return (1);
		head = head->next;
	}
	return (0);
}

//
