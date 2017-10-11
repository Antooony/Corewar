# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 17:30:53 by adenis            #+#    #+#              #
#    Updated: 2017/10/11 17:29:13 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: NAME NAME2 all LIBFT clean fclean

CC			= gcc
FLAG		= -Wall -Wextra -Werror

LIB			= ./libft/libft.a
LIB_PATH	= ./libft

NAME		= asm
NAME2		= corewar

SRC_ASM		=	tools.c \
				assembler.c \
				free.c \
				token.c token_2.c \
				t_ft.c t_ft_2.c \
				ft_op.c \
				display.c display_2.c \
				output.c \
				calc.c

SRC_VM		= vm.c

PATH_ASM	= srcs/asm
PATH_VM		= srcs/vm

ASM			= $(addprefix $(PATH_ASM)/,$(SRC_ASM))
VM			= $(addprefix $(PATH_VM)/,$(SRC_VM))

OBJS_ASM	= $(ASM:%.c=%.o)
OBJS_VM		= $(VM:%.c=%.o)

HEADER		= includes

all: $(NAME) $(NAME2)

$(NAME): $(OBJS_ASM) $(LIB)
	@$(CC) $(FLAGS) $(ASM) $(LIB) -I $(HEADER) -o $(NAME)

$(NAME2): $(OBJS_VM) $(LIB)
	@$(CC) $(FLAGS) $(ASM) $(LIB) -I $(HEADER) -o $(NAME2)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $< -I $(HEADER)

clean:
	@rm -f $(OBJS_ASM)
	@rm -f $(OBJS_VM)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make fclean -C ./libft

re: fclean all
