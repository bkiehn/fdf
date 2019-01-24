# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiehn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2018/12/03 12:10:45 by bkiehn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

FLAGS = -Wall -Wextra -Werror

INC = includes/libft.h

OBJC = $(SRC:.c=.o)

$(NAME): $(OBJC)
	ar rc $(NAME) $(OBJC)

all:$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJC): $(SRC)
	gcc -c $(FLAGS) $(SRC) -I $(INC)
