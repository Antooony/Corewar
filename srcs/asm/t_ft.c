/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:32:29 by adenis            #+#    #+#             */
/*   Updated: 2017/10/02 19:15:48 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		*ft_lab(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 0;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_comment(char *s)
{
	return (NULL);
}

int		*ft_dirlab(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 2;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_indirlab(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 2;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_dir(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 4;
	out[1] = 0;
	n = out;
	return (n);
}
