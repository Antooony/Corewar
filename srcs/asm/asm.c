/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <nagaloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 11:29:56 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/21 15:58:55 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.h"

static t_token		*ft_split(t_list **temp, t_token *tok)
{
	t_list	*ops;
	int		b;

	b = 1;
	ops = *temp;
	while (ops)
	{
		if (ft_strchr(ops->content, '"'))
			split_head(&tok, &ops, &b);
		else
			split_tok(&tok, ops->content, b);
		if (ops)
			ops = ops->next;
		b++;
	}
	if (!tok)
	{
		ft_printf("Syntax error at token [TOKEN][%d:001] END \"(null)\"\n", b);
		clean();
	}
	ft_pars(tok);
	if (!ft_check(tok, *temp))
		clean();
	return (tok);
}

void				ft_asm(t_list *ops, char *name)
{
	t_token		*tok;

	tok = NULL;
	tok = ft_split(&ops, tok);
	TOK = tok;
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
	OPS = ops;
	close(fd);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		return (0);
	read_check(fd, ops);
	ft_asm(ops, av[1]);
	clean();
	return (0);
}
