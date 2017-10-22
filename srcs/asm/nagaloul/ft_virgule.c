/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_virgule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:58:09 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 17:57:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_finishim(char **tab)
{
	int a;

	a = 0;
	while (tab[a])
		a++;
	a--;
	if (ft_lastchar(tab[a]) == ',')
	{
		ft_freetab(tab);
		return (0);
	}
	if (ft_strchr(tab[a], ','))
		return (1);
	a--;
	if (ft_lastchar(tab[a]) == ',')
		return (1);
	ft_freetab(tab);
	return (0);
}

int		ft_finish(char **tab)
{
	if (ft_finishim(tab))
	{
		if (tab[1][0] == ',')
		{
			ft_freetab(tab);
			return (0);
		}
		else
			return (1);
	}
	return (0);
}

int		ft_virgule(int i, t_list *sep, int c)
{
	int		a;
	char	**tab;
	char 	*s;

	a = 0;
	while (++a < i)
		sep = sep->next;
	s = sep->content;
	a = 0;
	while (s[a] != '\0' && s[a] != '#')
		a++;
	s[a] = '\0';
	if (ft_countchar(s, ',') != c - 1)
		return (0);
	tab = ft_strsplit(s);
	if (c == 2)
		if (!ft_finishim(tab))
			return (0);
	if (c == 3)
		if (!ft_finish(tab))
			return (0);
	ft_freetab(tab);
	return (1);
}
