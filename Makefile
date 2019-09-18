#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2019/08/01 03:24:58 by brey-gal     #+#   ##    ##    #+#       #
#    Updated: 2019/08/01 03:24:58 by brey-gal    ###    #+. /#+    ###.fr     #
#                                                          /                  #
#                                                         /                   #
#  ************************************************************************** #

NAME = wolf3d

SRCS =  srcs/main.c		\
		srcs/wolf.c		\
		srcs/ray.c		\
		srcs/get_next_line.c	\
		srcs/map_line.c		\
		srcs/render.c	\
		srcs/setup.c

OBJS = $(SRCS:.c=.o)

LIB = -L. libft/libft.a

INC =	includes/struct.h	\
		includes/wolf3d.h

CC = gcc

SDL2 = -I include -L lib -l SDL2-2.0.0

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
		$(MAKE) -C libft
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(SDL2)

clean :
		$(MAKE) clean -C libft
		rm -f $(OBJS)

fclean : clean
		$(MAKE) fclean -C libft
		rm -f $(NAME)

re : fclean all
