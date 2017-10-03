/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:48:56 by adenis            #+#    #+#             */
/*   Updated: 2017/10/03 16:05:18 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_output	*new_output(char *name, int type)
{
	t_output	*new;

	new = (t_output *)malloc(sizeof(t_output));
	new->val = 0;
	new->size =  0;
	new->name = name;
	new->next = NULL;
	new->link = NULL;
	new->type = type;
	return (new);
}

void		link_op(t_output *pop, int narg)
{
	t_output	*tmp;

	if (pop->type != 8)
		return ;
	tmp = pop;
	while (narg && tmp->next)
	{
		tmp = tmp->next;
		tmp->link = pop;
		narg--;
	}
}

void		output_add(t_output *out, t_output *new)
{
	if (out->next)
		output_add(out->next, new);
	else
		out->next = new;
}

void		fill_output(void)
{
	t_output	*tmp;

	tmp = OUT;
	while (tmp)
	{
		g_ft_tab[tmp->type](tmp);
		link_op(tmp, g_op_tab[whichop(tmp->name)].num_params);
		tmp = tmp->next;
	}
}

void		create_output(t_token *token)
{
	while (token)
	{
		if (OUT)
			output_add(OUT, new_output(token->unknow, get_value(token)));
		else
			OUT = new_output(token->unknow, get_value(token));
		token = token->next;
	}
	fill_output();
}
