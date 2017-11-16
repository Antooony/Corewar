/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <nagaloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 11:29:56 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/16 15:05:34 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

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

static t_token		*ft_split(t_list **temp, t_token *tok)
{
	t_list	*ops;
	int		b;
	int i;

	i = 0;
	b = 1;
	ops = *temp;
	while (ops)
	{
		if (ft_strchr(ops->content, '"'))
		{
			split_head(&tok, &ops, &b);
		}
		else
			split_tok(&tok, ops->content, b);
		ops = ops->next;
		b++;
	}
	ft_pars(tok);
	if (!ft_check(tok, *temp))
		return (NULL);
	return (tok);
}

static int			ft_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

void				get_ops(t_list **ops, int fd)
{
	char		*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_push_back(ops, line);
		ft_strdel(&line);
	}
}

void				ft_asm(t_list *ops, char *name)
{
	t_token		*tok;

	tok = ft_split(&ops, tok);
	TOK = tok;
	if (!tok)
		clean(ops);
	handle_file(name);
	ft_calc(tok);
}

int					main(int ac, char **av)
{
	int			fd;
	t_list		*ops;

	(void)av;
	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		return (0);
	g_name = 0;
	FD = 1;
	init_ft_tab();
	get_ops(&ops, fd);
	ft_asm(ops, av[1]);
	clean(ops);
	return (0);
}
