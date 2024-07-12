/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:11:39 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/12 16:14:09 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include "./gc/gc.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
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
	QUOTES
}						t_tokens;

typedef struct s_lexer
{
	char				*str;
	t_tokens			tokens;
	struct s_lexer		*next;
}						t_lexer;
typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
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
	char				**cmd;
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
t_lexer					*ft_lexer_new(char *str, t_tokens type);
t_lexer					*ft_lstlast(t_lexer *lst);
int						ft_lstsize(t_list *lst);
void					ft_lstadd_back(t_lexer **lst, t_lexer *new);
//////////////////////////main///////////////////////
void					loop_minishell(t_tool *data, t_env *env);
//////////////////////lexer//////////////////////////
void					lexer(t_tool *data);
void					display_token_lexer(t_lexer *lexer);
void					add_node(t_lexer **head, t_tokens type, char *str);
/////////////////////syntax_error///////////////////
int						check_quotes(t_lexer *head);
int						syntax_error(t_tool *data);
int						ambiguous(t_command *command);
/////////////////////parser///////////////////////////
char					*remove_quotes(char *arg);
t_command				*parser(t_lexer *data);
void					add_node_command(t_command **head, t_file **file_head,
							char *command);
void					xavi(t_lexer **head, char **command, t_file **file);
void					handel_token(t_lexer **head, t_file **file,
							t_tokens type);
t_file					*ft_file_new(char *file_name, t_tokens type);
t_command				*ft_command_new(char *command, t_file *file);
void					ft_lstadd_back_command(t_command **lst, t_command *new);
void					display_token(t_file *file);
void					ft_lstadd_back_file(t_file **lst, t_file *new);
char					*get_token(t_tokens token);
void					display_token_command(t_command *command);
void					add_node_file(t_file **head, char *file_name,
							t_tokens type);
//////////////////////////////expand//////////////////////

t_env					*envp_to_list(char **envp);
void					expand(t_lexer *lexer, t_env *env);
t_env					*ft_env_new(char *key, char *value);
void					ft_lstadd_back_env(t_env **lst, t_env *new);
void					aff(t_env *data);
int						quote_after_dollar(t_lexer **lexer, int *i,
							char **str_to_expand);
void					probability_to_expand(t_lexer *lexer, t_env *env,
							int *i, char **str_to_expand);
void					dont_expand(t_lexer **lexer);
char					*to_expand(char *str);
char					*get_env_value(t_env *env, char *key);
///////////////////////////////free///////////////////////

#endif