##
## EPITECH PROJECT, 2020
## main Makefile
## File description:
## root
##

CC	=	gcc

SRC_S	=	server/option/create.c		\
			server/option/help.c		\
			server/option/info.c		\
			server/option/list.c		\
			server/option/login.c		\
			server/option/logout.c		\
			server/option/messages.c	\
			server/option/send.c		\
			server/option/subscribe.c	\
			server/option/subscribed.c	\
			server/option/subscribed_bis.c	\
			server/option/unsubscibe.c	\
			server/option/use.c			\
			server/option/user.c		\
			server/option/users.c		\
			server/commands.c			\
			server/main.c				\
			server/socket.c				\
			server/storage.c			\
			utils/totab.c				\
			utils/read.c				\
			utils/utils.c

SRC_CLI	=	client/option/create.c		\
			client/option/help.c		\
			client/option/info.c		\
			client/option/list.c		\
			client/option/login.c		\
			client/option/logout.c		\
			client/option/messages.c	\
			client/option/send.c		\
			client/option/subscribe.c	\
			client/option/subscribed.c	\
			client/option/unsubscribe.c	\
			client/option/use.c			\
			client/option/user.c		\
			client/option/users.c		\
			client/commands.c			\
			client/connect.c			\
			client/main.c				\
			client/run.c				\
			client/toupper.c			\
			utils/totab.c				\
			utils/read.c				\
			utils/utils.c

SRC_TEST=

OBJ	=	$(SRC_S:.c=.o)
OBJ_CLI	=	$(SRC_CLI:.c=.o)

INC	=	-I include/

CRITFLAGS=	-lcriterion --coverage

CFLAGS	=	-W -Wall -Wextra -Werror -g3 $(INC)

NAME_S	=	myteams_server

NAME_CLI=	myteams_cli

NAME_TEST=	unit_tests

all: $(OBJ) $(OBJ_CLI)

	$(CC) -o $(NAME_CLI) $(OBJ_CLI) $(CFLAGS) -luuid -L ./libs/myteams -lmyteams
	$(CC) -o $(NAME_S) $(OBJ) $(CFLAGS) -luuid -L ./libs/myteams -lmyteams

tests_run: fclean
	gcc -o $(NAME_TEST) $(SRC_TEST) $(INC) $(CFLAGS) $(CRITFLAGS)
	./$(NAME_TEST) --verbose
	gcovr --exclude ./tests
	gcovr -b --exclude ./tests

clean:
	rm -rf *~
	rm -rf src/*~
	rm -rf tests/*~
	rm -rf include/*~
	rm -rf *.gc*

fclean: clean
	rm -rf $(NAME_S)
	rm -rf $(NAME_CLI)
	rm -f $(NAME_TEST)
	rm -f $(OBJ)
	rm -f $(OBJ_CLI)

re: fclean all
