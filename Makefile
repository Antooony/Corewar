# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khabbar <khabbar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 15:04:37 by khabbar           #+#    #+#              #
#    Updated: 2017/11/10 18:14:30 by adenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean name re

CC= gcc

NAME= asm

COR= corewar

MSA= msa

CFLAGS= -Wall -Wextra -Werror

CPATH= srcs/

MPATH= msa/

OPATH= obj/

HPATH= includes/

INC= $(addprefix -I , $(HPATH))

CFILES= vm.c \
		ft_init_graph.c \
		ft_graph.c \
		ft_graph_dump.c \
		ft_graph_info.c \
		ft_graph_func.c \
		ft_graph_process.c \
		ft_graph_audio.c \
		ft_press_to_dump.c \
		ft_run_kitty_run.c \
		ft_error.c \
		ft_print_winner.c \
		ft_dump_memory.c \
		ft_invert_endian.c \
		ft_check_options.c \
		ft_manage_entry.c \
		ft_load.c \
		ft_init_process.c \
		ft_check_ctd.c \
	   	ft_get_ocp.c \
	   	ft_get_add.c \
		ft_get_val.c \
	   	ft_modif_carry.c \
		ft_create_process.c \
		ft_pc_move.c \
	   	ft_live.c \
	   	ft_ld.c \
	   	ft_st.c \
	   	ft_add.c \
	   	ft_sub.c \
	   	ft_and.c \
	   	ft_or.c \
	   	ft_xor.c \
	   	ft_zjmp.c \
	   	ft_ldi.c \
	   	ft_sti.c \
	   	ft_fork.c \
	   	ft_lld.c \
	   	ft_lldi.c \
	   	ft_lfork.c \
	   	ft_aff.c

AFILES= assembler.c
# AFILES= asm.c \
# 		calc.c \
# 		display.c \
# 		display_2.c \
# 		ft_and.c \
# 		ft_check.c ft_check_2.c \
# 		ft_commands.c \
# 		ft_create_elem.c \
# 		ft_create_token.c \
# 		ft_freetab.c \
# 		ft_live.c \
# 		ft_pars.c ft_pars_2.c ft_pars_3.c \
# 		ft_push_back.c \
# 		ft_push_token.c \
# 		ft_puterror.c \
# 		ft_puterrorsep.c \
# 		ft_reg.c \
# 		ft_tomuch.c \
# 		ft_virgule.c \
# 		output.c \
# 		split_space.c \
# 		split_tok.c \
# 		t_ft.c \
# 		t_ft_2.c \
# 		ft_op.c \
# 		ft_countchar.c \
# 		ft_decoupe.c \
# 		ft_lastchar.c \
# 		ft_remp.c \
# 		ft_strsplit.c \
# 		tools.c \
# 		handle_lab.c \
# 		free.c

MFILES= $(MPATH)msa.c \
		$(MPATH)tools.c \
		$(MPATH)tools_2.c \
		$(MPATH)tools_3.c \
		$(MPATH)header.c \
		$(MPATH)args.c \
		$(MPATH)output.c \
		$(MPATH)checks.c \
		$(MPATH)ocp.c \
		$(MPATH)label.c

COFILES= $(CFILES:.c=.o)

AOFILES= $(AFILES:.c=.o)

MOFILES= $(MFILES:.c=.o)

HFILES= includes/vm.h \
		includes/op.h \
		includes/msa.h \
		libft/inc/libftprintf.h

COBJ= $(addprefix $(OPATH), $(COFILES))

POBJ= $(addprefix $(OPATH), $(AOFILES))

MOBJ= $(addprefix $(OPATH), $(MOFILES))

all: LIB $(NAME) $(HFILES)

$(NAME): $(POBJ) $(COBJ) $(MOBJ)
	$(CC) $(CFLAGS) $(COBJ) $(INC) libft/libft.a -o $(COR) -lncurses
	$(CC) $(CFLAGS) $(POBJ) $(INC) libft/libft.a -o $(NAME)
	$(CC) $(CFLAGS) $(MOBJ) $(INC) libft/libft.a -o $(MSA)

LIB:
	make -C libft

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
	@mkdir -p $(OPATH)/build
	@mkdir -p $(OPATH)/$(MPATH)
	$(CC) $(CFLAGS) $(INC) $< -c -o $@

clean:
	$(MAKE) -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -rf $(OPATH)
	rm -rf $(NAME)
	rm -rf $(COR)
	rm -rf $(MSA)

re: fclean all
