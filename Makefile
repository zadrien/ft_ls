# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 18:16:06 by zadrien           #+#    #+#              #
#    Updated: 2017/11/06 12:33:31 by zadrien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean name re

CC=				gcc

NAME=			ft_ls

CFLAGS=			 -Wall -Werror -Wextra

CPATH=			srcs/

OPATH=			obj/

HPATH=			include/ libft/

INC=			$(addprefix -I , $(HPATH))

CFILES= 		main.c \
				misc.c \
				arg_handler/recup_arg.c	\
				arg_handler/checking_arg.c	\
				output_ls/print.c	\
				output_ls/ft_chmod.c	\
				output_ls/opt_l.c	\
				listing_dir/list_dir.c	\
				listing_dir/ft_timerev.c	\
				listing_dir/sort_ascii.c	\
				listing_dir/sort_time.c	\
				listing_dir/recursive.c	\

OFILES=			$(CFILES:.c=.o)

HFILES=			include/ft_ls.h	\
				libft/libft.h	\

OBJ=			$(addprefix $(OPATH), $(OFILES))


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
	@mkdir -p $(OPATH)/arg_handler
	@mkdir -p $(OPATH)/output_ls
	@mkdir -p $(OPATH)/listing_dir
	$(CC) $(CFLAGS)  $(INC) $< -c -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(OPATH)

re: fclean all

norme:
	@norminette srcs/**/**.[ch]
	@norminette libft/*.[ch]
