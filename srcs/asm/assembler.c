/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/09/20 17:03:02 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "assembler.h"

t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 2},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	display_output(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s%#.2x\n", lst->content_size ? "" : "0x", lst->content_size);
		lst = lst->next;
	}
}

void	show_me_whatugot(void)
{
	t_label		*tmp;

	ft_printf("\e[31mName : \e[0m%s\n", g_infos.name);
	ft_printf("\e[31mComment : \e[0m%s\n", g_infos.comment);
	tmp = FLABEL;
	while (tmp)
	{
		ft_printf("\e[32mLABEL : %s\n\e[0m", tmp->name);
		display_op(tmp->firstop);
		tmp = tmp->next;
	}
}

void	check_op(t_ops op)
{

}

void	checks(void)
{
	t_label		tmp;

	tmp = FLABEL
	while (tmp)
	{
		while (tmp->ops)
		{
			check_op(tmp->ops);
			tmp->ops = tmp->ops->next;
		}
		tmp = tmp->next;
	}
}

void	ft_asm(int fd)
{
	t_list	*lst;

	lst = get_input(fd);
	INPUT = lst;
	init_infos();
	parsing(lst);
	checks();
	show_me_whatugot();
	// calc_out();
	// display_output(OUT);
	// display_out();
	leave_free();
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	ft_asm(fd);
	if (close(fd) == -1)
		return (ft_error());
}
