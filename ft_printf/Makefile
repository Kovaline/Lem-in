# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 13:47:41 by ikovalen          #+#    #+#              #
#    Updated: 2019/01/24 14:48:13 by ikovalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -c -Wall -Wextra -Werror
OBJ = *.o
SRC = ft_printf.c applyflags.c flags.c ft_itoa_base.c \
	  ft_utoa_base.c printit.c prints.c prints2.c \
	  validation.c bonusprints.c

all: $(NAME)

$(NAME):
	@make -C libft
	gcc $(FLAGS) $(SRC)
	ar rc $(NAME) *.o libft/*.o

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
