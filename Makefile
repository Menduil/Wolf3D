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

SRCS =  srcs/main.c

OBJS = $(SRCS:.c=.o)

CFlAGS = -Wall -Werror -Wextra

LIB = -L. libft/libft.a

CC = gcc

SDL2 = -I /Library/Frameworks/SDL2.framework/Versions/A/Headers -F /Library/Frameworks/ -framework SDL2

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C libft
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(SDL2)

clean :
		$(MAKE) clean -C libft
		rm -f $(OBJS)

fclean : clean
		$(MAKE) fclean -C libft
		rm -f $(NAME)

re : fclean all
