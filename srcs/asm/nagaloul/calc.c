/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:22:57 by adenis            #+#    #+#             */
/*   Updated: 2017/10/16 16:38:46 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		opc_val(int type)
{
	if (type == 1)
		return (REG_CODE);
	if (type == 4)
		return (DIR_CODE);
	if (type == 6)
		return (IND_CODE);
	return (2);
}

int		ft_opc(t_output *pop)
{
	int			opc;
	int			i;
	int			val;
	t_output	*tmp;

	val = 64;
	opc = 0;
	i = g_op_tab[whichop(pop->name)].num_params;
	tmp = pop;
	while (i)
	{
		tmp = tmp->next;
		opc += val * (opc_val(tmp->type));
		val = val / 4;
		i--;
	}
	return (opc);
}