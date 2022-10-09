# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arupert <arupert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:38:49 by arupert           #+#    #+#              #
#    Updated: 2022/04/04 13:59:17 by arupert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= ft_split.c \
			  libft.c \
			  parser.c \
			  pipex.c \
			  main.c

OBJS		= $(SRC_FILES:.c=.o)

HEADER		= pipex.h

NAME		= pipex

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

.PHONY:		all clean fclean re

%.o:		%.c $(HEADER) Makefile
			$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)
	
re:			fclean all
