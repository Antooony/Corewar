/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:00:57 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/11 16:52:39 by adenis           ###   ########.fr       */
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

void	print_char(char nb)
{
	int		o1;
	int		o2;

	o1 = nb >> 8;
	o2 = (nb >> 8) << 8 | nb;
	ft_printf("\e[35m[\e[0m%s%#0.2x ",o1 ? "" : "0x", o1);
	ft_printf("%s%#0.2x\e[35m]\e[0m ",o2 ? "" : "0x", o2);
}

void	print_int(char nb)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;

	o1 = nb >> 24;
	o2 = nb >> 16;
	o3 = nb >> 8;
	o4 = (nb >> 8) << 8 | nb;
	ft_printf("\e[35m[\e[0m%s%#0.2x ",o1 ? "" : "0x", o1);
	ft_printf("%s%#0.2x ",o2 ? "" : "0x", o2);
	ft_printf("%s%#0.2x ",o3 ? "" : "0x", o3);
	ft_printf("%s%#0.2x\e[35m]\e[0m ",o4 ? "" : "0x", o4);
}

void	ft_get_dir(int	size, char *s)
{
	int		val;

	if (s[0] == ':')
	{
		print_char(0);
		return ;
	}
	val = ft_atoi(s);
	if (size == 2)
		print_char(val);
	if (size == 4)
		print_int(val);
}

int		get_val_op(char *s)
{
	int		i;

	i = 0;
	while (g_op_tab[i].label)
	{
		if (!ft_strcmp(g_op_tab[i].label, s))
			return (g_op_tab[i].op_code);
		i++;
	}
	return (0);
}

void	get_val_args(t_ops *lst, char *s)
{
	if (!s)
		return ;
	if (s[0] == 'r')
		ft_printf("\e[35m[\e[0m%#.2x\e[35m]\e[0m ", ft_atoi(&s[1]));
	if (s[0] == '%')
		ft_get_dir(lst->label_size, &s[1]);
}

void	display_op_out(t_ops *lst)
{
	int		i;

	while (lst)
	{
		i = 0;
		ft_printf("\e[36m[\e[0m%#.2x\e[36m]\e[0m ", get_val_op(lst->name));
		if (lst->coding_param)
			ft_printf("\e[93m[\e[0m%s%#0.2x\e[93m]\e[0m ","0x", 0);
		while (i < lst->nargs)
		{
			get_val_args(lst, lst->args[i]);
			i++;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
}

void	display_op(t_ops *lst)
{
	int		i;

	while (lst)
	{
		ft_printf("\t\e[36m%-4s\e[0m - ", lst->name);
		i = 0;
		while (i < lst->nargs)
		{
			ft_printf("\e[35m%s\e[0m ",lst->args[i]);
			i++;
		}
		ft_printf("\n");
		lst = lst->next;
	}
}

void	display_out(void)
{
	t_label		*tmp;

	tmp = FLABEL;
	ft_putchar('\n');
	while (tmp)
	{
		display_op_out(tmp->firstop);
		tmp = tmp->next;
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

void	ft_asm(int fd)
{
	t_list	*lst;

	lst = get_input(fd);
	init_infos();
	parsing(lst);
	show_me_whatugot();
	display_out();
	leave_free(lst);
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
