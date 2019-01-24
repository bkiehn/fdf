# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2019/01/22 20:59:56 by bkiehn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myfdf

SRC = *.c

FLAGS = -Wall -Wextra -Werror

INC = libft/includes

LIBRARY = libft/

$(NAME): 
	gcc -o $(NAME) $(SRC) -I $(INC) -L $(LIBRARY) -lmlx -framework OpenGL -framework Appkit -lft

all:$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

