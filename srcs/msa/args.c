/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:49:33 by adenis            #+#    #+#             */
/*   Updated: 2017/10/19 17:06:14 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"

void		get_arg(t_oct **lst, int size, int type)
{
	int		arg;
	int		offset;
	char	*s;

	if (!size)
		return ;
	offset = 8 * (size - 1);
	arg = 0;
	while (size)
	{
		arg = (int)(*lst)->content << offset | arg;
		offset -= 8;
		(*lst) = (*lst)->next;
		size--;
	}
	if (type == 1)
		write_output("r", 0, NULL);
	if (type == 2)
		write_output("%", 0, NULL);
	write_output((s = ft_itoa(arg)), 0, ", ");
	s ? ft_strdel(&s) : NULL;	
}

void		handle_opc(t_oct **lst, int a1, int a2, int a3)
{
	t_oct	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	*lst = (*lst)->next;
	get_arg(lst, noct(a1, tmp), get_type(a1, tmp));
	get_arg(lst, noct(a2, tmp), get_type(a2, tmp));
	get_arg(lst, noct(a3, tmp), get_type(a3, tmp));
}

void		get_opc(t_oct **lst)
{
	t_oct				*tmp;
	unsigned char		opc;
	int					a1;
	int					a2;
	int					a3;

	tmp = *lst;
	tmp = tmp->next;
	opc = tmp->content;
	a1 =  opc / 64 ;
	opc = opc % 64;
	a2 =  opc / 16 ;
	opc = opc % 16;
	a3 =  opc / 4 ;
	handle_opc(lst, a1, a2, a3);
}

void		handle_args(t_oct **lst)
{
	t_oct	*tmp;
	int		size;
	int		a;
	int		i;

	a = 0;
	i = 0;
	tmp = *lst;
	*lst = (*lst)->next;
	size = g_op_tab[tmp->content - 1].num_params;
	while (i < size)
	{
		a = g_op_tab[tmp->content - 1].params[i];
		get_arg(lst, noct(a, tmp), get_type(a, tmp));
		i++;
	}
}