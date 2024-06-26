
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
#include <stdbool.h>


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
	QUOTES
}						t_tokens;

typedef struct s_lexer
{
	char				*str;
	// bool				quote;
	t_tokens			tokens;
	struct s_lexer		*next;
}						t_lexer;
typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}						t_env;


///////////////////execute////////////
typedef struct s_file
{
	char				*file_name;
	t_tokens			file_type;
	struct s_file		*next;
}						t_file;

typedef struct s_command
{
	// char			*cmd;
	char				**cmd /*[0] =>command | [0 + 1] =>arg command*/;
	t_file				*file;
	struct s_command	*next;
}						t_command;
////////////////////////////////////////////


typedef struct s_tool
{
	char				*cmd;
	char				**env_copy;
	t_lexer				*lexer_list;
	t_command			*command;
	t_env				*env;
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
// void					loop_minishell(t_tool *data);
void	loop_minishell(t_tool *data,t_env *env);
// void					loop_minishell(t_tool *data,char **env);
//////////////////////lexer//////////////////////////
void					lexer(t_tool *data);
void	display_token_lexer(t_lexer *lexer);
// void add_node(t_lexer **head, int type,char *str);
void					add_node(t_lexer **head, t_tokens type, char *str);
// void				display_token(t_lexer *lexer);
/////////////////////syntax_error///////////////////
int						check_quotes(t_lexer *head);
int						unexpected_token(t_lexer *head);
int						syntax_error(t_tool *data);
/////////////////////parser///////////////////////////
// void					parser(t_tool *data);
// void	parser(t_lexer *data);
char *remove_quotes (char *arg);
// void	parser(t_lexer *data , t_command *command_list);
t_command	*parser(t_lexer *data);
t_file					*ft_file_new(char *file_name, t_tokens type);
t_command	*ft_command_new(char *command ,t_file *file);
// t_command				*ft_command_new(char *command);
void					ft_lstadd_back_command(t_command **lst, t_command *new);
void					display_token(t_file *file);
void					ft_lstadd_back_file(t_file **lst, t_file *new);
char					*get_token(t_tokens token);
// void	display_token_command(t_command *command);
void	display_token_command(t_command *command,t_file *file);
//////////////////////////////expand//////////////////////

t_env	*envp_to_list(char **envp);
// void expand(t_lexer *lexer);
void expand(t_lexer *lexer,t_env *env);
// void expand(t_tool *data);
t_env *ft_env_new(char *key,char *value);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
void aff(t_env *data);










#endif