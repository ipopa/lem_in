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
SRC = $(SDIR)main.c $(SDIR)get_next_line.c $(SDIR)parse_map.c $(SDIR)error.c $(SDIR)check.c $(SDIR)tools.c $(SDIR)algo.c $(SDIR)path.c $(SDIR)print.c $(SDIR)test.c
LIB = libft/
OBJ = $(SRC:.c=.o)
LFILES = $(addprefix $(LIB), $(shell ls $(LIB) | grep .c))
LOBJ = $(LFILES:.c=.o)

all : $(NAME)

$(NAME): $(LOBJ) $(OBJ)
		@echo -n 'ft_sh:    Creating $(NAME) done...		'
		@gcc -o $(NAME) $(OBJ) -L $(LIB) -lft -I $(IDIR)
		@echo "\033[32mOK\033[0m"

clean :
		make clean -C libft
		@echo -n 'ft_sh:	  Removing objects...				'
		@rm -f $(OBJ)
		@echo "\033[32mOK\033[0m"

$(LIB)%.o:	$(LIB)%.c
					@make -C $(LIB)
%.o:%.c
		@echo -n 'ft_sh:    Compiling done...				'
		@gcc -c $< -o $@ -I $(IDIR)
		@echo "\033[32mOK\033[0m"

fclean:	clean
		@echo -n 'libft:    Removing libft.a...				'
		@rm -f $(LIB)libft.a
		@echo "\033[32mOK\033[0m"
		@echo -n 'ft_sh:	  Removing ft_sh...				'
		@rm -f $(NAME)
		@echo "\033[32mOK\033[0m"

re: fclean all
