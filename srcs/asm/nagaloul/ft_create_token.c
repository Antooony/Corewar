/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 19:22:01 by nagaloul          #+#    #+#             */
/*   Updated: 2017/09/28 15:49:56 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

t_token		*ft_create_token(char *data, int i, int b)
{
	t_token	*elem;

	elem = NULL;
	elem = malloc(sizeof(t_token));
	if (elem)
	{
		elem->unknow = ft_strdup(data);
		elem->col = i;
		elem->lan = b;
		elem->lab = NULL;
		elem->comment = NULL;
		elem->dirlab = NULL;
		elem->indirlab = NULL;
		elem->dir = NULL;
		elem->name = NULL;
		elem->ncom = NULL;
		elem->indir = NULL;
		elem->inst = NULL;
		elem->reg = NULL;
		elem->next = NULL;
	}
	return (elem);
}
