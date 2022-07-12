##
## EPITECH PROJECT, 2022
## B-CCP-400-RUN-4-1-panoramix-team.bodzen
## File description:
## Makefile
##

PANORAMIX	=	$(wildcard *srcs/*.c)

BINARY		=	panoramix

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

INC			=	-I ./includes

all:
				$(CC) -o $(BINARY) $(PANORAMIX) $(CFLAGS) -lpthread

clean:
				$(RM) *~
				$(RM) *vg*

fclean: 		clean
				$(RM) $(BINARY)

re: 			fclean all clean

.PHONY: 		all clean fclean re
