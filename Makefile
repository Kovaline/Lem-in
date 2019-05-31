# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/31 15:28:12 by ikovalen          #+#    #+#              #
#    Updated: 2019/05/31 15:30:12 by ikovalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -c -Wall -Wextra -Werror
OBJ = *.o
SRC = lemin.c algo.c print.c readfile.c

all: $(NAME)

$(NAME):
		@make -C ft_printf
		gcc $(FLAGS) $(SRC)
		gcc $(OBJ) -L ft_printf/ -lftprintf -o $(NAME)

clean:
	@make -C ft_printf/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean all
