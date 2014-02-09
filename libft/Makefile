#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalaing <cmalaing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 11:30:32 by cmalaing          #+#    #+#              #
#    Updated: 2013/12/29 00:20:55 by cmalaing         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
PATH_INC = .
PATH_OBJ = ./obj
PATH_SRC = ./srcs
SRC = ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c \
ft_memcpy.c ft_memset.c ft_strchr.c ft_strcpy.c ft_strlcat.c ft_strncat.c \
ft_strncpy.c ft_strrchr.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isdigit.c \
ft_memccpy.c ft_memcmp.c ft_memmove.c ft_strcat.c ft_strcmp.c ft_strdup.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strstr.c ft_toupper.c ft_strequ.c \
ft_strnequ.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strsub.c ft_strjoin.c \
ft_strndup.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstaddlast.c ft_lstmap.c ft_isspace.c ft_lstrev.c ft_lstlen.c \
ft_stradd.c ft_lstsort.c ft_getnumlen.c ft_nputchar.c ft_strinsert.c \
get_next_line.c ft_pow.c
OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

.PHONY: 			clean fclean re

all:				$(NAME)

$(NAME):			$(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft : done !"

$(PATH_OBJ)/%.o:	$(addprefix $(PATH_SRC)/, %.c)
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(PATH_INC)

clean:
	@rm -f $(OBJ)
	@echo "Libft : objects removed"

fclean:				clean
	@rm -f $(NAME)
	@echo "Libft : binary removed"

re:					fclean all
