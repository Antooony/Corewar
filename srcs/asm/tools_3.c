/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:37:22 by adenis            #+#    #+#             */
/*   Updated: 2017/09/13 13:29:20 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	clean_spaces(int j)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!OP->args[j])
		return ;
	while (!ft_strchr(BLANK, OP->args[j][i]))
		i++;
	tmp = ft_strsub(OP->args[j], 0, i);
	free(OP->args[j]);
	OP->args[j] = tmp;
}

void	free_ops(t_ops *op)
{
	int		i;

	i = 0;
	if (!op)
		return ;
	if (op->next)
		free_ops(op->next);
	op->name ? ft_strdel((char **)&op->name) : NULL;
	while (i < op->nargs)
	{
		op->args[i] ? ft_strdel((char **)&op->args[i]) : NULL;
		i++;
	}
	op->args ? free(op->args) : NULL;
	free(op);
}

void	free_labels(t_label *label)
{
	if (!label)
		return ;
	if (label->next)
		free_labels(label->next);
	label->name ? ft_strdel((char **)&label->name) : NULL;
	free_ops(label->firstop);
	label ? free(label) : NULL;
}

void	del(void *content, size_t size)
{
	if (content)
		free(content);
	content = NULL;
	size = 0;
}

void	leave_free(void)
{
	INPUT ? ft_lstdel(&INPUT, &del) : NULL;
	g_infos.name ? ft_strdel((char **)&g_infos.name) : NULL;
	g_infos.comment ? ft_strdel((char **)&g_infos.comment) : NULL;
	FLABEL ? free_labels(FLABEL) : NULL;
	exit(0);
}
