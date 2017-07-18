# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 14:06:26 by nolivier          #+#    #+#              #
#    Updated: 2017/05/31 15:37:39 by nolivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: NAME NAME2 all LIBFT clean fclean

NAME = asm

NAME2 = corewar

SRC = assembler.c

SRC2 = vm.c

OUT = $(SRC:.c=.o)

OUT2 = $(SRC2:.c=.o)

FLAG = -Wall -Wextra #-Werror

all: LIBFT $(NAME) $(NAME2)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^

$(NAME): $(OUT)
	gcc -o $(NAME) $(OUT) $(FLAG) libft/libft.a

$(NAME2): $(OUT2)
	gcc -o $(NAME2) $(OUT2) $(FLAG) libft/libft.a

LIBFT:
	$(MAKE) -C libft/

clean:
	/bin/rm -f $(OUT)
	/bin/rm -f $(OUT2)
	$(MAKE) -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)
	$(MAKE) -C libft/ fclean

re: fclean all
