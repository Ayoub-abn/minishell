
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:11:39 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/31 20:42:28 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "./libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// #define WORD 1
// #define PIPE 2
// #define REDIR_IN 3
// #define REDIR_OUT 4
// #define HEREDOC 5
// #define APPEND 6

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}						t_list;

typedef enum e_num
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	WHITESPACE,
}						t_tokens;

typedef struct s_lexer
{
	char				*str;
	// int			type;
	t_tokens			tokens;
	// int			i;
	struct s_lexer		*next;
	// struct s_lexer	*prev;
}						t_lexer;

typedef struct s_file
{
	char				*file_name;
	// char		*del;
	t_tokens			file_type;
	struct s_file		*next;
}						t_file;

typedef struct s_command
{
	// char			*cmd;
	char				**cmd;
	t_file				*file;
	struct s_command	*next;
}						t_command;

typedef struct s_tool
{
	char				*cmd;
	char				**env;
	t_lexer				*lexer_list;
	t_command			*command;
}						t_tool;

////////////////////list//////////////
void					ft_lstadd_front(t_list **lst, t_list *new);
// t_list				*ft_lstnew(void *content);
// t_lexer				*ft_lexer_new(char *str,int type);
t_lexer					*ft_lexer_new(char *str, t_tokens type);
// t_command			*ft_command_new(char *command, char *file_name,
// 						t_type_command type);

// t_list				*ft_lstlast(t_list *lst);
t_lexer					*ft_lstlast(t_lexer *lst);
int						ft_lstsize(t_list *lst);
// void				ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_back(t_lexer **lst, t_lexer *new);
///////////////////////////////////////////////////////

char					**array_cpy(char **env);
void					command_line(char **command, t_list **head);
void					loop_minishell(t_tool *data);
//////////////////////lexer//////////////////////////
void					lexer(t_tool *data);
// void add_node(t_lexer **head, int type,char *str);
void					add_node(t_lexer **head, t_tokens type, char *str);
// void				display_token(t_lexer *lexer);
/////////////////////syntax_error///////////////////
int						check_quotes(t_lexer *head);
int						unexpected_token(t_lexer *head);
int						syntax_error(t_tool *data);
/////////////////////parser///////////////////////////
void					parser(t_tool *data);
t_file					*ft_file_new(char *file_name, t_tokens type);
t_command				*ft_command_new(char *command);
void					ft_lstadd_back_command(t_command **lst, t_command *new);
void					display_token(t_file *file);
void					ft_lstadd_back_file(t_file **lst, t_file *new);
char					*get_token(t_tokens token);
// void	display_token_command(t_command *command);
void	display_token_command(t_command *command,t_file *file);
#endif