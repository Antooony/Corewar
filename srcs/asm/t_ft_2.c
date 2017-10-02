/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ft_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:34:29 by adenis            #+#    #+#             */
/*   Updated: 2017/10/02 16:34:39 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		*ft_name(char *s)
{
	return (NULL);
}

int		*ft_ncom(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_indir(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 2;
	out[1] = ft_atoi(&s[1]);
	n = out;
	return (n);
}

int		*ft_inst(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	if (g_op_tab[whichop(s)].coding_param)
		out[0]++;
	out[1] = whichop(s) + 1;
	n = out;
	return (n);
}

int		*ft_reg(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = ft_atoi(&s[1]);
	n = out;
	return (n);
}
