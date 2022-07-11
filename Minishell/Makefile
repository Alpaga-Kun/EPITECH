# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 19:40:13 by Alpaga-Kun        #+#    #+#              #
#    Updated: 2022/07/10 21:50:07 by Alpaga-Kun       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL	=	$(wildcard minishell/*.c)
MINISHELL	=	$(wildcard minishell/*/*.c)

BINARY		= 	shell

OBJS		=	$(MINISHELL:.c=.o)

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
