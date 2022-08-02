# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 13:58:22 by rezzahra          #+#    #+#              #
#    Updated: 2022/08/02 13:58:25 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	*.c

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror -Ofast

NAME			= CUB3D

all:			$(NAME)

$(NAME):		$(SRCS)
				gcc  $(FLAGS) -lmlx -framework OpenGL -framework Appkit $(SRCS) -o $(NAME)
clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME) 

re:				fclean $(NAME)