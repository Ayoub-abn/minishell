/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:19:58 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/02 16:17:57 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexer_new(char *str,t_tokens type)
{
	t_lexer	*new_node;
	// static int i; 

	new_node = malloc(sizeof(t_lexer));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str;
	new_node->tokens = type;
	// new_node->i = i++;
	new_node->next = NULL;
	// new_node->prev = NULL;
	return (new_node);
}
t_file	*ft_file_new(char *file_name,t_tokens type)
{
	t_file	*new_node;

	new_node = malloc(sizeof(t_file));
	if (new_node == NULL)
		return (NULL);
	new_node->file_name = file_name;
	new_node->file_type = type;
	new_node->next = NULL;
	// new_node->prev = NULL;
	return (new_node);
}