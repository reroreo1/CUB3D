# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:58:22 by rezzahra          #+#    #+#              #
#    Updated: 2022/09/05 04:02:24 by hkheiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= SRC/drawmap.c SRC/events.c SRC/get_next_line.c SRC/get_next_line_utils.c \
		SRC/intersection.c SRC/normimg.c SRC/parsing.c SRC/parsing2.c SRC/parsing3.c \
		SRC/parsing_utils.c SRC/parsing_utils2.c SRC/parsing_utils3.c SRC/walls.c
OBJS	= drawmap.o events.o get_next_line.o get_next_line_utils.o \
		intersection.o normimg.o parsing.o parsing2.o parsing3.o \
		parsing_utils.o parsing_utils2.o parsing_utils3.o walls.o
FLAGS	= -Wall -Wextra -Werror -Ofast
NAME	= CUB3D
CC		= gcc
INCLUDE	= INC/

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) -c $(FLAGS) -I $(INCLUDE) $(SRCS)
	$(CC) $(FLAGS)  -lmlx -framework OpenGL -framework Appkit -I $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)