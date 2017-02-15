#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpanov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 15:50:46 by dpanov            #+#    #+#              #
#    Updated: 2017/02/15 16:21:12 by dpanov           ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fillit
SRC = main.c if_valid.c printers.c input.c part.c
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) 

%.o: %.c
	gcc $(FLG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all