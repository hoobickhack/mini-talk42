SRCS_serv = src/server.c 
SRCS_client = src/client.c 

OBJS_serv = ${SRCS_serv:.c=.o}
OBJS_client = ${SRCS_client:.c=.o}


SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./libft

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
GREEN = \033[38;5;85m


all : ${SERVER} ${CLIENT}

$(SERVER): $(OBJS_serv) 
	@${MAKE} --silent -C ${LIBFT}/
	@${CC} ${CFLAGS} ${OBJS_serv} ${LIBFT}/libft.a -o $(SERVER)
	@echo "${GRAS}${RED}[SERVER OK]${RESET}\n"

$(CLIENT): $(OBJS_client)
	@${MAKE} --silent -C ${LIBFT}/
	@${CC} ${CFLAGS} ${OBJS_client} ${LIBFT}/libft.a -o ${CLIENT}
	@echo "${GRAS}${RED}[CLIENT OK]${RESET}\n"

clean:

	@${MAKE} --silent clean -C ${LIBFT}
	@${RM} ${OBJS_serv} ${OBJS_client}  
	@echo "${ORANGE}${GRAS}\tNETTOYAGE 🛁${RESET}"
	@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean: clean
	@${RM} ${LIBFT}/libft.a
	@${RM} ${SERVER} ${CLIENT}
	@echo "${DARKBLUE}${ITALIQUE} -libft.a est supprimé${RESET}"
	@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimês${RESET}"

re: fclean all

.PHONY: all clean fclean re
