/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_loot_box.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:27:33 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/09 23:28:45 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// fun handle $"USER" ==> USER | if 1: echo $ | if 2:echo $ "a" != echo a
int	quote_after_dollar(t_lexer **lexer, int *i, char **str_to_expand)
{
	if (!(*lexer)->next)
	{
		*str_to_expand = "$";
		return (1);
	}
	if ((*lexer)->next->str[*i] == '"' || (*lexer)->next->str[*i] == '\'')
		(*lexer)->str = "";
	(*lexer) = (*lexer)->next;
	return (0);
}

void	probability_to_expand(t_lexer *lexer, t_env *env, int *i,
		char **str_to_expand)
{
	char	*key;
	char	*value;

	key = to_expand(&lexer->str[*i]);
	value = get_env_value(env, key);
	*i += ft_strlen(key) + 1;
	if (value)
		*str_to_expand = ft_strjoin(*str_to_expand, value);
}

void	dont_expand(t_lexer **lexer)
{
	while ((*lexer)->next && (*lexer)->tokens != WORD)
		(*lexer) = (*lexer)->next;
	(*lexer) = (*lexer)->next;
}
