# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 20:45:05 by zadrien           #+#    #+#              #
#    Updated: 2017/08/28 15:43:27 by zadrien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = ft_ls

LIB = -L libft/ -lft

LIBFT = libft/libft.a

C_DIR = srcs/

SRCS = main.c checking_arg.c	\

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I include -I libft/

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@gcc -Wall -Wextra -Werror $^ -o $@ $(LIB)

$(LIBFT):
	@make -C libft/
	@echo "Compilation ft_ls: DONE"

$(OBJ) : $(SRC)
	@echo "Compilation ft_ls: In progress"
	@gcc -c -Wall -Wextra -Werror $^ $(INC)

clean :
	@make clean -C libft/
	@echo "Suppression Objet LIBFT : OK"
	@rm -f $(OBJ)
	@echo "Suppression Objet SRCS : OK"

fclean : clean
	@rm -f $(LIBFT)
	@echo "Suppression libft.a : OK"
	@rm -f $(NAME)
	@echo "Suppression (executable) minishell : OK"

re : fclean all
