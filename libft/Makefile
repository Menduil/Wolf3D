#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2019/06/20 19:05:09 by brey-gal     #+#   ##    ##    #+#       #
#    Updated: 2019/06/20 19:05:09 by brey-gal    ###    #+. /#+    ###.fr     #
#                                                          /                  #
#                                                         /                   #
#  ************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

SRC =	ft_puterror.c   \
        ft_putstr.c		\
        ft_strnew.c		\
        ft_strjoin.c	\
        ft_strcpy.c		\
        ft_strsub.c		\
        ft_strlen.c		\
        ft_strdup.c		\
        ft_atoi.c       \
        ft_itoa.c


all: $(NAME)

$(NAME): $(OBJ)
		ar ruc $@ $?
		ranlib $@

.PHONY: clean fclean re

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM)  $(NAME)

re: fclean all
