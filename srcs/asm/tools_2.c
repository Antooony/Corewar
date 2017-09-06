/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:05:13 by adenis            #+#    #+#             */
/*   Updated: 2017/09/06 17:29:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_label		*ft_newlabel(void)
{
	t_label		*new;

	new = (t_label *)malloc(sizeof(t_label));
	new->name = NULL;
	new->ops = NULL;
	new->firstop = NULL;
	new->next = NULL;
	return (new);
}

t_ops		*ft_newop(void)
{
	t_ops	*new;

	new = (t_ops *)malloc(sizeof(t_ops));
	new->name = NULL;
	new->args = NULL;
	new->next = NULL;
	return (new);
}

void	init_label(void)
{
	LABEL = ft_newlabel();
	if (!FLABEL)
		FLABEL = LABEL;
}

void	init_ops(void)
{
	OP = ft_newop();
	if (!FOP)
		FOP = OP;
}

void	init_infos(void)
{
	g_infos.name = NULL;
	g_infos.comment = NULL;
	g_infos.labels = NULL;
	g_infos.firstlabel = NULL;
}
