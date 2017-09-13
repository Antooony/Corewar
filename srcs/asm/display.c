/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:04:27 by adenis            #+#    #+#             */
/*   Updated: 2017/09/12 16:05:37 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	print_char(char nb)
{
	int		o1;
	int		o2;

	o1 = nb >> 8;
	o2 = (nb >> 8) << 8 | nb;
	ft_printf("\e[35m[\e[0m%s%#0.2x,",o1 ? "" : "0x", o1);
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
	ft_printf("\e[35m[\e[0m%s%#0.2x,",o1 ? "" : "0x", o1);
	ft_printf("%s%#0.2x,",o2 ? "" : "0x", o2);
	ft_printf("%s%#0.2x,",o3 ? "" : "0x", o3);
	ft_printf("%s%#0.2x\e[35m]\e[0m ",o4 ? "" : "0x", o4);
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
