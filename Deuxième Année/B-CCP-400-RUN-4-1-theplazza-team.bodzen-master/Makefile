##
## EPITECH PROJECT, 2021
## Project [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

RECEP 	= 	src/Reception/

KITCH	=	src/Kitchen/

COOK	=	src/Cookers/

IPC 	=	src/IPC/

SRC		= 	main.cpp \
			src/Pizza.cpp \
			src/Process.cpp \
			src/Parser.cpp \
			src/Clock.cpp \
			src/Utils.cpp \
			$(RECEP)Reception.cpp \
			$(KITCH)Kitchen.cpp \
			$(KITCH)Ticket.cpp \
			$(KITCH)Refill.cpp \
			$(COOK)Cookers.cpp \
			$(COOK)Furnace.cpp \
			$(IPC)MessageQueue.cpp \
			$(IPC)LogFile.cpp \
			$(IPC)SharedMem.cpp

CC		= 	g++

INC 	= 	-I ./

CFLAGS 	= 	-std=c++20 -W -Wall  -Wextra -pthread -g -I./include

NAME 	= plazza

all:	 $(NAME)

$(NAME):
		 $(CC) -o $(NAME) $(SRC) $(CFLAGS) $(INC)

clean:
		rm -rf *~
		rm -rf *vg*

fclean: clean
		rm -f $(NAME)

re: 	fclean all