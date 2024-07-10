NAME = minishell

CFLAG = -Wall -Wextra  -Werror  -g3 -fsanitize=address

LIBFT_SRC = ./libft/ft_atoi.c       ./libft/ft_bzero.c \
			./libft/ft_calloc.c     ./libft/ft_isalnum.c\
			./libft/ft_isalpha.c    ./libft/ft_isascii.c \
			./libft/ft_isdigit.c    ./libft/ft_isprint.c \
			./libft/ft_memchr.c     ./libft/ft_memcmp.c \
	  		./libft/ft_memcpy.c     ./libft/ft_memmove.c \
	  		./libft/ft_memset.c     ./libft/ft_strchr.c \
	  		./libft/ft_strdup.c     ./libft/ft_strjoin.c\
			./libft/ft_strlcat.c    ./libft/ft_strlcpy.c \
			./libft/ft_strlen.c     ./libft/ft_strncmp.c \
			./libft/ft_strnstr.c    ./libft/ft_strrchr.c \
			./libft/ft_substr.c     ./libft/ft_tolower.c \
			./libft/ft_toupper.c    ./libft/ft_strtrim.c \
			./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c\
 			./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c \
 			./libft/ft_strmapi.c    ./libft/ft_striteri.c \
 			./libft/ft_itoa.c       ./libft/ft_split.c\
			./libft/ft_strcmp.c ./libft/ft_split_sp.c\
			ft_lexer_new.c 		ft_lstsize_bonus.c ft_lstlast_bonus.c \
	   		ft_lstadd_back_bonus.c 	ft_lstadd_front_bonus.c\
			

# LIBFT_SRC = $(wildcard libft/*.c) $(wildcard src/*.c) $(wildcard *.c)

LIXER = src/lexer.c src/display_tokens.c syntax_error.c
PARSRE = src/parser.c 
EXPAND = src/env_linkedlist.c src/expand.c src/expand_loot_box.c
ADD = free_fun.c
FREE = ./gc/gc.c error_exit.c

SRC = main.c loop_minishell.c init.c ${ADD} ${FREE} ${LIBFT_SRC} ${LIXER} ${PARSRE} ${EXPAND}

OBG = ${SRC:.c=.o}

%.o: %.c
	@${CC} ${CFLAG} -c $< -o $@
	@echo "✅"

all: ${NAME}

${NAME} : ${OBG}
	@${CC} ${CFLAG} ${OBG} -lreadline -lhistory -o ${NAME}
	@echo "💯"
# @rm -f ${OBG} rm -f


clean:
	@rm -f ${OBG}
	@echo "🧹"

fclean: clean
	@rm -f ${NAME}
	@echo "🗑️"
re: fclean all
