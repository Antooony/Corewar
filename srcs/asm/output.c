/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:48:56 by adenis            #+#    #+#             */
/*   Updated: 2017/11/04 15:30:59 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_output	*new_output(char *name, int type)
{
	t_output	*new;

	if (!(new = (t_output *)malloc(sizeof(t_output))))
		exit(0);
	new->val = 0;
	new->size = 0;
	new->name = name;
	new->next = NULL;
	new->link = NULL;
	new->type = type;
	new->pos = 0;
	return (new);
}

void		link_op(t_output *pop, int narg)
{
	t_output	*tmp;

	if (pop->type != 9)
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
	int			count;
	int			name;

	name = 0;
	count = 0;
	tmp = OUT;
	while (tmp)
	{
		g_ft_tab[tmp->type](tmp);
		link_op(tmp, g_op_tab[whichop(tmp->name)].num_params);
		tmp->pos = count;
		count += tmp->size;
		tmp = tmp->next;
	}
	PROG_SIZE = count;
}
char		*getattribute(t_token *tok)
{
	if (tok->reg)
		return(tok->reg);
	else if (tok->lab)
		return(tok->lab);
	else if (tok->comment)
		return(tok->comment);
	else if (tok->dirlab)
		return(tok->dirlab);
	else if (tok->indirlab)
		return(tok->indirlab);
	else if (tok->dir)
		return(tok->dir);
	else if (tok->name)
		return(tok->name);
	else if (tok->ncom)
		return(tok->ncom);
	else if (tok->indir)
		return(tok->indir);
	return (tok->unknow);
}

void		create_output(t_token *token)
{
	while (token)
	{
		if (OUT)
			output_add(OUT, new_output(getattribute(token), get_value(token)));
		else
			OUT = new_output(getattribute(token), get_value(token));
		token = token->next;
	}
	fill_output();
}

