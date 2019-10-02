# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrella <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 16:17:59 by mbrella           #+#    #+#              #
#    Updated: 2019/10/02 16:18:00 by mbrella          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Wextra -Werror

SRC=display_files.c ft_read_tetro.c main.c ft_dop_func.c

HEADER=-I ft_fillit.h

NAME=fillit

OBJ=$(SRC:.c=.o)

LIBFT=./libft/libft.a

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(FLAGS) $(OBJ) $(HEADER) $(LIBFT) -o $(NAME)
%.o:%.c
	@gcc $(FLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
