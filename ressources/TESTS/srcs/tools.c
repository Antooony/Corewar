/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:12:30 by adenis            #+#    #+#             */
/*   Updated: 2017/06/06 16:26:40 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	dispop(void)
{
	int		i;
	int		j;

	i = 0;
	while (op_tab[i].name)
	{
		ft_printf("%-5s : opcode : %-2d nargs : %d\n"
			, op_tab[i].name, op_tab[i].opcode, op_tab[i].nargs);
		j = 0;
		while (j < op_tab[i].nargs)
		{
			if (j > 0) 
				ft_printf(" - ");
			ft_printf("%d", op_tab[i].args[j]);
			j++;

		}
		ft_printf("\n\e[35m%C  %s\e[0m\n",L'↳' ,op_tab[i].action);
		i++;
	}
}

void	displst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n",lst->content);
		lst = lst->next;
	}
}
