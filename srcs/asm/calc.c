/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:21:10 by adenis            #+#    #+#             */
/*   Updated: 2017/09/12 16:50:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_output(int x)
{
	t_list *tmp;

	PROG_SIZE++;
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = x;
	if (!OUT)
		OUT = tmp;
	else
		ft_lstadd_end(OUT, tmp);
}

void	out_char(char nb)
{
	int		o1;
	int		o2;

	o1 = nb >> 8;
	o2 = (nb >> 8) << 8 | nb;
	ft_output(o1);
	ft_output(o2);
}

void	out_int(char nb)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;

	o1 = nb >> 24;
	o2 = nb >> 16;
	o3 = nb >> 8;
	o4 = (nb >> 8) << 8 | nb;
	ft_output(o1);
	ft_output(o2);
	ft_output(o3);
	ft_output(o4);
}

void	out_op(t_ops *lst)
{
	int		i;

	while (lst)
	{
		i = 0;
		ft_output(get_val_op(lst->name));
		if (lst->coding_param)
			ft_output(0);
		while (i < lst->nargs)
		{
			calc_val_args(lst, lst->args[i]);
			i++;
		}
		lst = lst->next;
	}
}

void	calc_dir(int size, char *s)
{
	int		val;

	if (s[0] == ':')
	{
		out_char(0);
		return ;
	}
	val = ft_atoi(s);
	if (size == 2)
		out_char(val);
	if (size == 4)
		out_int(val);
}

void	calc_val_args(t_ops *lst, char *s)
{
	if (!s)
		return ;
	if (s[0] == 'r')
		ft_output(ft_atoi(&s[1]));
	if (s[0] == '%')
		calc_dir(lst->label_size, &s[1]);
}

void	calc_out(void)
{
	t_label		*tmp;

	tmp = FLABEL;
	while (tmp)
	{
		out_op(tmp->firstop);
		tmp = tmp->next;
	}
}
