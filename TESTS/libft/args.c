/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:53:35 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:36:40 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_args(void)
{
	ft_putstr("g_arg.opt = ");
	ft_putstr(g_arg.opt);
	ft_putchar('\n');
	ft_putstr("g_arg.len = ");
	ft_putnbr(g_arg.len);
	ft_putchar('\n');
	ft_putstr("g_arg.vacc = ");
	ft_putnbr(g_arg.vacc);
	ft_putchar('\n');
	ft_putstr("g_arg.acc = ");
	ft_putnbr(g_arg.acc);
	ft_putchar('\n');
	ft_putstr("g_arg.size = ");
	ft_putstr(g_arg.size);
	ft_putchar('\n');
	ft_putstr("g_arg.conv = ");
	ft_putchar(g_arg.conv);
	ft_putchar('\n');
}

void	init_args(void)
{
	g_arg.len = 0;
	g_arg.acc = 0;
	g_arg.vacc = 0;
	g_arg.zero = 0;
	g_arg.conv = 0;
	g_arg.sign = 0;
	g_arg.opt = ft_strnew(0);
	g_arg.size = ft_strnew(0);
}

void	clean_args(void)
{
	ft_strdel(&g_arg.opt);
	ft_strdel(&g_arg.size);
}
