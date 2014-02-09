# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 16:36:00 by sboeuf            #+#    #+#              #
#    Updated: 2014/02/09 16:36:02 by sboeuf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

NAME		= global

DIR_LIBFT	= ./libft

all:		$(NAME)

$(NAME):	$(DIR_LIBFT)/libft.a
			cd ./client/ ; make
			cd ./server/ ; make

clean:
			cd ./client/ ; make clean
			cd ./server/ ; make clean

fclean:
			cd ./client/ ; make fclean
			cd ./server/ ; make fclean

$(DIR_LIBFT)/libft.a:
	make  -f Makefile -C $(DIR_LIBFT)

re: fclean all

.PHONY:		all clean re fclean
