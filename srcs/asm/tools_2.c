/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:58:23 by adenis            #+#    #+#             */
/*   Updated: 2017/11/11 19:58:43 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
