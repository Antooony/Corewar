# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 17:30:53 by adenis            #+#    #+#              #
#    Updated: 2017/10/13 15:02:32 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: NAME NAME2 all LIBFT clean fclean

CC			= gcc
FLAG		= -Wall -Wextra -Werror

LIB			= ./libft/libft.a
LIB_PATH	= ./libft

NAME		= asm
NAME2		= msa

SRC_ASM		= tools.c \
			  assembler.c \
			  free.c \
			  token.c token_2.c \
			  t_ft.c t_ft_2.c \
			  ft_op.c \
			  display.c display_2.c \
			  output.c \
			  calc.c


SRC_MSA		= msa.c \
			  tools.c

PATH_ASM	= srcs/asm
PATH_MSA	= srcs/msa

ASM			= $(addprefix $(PATH_ASM)/,$(SRC_ASM))
MSA			= $(addprefix $(PATH_MSA)/,$(SRC_MSA))

OBJS_ASM	= $(ASM:%.c=%.o)
OBJS_MSA	= $(MSA:%.c=%.o)

HEADER		= includes

all: $(NAME) $(NAME2)

$(NAME): $(OBJS_ASM) $(LIB)
	@$(CC) $(FLAGS) $(ASM) $(LIB) -I $(HEADER) -o $(NAME)

$(NAME2): $(OBJS_MSA) $(LIB)
	@$(CC) $(FLAGS) $(MSA) $(LIB) -I $(HEADER) -o $(NAME2)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	@rm -f $(OBJS_ASM)
	@rm -f $(OBJS_VM)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make fclean -C ./libft

re: fclean all
