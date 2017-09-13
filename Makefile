# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 14:06:26 by nolivier          #+#    #+#              #
#    Updated: 2017/09/12 16:21:06 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: NAME NAME2 all LIBFT clean fclean

CC				=	gcc
FLAG			=	-Wall -Wextra -Werror

LIB				=	./libft/libft.a
LIB_PATH		=	./libft

NAME			=	asm
NAME2			=	corewar

SRC_ASM			=	tools.c tools_2.c tools_3.c tools_4.c \
					get.c get_2.c \
					assembler.c parsing.c display.c calc.c
SRC_VM			=	vm.c

PATH_ASM		=	srcs/asm
PATH_VM			=	srcs/vm

ASM				=	$(addprefix $(PATH_ASM)/,$(SRC_ASM))
VM				=	$(addprefix $(PATH_VM)/,$(SRC_VM))

OBJS_ASM		=	$(ASM:%.c=%.o)
OBJS_VM			=	$(VM:%.c=%.o)

HEADER			=	includes

all : $(NAME) $(NAME2)

$(NAME) : $(OBJS_ASM) $(LIB)
	@$(CC) $(FLAGS) $(ASM) $(LIB) -I $(HEADER) -o $(NAME)

$(NAME2) : $(OBJS_VM) $(LIB)
	@$(CC) $(FLAGS) $(VM) $(LIB) -I $(HEADER) -o $(NAME2)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $< -I $(HEADER)

clean :
	@rm -f $(OBJS_ASM)
	@rm -f $(OBJS_VM)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make fclean -C ./libft

re : fclean all
