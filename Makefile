# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2019/02/04 20:38:20 by dzboncak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = $(wildcard *.c)

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = libft/includes

LIBRARY = libft

$(NAME): $(SRC)
	gcc -o $(NAME) $(SRC) -I $(INC) -L ./$(LIBRARY) -lft  -lmlx -framework OpenGL -framework Appkit 
	make -C $(LIBRARY) 

all:$(NAME)

debug:
	gcc -g3 -o $(NAME) $(SRC) -I $(INC) -L ./$(LIBRARY) -lft -lmlx -framework OpenGL -framework Appkit 

clean:
	rm -f *.o
	make -C $(LIBRARY) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
	make -C $(LIBRARY) re
