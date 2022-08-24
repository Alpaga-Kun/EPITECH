# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Alpaga-Kun <teambodzen20@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 15:27:36 by Alpaga-Kun        #+#    #+#              #
#    Updated: 2022/08/24 16:33:52 by Alpaga-Kun       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BSQ			=	$(wildcard bsq/*.c) \
				$(wildcard bsq/*/*.c)

BINARY		= 	_bsq

OBJS		=	$(BSQ:.c=.o)

CC			=	gcc

INC			= 	-I includes/

CFLAGS		=	-W -Wextra -Werror -ansi -pedantic -std=gnu99 -g3 $(INC)

RM			=	rm -rf

all:		$(OBJS)
			$(CC) -o $(BINARY) main.c $(OBJS) $(CFLAGS) -g3

clean:
			$(RM) $(OBJS)
			$(RM) *vg*
			$(RM) *.gc*
			$(RM) .vscode

fclean:		clean
			$(RM) $(BINARY)

re:			fclean all

.PHONY:	all clean fclean re
