/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:22:57 by adenis            #+#    #+#             */
/*   Updated: 2017/10/03 17:58:51 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		ft_opc(t_output *pop)
{
	int			opc;
	int			i;
	int			val;
	t_output	*tmp;

	val = 64;
	opc = 0;
	i = pop->size + 1;
	tmp = pop;
	while (i)
	{
		tmp = tmp->next;
		opc += val * (tmp->type > 4 ? 2 : tmp->type);
		val = val / 4;
		i--;
	}
	return (opc);
}