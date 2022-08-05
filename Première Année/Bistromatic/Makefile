# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 18:03:34 by Alpaga-Kun        #+#    #+#              #
#    Updated: 2022/08/04 20:16:51 by Alpaga-Kun       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPERAND 	=	$(wildcard Addition/*.c) 		\
				$(wildcard Addition/*/*.c) 		\
				$(wildcard Subtraction/*.c) 	\
				$(wildcard Subtraction/*/*.c)	\
				$(wildcard Multiplication/*.c) 	\
				$(wildcard Multiplication/*/*.c)\
				$(wildcard Division/*.c) 		\
				$(wildcard Division/*/*.c) 		\
				$(wildcard tools/*.c)

ADD			=	$(wildcard Addition/*.c) \
				$(wildcard Addition/*/*.c)

SUB 		=	$(wildcard Subtraction/*.c) \
				$(wildcard Subtraction/*/*.c)

MUL			=	$(wildcard Multiplication/*.c) \
				$(wildcard Multiplication/*/*.c)

DIV 		=	$(wildcard Division/*.c) \
				$(wildcard Division/*/*.c)

TOOLS		=	$(wildcard tools/*.c)

BINARY		= 	bistromatic

OBJS		=	$(OPERAND:.c=.o)

CC			=	gcc

INC			= 	-I includes/

CFLAGS		=	-W -Wextra -Werror -ansi -pedantic -std=gnu99 -g3 $(INC)

RM			=	rm -f

all:		$(OBJS)
			$(CC) -o $(BINARY) main.c $(OBJS) $(CFLAGS)

clean:
			$(RM) $(OBJS)
			$(RM) *vg*
			$(RM) *.gc*

fclean:		clean
			$(RM) $(BINARY)

re:			fclean all

.PHONY:	all clean fclean re
