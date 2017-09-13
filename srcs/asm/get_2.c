/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:06:37 by adenis            #+#    #+#             */
/*   Updated: 2017/09/12 16:07:21 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	get_dir(int	size, char *s)
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
		get_dir(lst->label_size, &s[1]);
}
