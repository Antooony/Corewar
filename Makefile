# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 14:06:26 by nolivier          #+#    #+#              #
#    Updated: 2017/09/11 12:37:59 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: NAME NAME2 all LIBFT clean fclean

CC				=	gcc
FLAG			=	-Wall -Wextra -Werror

LIB				=	./libft/libft.a
LIB_PATH		=	./libft

NAME			=	asm
NAME2			=	corewar

SRC_NAME		=	assembler.c tools.c tools_2.c tools_3.c parsing.c get.c
SRC2_NAME		=	vm.c

SRC_PATH		=	srcs/asm
SRC2_PATH		=	srcs/vm

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC2			=	$(addprefix $(SRC2_PATH)/,$(SRC2_NAME))

OBJS			=	$(SRC:%.c=%.o)
OBJS2			=	$(SRC2:%.c=%.o)

HEADER			=	includes

all : $(NAME) $(NAME2)

$(NAME) : $(OBJS) $(LIB)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -I $(HEADER) -o $(NAME)

$(NAME2) : $(OBJS2) $(LIB)
	@$(CC) $(FLAGS) $(SRC2) $(LIB) -I $(HEADER) -o $(NAME2)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $< -I $(HEADER)

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS2)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make fclean -C ./libft

re : fclean all
