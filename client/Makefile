# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 16:37:03 by sboeuf            #+#    #+#              #
#    Updated: 2014/02/09 16:37:05 by sboeuf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

NAME		= client

INCLUDE		= ../includes/

SRCS		= main.c			\

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -g
CLFLAGS     += -L ../libft -lft
LDFLAGS 	= -I $(DIR_LIBFT)/includes

DIR_LIBFT	= ../libft

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -I $(INCLUDE) -L -lft

$(NAME): $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CLFLAGS) $(CFLAGS) $(LDFLAGS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

$(DIR_LIBFT)/libft.a:
	make  -f Makefile -C $(DIR_LIBFT)

re:			fclean all

.PHONY:		all clean re fclean
