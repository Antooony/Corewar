# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khabbar <khabbar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 15:04:37 by khabbar           #+#    #+#              #
#    Updated: 2017/11/21 15:33:28 by adenis           ###   ########.fr        #
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

APATH= asm/

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

AFILES= $(APATH)asm.c \
		$(APATH)calc.c \
		$(APATH)display.c \
		$(APATH)display_2.c \
		$(APATH)ft_and.c \
		$(APATH)ft_check.c \
		$(APATH)ft_check_2.c \
		$(APATH)ft_create_elem.c \
		$(APATH)ft_create_token.c \
		$(APATH)ft_freetab.c \
		$(APATH)ft_live.c \
		$(APATH)ft_pars.c \
		$(APATH)ft_pars_2.c \
		$(APATH)ft_pars_3.c \
		$(APATH)ft_push_back.c \
		$(APATH)ft_push_token.c \
		$(APATH)ft_puterror.c \
		$(APATH)ft_puterrorsep.c \
		$(APATH)ft_reg.c \
		$(APATH)ft_tomuch.c \
		$(APATH)ft_virgule.c \
		$(APATH)output.c \
		$(APATH)split_space.c \
		$(APATH)split_tok.c \
		$(APATH)split_head.c \
		$(APATH)t_ft.c \
		$(APATH)t_ft_2.c \
		$(APATH)ft_op.c \
		$(APATH)ft_countchar.c \
		$(APATH)ft_decoupe.c \
		$(APATH)ft_lastchar.c \
		$(APATH)ft_remp.c \
		$(APATH)ft_strsplit.c \
		$(APATH)tools.c \
		$(APATH)tools_2.c\
		$(APATH)handle_lab.c \
		$(APATH)free.c \
		$(APATH)ft_hard.c \
		$(APATH)ft_medium.c \
		$(APATH)ft_naco.c \
		$(APATH)ft_naco2.c \
		$(APATH)ft_lastline.c

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
		includes/assembler.h \
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
	@mkdir -p $(OPATH)/$(APATH)
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
