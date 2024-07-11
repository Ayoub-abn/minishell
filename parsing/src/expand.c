/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:50:49 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/11 18:49:49 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minishell.h"

char	*get_env_value(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(key, env->key) == 0)
			return (env->value);
		env = env->next;
	}
	return ("");
}

// Extract the key starting with '$' from the string
char	*to_expand(char *str)
{
	int	i;
	int	start;
	int	end;

	i = 1;
	start = i;
	while (str[i] && ft_isalnum(str[i]))
		i++;
	end = i;
	return (ft_substr(str, start, end - start));
}

int	iniesta(t_lexer **lexer, t_env *env, char **str_to_expand)
{
	int		i;
	char	tmp[2];

	i = 0;
	while ((*lexer)->str[i])
	{
		if (ft_strcmp((*lexer)->str, "$") == 0)
		{
			if (quote_after_dollar(lexer, &i, str_to_expand))
				break ;
		}
		if ((*lexer)->str[i] == '$' && (ft_isdigit((*lexer)->str[i + 1])
				&& (ft_strlen((*lexer)->str) > 2)))
			i += 2;
		else if ((*lexer)->str[i] == '$' && (ft_isalnum((*lexer)->str[i + 1])))
			probability_to_expand((*lexer), env, &i, str_to_expand);
		else
		{
			tmp[0] = (*lexer)->str[i++];
			tmp[1] = '\0';
			*str_to_expand = ft_strjoin(*str_to_expand, tmp);
		}
	}
	return (i);
}

// Function to expand variables in lexer tokens
// if $a="ls -al'" => should [ls] [-al']
void	expand(t_lexer *lexer, t_env *env)
{
	char	*str_to_expand;
	int		i;

	while (lexer)
	{
		i = 0;
		str_to_expand = NULL;
		if (lexer->tokens == HEREDOC)
		{
			dont_expand(&lexer);
			continue ;
		}
		else if (lexer->tokens == WORD && lexer->str[i] != '\'')
		{
			i = iniesta(&lexer, env, &str_to_expand);
			lexer->str = str_to_expand;
		}
		lexer = lexer->next;
	}
}
