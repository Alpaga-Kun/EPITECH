##
## EPITECH PROJECT, 2022
## B-PSU-400-RUN-4-1-malloc-team.bodzen
## File description:
## Makefile
##

CC			=	gcc

SRCS		=	$(wildcard *memory/*.c)

OBJS		=	$(SRCS:.c=.o)

LIBMEMORY 	=	 libmy_malloc.so

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -fPIC

all: 			$(LIBMEMORY)

$(LIBMEMORY):	$(OBJS)
				$(CC) -shared -o $(LIBMEMORY) $(OBJS) $(CFLAGS)

clean:
				$(RM) *~
				$(RM) *vg*
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(LIBMEMORY)

re: 			fclean all clean

.PHONY: 		all clean fclean re