# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrella <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 16:17:59 by mbrella           #+#    #+#              #
#    Updated: 2019/10/02 16:30:45 by mbrella          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Wextra -Werror

SRC=src/display_files.c src/lists.c src/main.c src/sort_files.c src/dop_files.c

HEADER=-I inc/ft_ls.h

NAME=ft_ls

OBJ=$(SRC:.c=.o)

LIBFT=./libft/libft.a

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(OBJ) $(HEADER) $(LIBFT) -o $(NAME)
%.o:%.c
	@gcc $(HEADER) -c $< -o $@

all: $(NAME)

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
