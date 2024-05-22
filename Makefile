NAME = minishell

# CFLAG = -Wall -Wextra -Werror

SRC = main.c abn.c

OBG = ${SRC:.c=.o}

%.o: %.c
	@${CC} ${CFLAG} -c $< -o $@
	@echo "✅"

all: ${NAME}

${NAME} : ${OBG}
	@${CC} ${CFLAG} ${OBG} -lreadline -lhistory -o ${NAME}
	@rm -f ${OBG}
	@echo "💯"


clean:
	@rm -f ${OBG}
	@echo "🧹"

fclean: clean
	@rm -f ${NAME}
	@echo "🗑️"

