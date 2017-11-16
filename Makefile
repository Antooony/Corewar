# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 17:30:53 by adenis            #+#    #+#              #
#    Updated: 2017/11/16 15:16:48 by nagaloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: NAME NAME2 all LIBFT clean fclean

CC			= gcc
FLAG		= -Wall -Wextra -Werror

LIB			= ./libft/libft.a
LIB_PATH	= ./libft

NAME		= asm
NAME2		= msa

SRC_ASM		= asm.c \
			  calc.c \
			  display.c \
			  display_2.c \
			  ft_and.c \
			  ft_check.c ft_check_2.c \
			  ft_commands.c \
			  ft_create_elem.c \
			  ft_create_token.c \
			  ft_freetab.c \
			  ft_live.c \
			  ft_pars.c ft_pars_2.c ft_pars_3.c \
			  ft_push_back.c \
			  ft_push_token.c \
			  ft_puterror.c \
			  ft_puterrorsep.c \
			  ft_reg.c \
			  ft_tomuch.c \
			  ft_virgule.c \
			  output.c \
			  split_space.c \
			  split_tok.c \
			  split_head.c \
			  t_ft.c \
			  t_ft_2.c \
			  ft_op.c \
			  ft_countchar.c \
			  ft_decoupe.c \
			  ft_lastchar.c \
			  ft_remp.c \
			  ft_strsplit.c \
			  tools.c tools_2.c\
			  handle_lab.c \
			  free.c \
			  ft_hard.c \
			  ft_medium.c \
			  ft_naco.c \
			  ft_naco2.c \
			  ft_lastline.c

SRC_MSA		= msa.c \
			  tools.c tools_2.c \
			  header.c \
			  args.c \
			  output.c \
			  checks.c

PATH_ASM	= srcs/asm/
PATH_MSA	= srcs/msa

ASM			= $(addprefix $(PATH_ASM)/,$(SRC_ASM))
MSA			= $(addprefix $(PATH_MSA)/,$(SRC_MSA))

OBJS_ASM	= $(ASM:%.c=%.o)
OBJS_MSA	= $(MSA:%.c=%.o)

HEADER		= includes

all: $(NAME) $(NAME2)

$(NAME): $(OBJS_ASM) $(LIB)
	$(CC) $(FLAGS) $(ASM) $(LIB) -I $(HEADER) -o $(NAME)

$(NAME2): $(OBJS_MSA) $(LIB)
	$(CC) $(FLAGS) $(MSA) $(LIB) -I $(HEADER) -o $(NAME2)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	@rm -f $(OBJS_ASM)
	@rm -f $(OBJS_MSA)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make fclean -C ./libft

re: fclean all
