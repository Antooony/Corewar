/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:48:56 by adenis            #+#    #+#             */
/*   Updated: 2017/10/02 18:28:53 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_output	*new_output(int size, int val, char *name)
{
	t_output	*new;

	new = (t_output *)malloc(sizeof(t_output));
	new->val = val;
	new->size = size;
	new->name = name;
	new->next = NULL;
	return (new);
}

void		output_add(t_output *out, t_output *new)
{
	if (out->next)
		output_add(out->next, new);
	else
		out->next = new;
}

void		fill_output(t_token *token)
{
	int		*out;
	int		i;

	i = get_value(token);
	if (i > 9)
		return ;
	out = (int *)g_ft_tab[i](token->unknow);
	if (!out)
		return ;
	if (OUT)
		output_add(OUT, new_output(out[0], out[1], token->unknow));
	else
		OUT = new_output(out[0], out[1], token->unknow);
}

void		create_output(t_token *token)
{
	while (token)
	{
		fill_output(token);
		token = token->next;
	}
}
