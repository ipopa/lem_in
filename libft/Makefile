#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipopa <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/13 14:41:38 by ipopa             #+#    #+#              #
#    Updated: 2016/05/19 13:01:09 by ipopa            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

IDIR = -I includes/

SRC = $(shell find . -type f | grep -e \.c$$)

NOM = $(basename $(SRC))
OBJ = $(addsuffix .o, $(NOM))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $< $(IDIR)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

norme :
	@norminette $(SRC)
