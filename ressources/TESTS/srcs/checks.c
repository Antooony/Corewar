/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:11:47 by adenis            #+#    #+#             */
/*   Updated: 2017/06/29 10:31:36 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		isop(char *s)
{
	int		i;

	i = 0;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(s, op_tab[i].name))
			return (i);
		i++;
	}
	return (-1);
}

int		islabel(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == LABEL_CHAR && i)
			return (i + 1);
		if (!ft_strchr(LABEL_CHARS, s[i]))
			return (0);
		i++;
	}
	return (0);
}

int		isspace(char c)
{
	if (c == 32 || c == 9 || c == 10)
		return (1);
	return (0);
}
