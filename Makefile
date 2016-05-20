#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/10 19:36:45 by sbeaufil          #+#    #+#              #
#    Updated: 2016/05/04 18:08:11 by sbeaufil         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem_in
FLAGS = -g -Wall -Werror -Wextra
IDIR = includes/
SDIR = srcs/
ODIR = objects/
SRC = $(shell find $(SDIR) -type f | grep -e \.c$$)
LIB = libft/
OBJ = $(SRC:.c=.o)
LFILES = $(shell find $(LIB) -type f | grep -e \.c$$)
LOBJ = $(LFILES:.c=.o)

all : $(NAME)

$(NAME): $(LOBJ) $(OBJ)
		@echo -n '$(NAME):    Creating $(NAME) done...			'
		@gcc -o $(NAME) $(OBJ) -L $(LIB) -lft -I $(IDIR)
		@echo "\033[32mOK\033[0m"

clean :
		make clean -C libft
		@echo -n '$(NAME):	  Removing objects...				'
		@rm -f $(OBJ)
		@echo "\033[32mOK\033[0m"

$(LIB)%.o:	$(LIB)%.c
					@make -C $(LIB)
%.o:%.c
		@echo -n '$(NAME):    Compiling done...				'
		@gcc -c $< -o $@ -I $(IDIR)
		@echo "\033[32mOK\033[0m"

fclean:	clean
		@echo -n 'libft:    Removing libft.a...				'
		@rm -f $(LIB)libft.a
		@echo "\033[32mOK\033[0m"
		@echo -n '$(NAME):	  Removing $(NAME)...				'
		@rm -f $(NAME)
		@echo "\033[32mOK\033[0m"

re: fclean all
