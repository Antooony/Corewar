# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenis <adenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 16:45:23 by adenis            #+#    #+#              #
#    Updated: 2017/03/06 11:31:29 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC				=	gcc
NAME			=	libft.a
FLAGS			=	-Wall -Wextra -Werror

SRC				=	ft_atol.c ft_uitoa.c ft_sorttab.c ft_putwchar_fd.c\
					ft_atoi.c ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_memcmp.c \
					ft_memchr.c ft_memmove.c ft_memccpy.c ft_bzero.c ft_isalnum.c \
					ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c \
					ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_lstadd_end.c\
					ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
					ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
					ft_strdup.c ft_strlen.c ft_strncat.c ft_strncpy.c ft_strrchr.c \
					ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
					ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
					ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
					ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_lstnew.c \
					ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
					ft_lstsplit.c ft_strjoinfree.c ft_strsubfree.c ft_itoa_base.c \
					ft_power.c ft_ltoa_base.c ft_printf.c checks.c getargs.c args.c \
 					conv_p.c conv_i.c conv_o.c conv_x.c conv_xx.c conv_c.c \
 					conv_cc.c conv_per.c noconv.c conv.c size_base.c size_int.c \
 					size_u.c conv_u.c conv_uu.c conv_s.c ft_putwchar.c ft_putwstr.c \
 					wtoa.c conv_ss.c size_z.c various_get.c get_next_line.c ft_sprintf.c \
 					conv_i_s.c conv_o_s.c conv_ss_s.c conv_x_s.c conv_xx_s.c 
HEADER 			=	libft.h

OBJS			=	$(SRC:%.c=%.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
