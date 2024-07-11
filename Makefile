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
			./libft/ft_strcmp.c \
			
			

UTILS = parsing/utils/ft_lexer_new.c parsing/utils/ft_lstsize.c parsing/utils/ft_lstlast.c parsing/utils/ft_lstadd_back.c 	parsing/utils/ft_lstadd_front.c
LIXER = parsing/src/lexer.c parsing/src/display_tokens.c parsing/src/syntax_error.c
PARSRE = parsing/src/parser.c parsing/src/parser_loot_box.c
EXPAND = parsing/src/env_linkedlist.c parsing/src/expand.c parsing/src/expand_loot_box.c
FREE = ./gc/gc.c ./gc/error_exit.c

SRC = main.c loop_minishell.c ${UTILS} ${FREE} ${LIBFT_SRC} ${LIXER} ${PARSRE} ${EXPAND}

OBG = ${SRC:.c=.o}

%.o: %.c
	@${CC} ${CFLAG} -c $< -o $@
	@echo "✅"

all: ${NAME}

${NAME} : ${OBG}
	@${CC} ${CFLAG} ${OBG} -lreadline -lhistory -o ${NAME}
	@echo "💯"


clean:
	@rm -f ${OBG}
	@echo "🧹"

fclean: clean
	@rm -f ${NAME}
	@echo "🗑️"
re: fclean all
