/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:11:39 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/25 00:01:34 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h> 
#include <unistd.h>
#include "./libft/libft.h"

#define WORD 0
#define PIPE 1
#define REDIR_IN 2
#define REDIR_OUT 3
#define HEREDOC 4
#define APPEND 5

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_lexer
{
	char    	*str;
	int			type;
	// int			i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct  s_tool
{
	char   *cmd;
    char    **env;
	t_lexer	*lexer_list;
	// char **command;
	// t_list *infile;
	// t_list *outfile;
	// t_list *heredoc;
	// t_list *append;
	
}	t_tool;


////////////////////list//////////////
void				ft_lstadd_front(t_list **lst, t_list *new);
// t_list				*ft_lstnew(void *content);
t_lexer				*ft_lexer_new(char *str,int type);
// t_list				*ft_lstlast(t_list *lst);
t_lexer				*ft_lstlast(t_lexer *lst);
int					ft_lstsize(t_list *lst);
// void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_back(t_lexer **lst, t_lexer *new);
///////////////////////////////////////////////////////

char **array_cpy(char **env);
void	command_line(char **command,t_list **head);
void	loop_minishell(t_tool *data);
//////////////////////lexer//////////////////////////
void lexer(t_tool *data);
void add_node(t_lexer **head, int type,char *str);
void display_token(t_lexer *lexer);

#endif