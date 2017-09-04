/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:00:57 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/04 18:22:46 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		ft_op_delim(char *s, int i, int len)
{
	char 	*delim;

	delim = "%:, \t";
	if ((!s[i + len] || ft_strchr(&delim[2], s[i + len]))
		&& (!i || ft_strchr(delim, s[i - 1])))
		return (1);
	return (0);
}

void	show_op(int i, char *s)
{
	char 	*tmp;

	while (s && ft_strstr(s, g_op_tab[i].label))
	{
		if ((tmp = ft_strstr(s, g_op_tab[i].label))
			&& ft_op_delim(s, tmp - s, ft_strlen(g_op_tab[i].label)))
			ft_printf("\t\e[32mop found = %s\n\e[0m", g_op_tab[i].label);
		s = tmp + ft_strlen(g_op_tab[i].label);
	}
}

void	get_op(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return;
	while (g_op_tab[i].label)
	{
		show_op(i, s);
		i++;
	}
}

void	get_labels(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return;
	while (s[i] != ':')
	{
		if (!ft_isalnum(s[i]))
			return;
		i++;
	}
	ft_printf("\t\e[31mlabel found = %.*s\n\e[0m", (&s[i] - s), s);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;
	t_list	*tmp;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	lst = get_input(fd);
	tmp = lst;
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		get_labels(lst->content);
		get_op(lst->content);
		lst = lst->next;
	}
	lst = tmp;
	if (close(fd) == -1)
		return (ft_error());
}
