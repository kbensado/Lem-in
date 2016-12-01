# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbensado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/12 09:51:19 by kbensado          #+#    #+#              #
#    Updated: 2016/04/12 09:51:21 by kbensado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

NAME =		lem-in

CFLAGS =	-Wall -Wextra -Werror

SRC =		main.c algo.c check.c get_stdin.c joker.c list.c list2.c move.c tab.c tab2.c utils.c utils2.c \

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	
			@make -C libft
			@make -C ft_printf
			@$(CC) $(CFLAGS) -I libft -c $(SRC)
			@$(CC) $(CFLAGS) -I ft_printf -c $(SRC)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft -L ft_printf -lftprintf
			@echo ... Compilation of Lem-In DONE !

clean:
			@rm -rf $(OBJ)
			@make clean -C libft
			@make clean -C ft_printf
			@echo ... Objects clean in Lem-In !

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft
			@make fclean -C ft_printf
			@echo ... Name clean in Lem-In !

re:			fclean all
			@echo ... Lem-In retry !

