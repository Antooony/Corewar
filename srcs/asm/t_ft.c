/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:32:29 by adenis            #+#    #+#             */
/*   Updated: 2017/10/03 18:14:42 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_lab(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 0;
	pop->val = 0;
}

void	ft_comment(t_output *pop)
{
	return ;
}

void	ft_dirlab(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 2;
	pop->val = 0;
}

void	ft_indirlab(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 2;
	pop->val = 0;
}

void	ft_dir(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 4;
	if (pop->link && g_op_tab[whichop(pop->link->name)].label_size)
		pop->size = 2;
	pop->val = ft_atoi(&(pop->name)[1]);
}
