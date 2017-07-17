# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:01:35 by adenis            #+#    #+#              #
#    Updated: 2017/06/06 17:42:20 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	asm
FLAGS			=	-Wall -Wextra -Werror
SRC_DIR			=	./srcs/
SRCS			=	test.c checks.c tools.c parsing.c init_op_tab.c
SRC 			=	$(addprefix $(SRC_DIR)/,$(SRCS))
LIB				=	./libft/libft.a
INCLUDES 		=	./includes
LIB_PATH		=	./libft

OBJS			=	$(SRC:%.c=%.o)

.PHONY: all re clean fclean

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INCLUDES)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $< -I $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
