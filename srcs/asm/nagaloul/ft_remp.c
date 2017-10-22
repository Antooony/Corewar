/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:21:03 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 16:46:00 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

char		**ft_remp(char **tab, char const *s, int g)
{
	int		i;
	int		l;
	int		v;

	i = 0;
	l = 0;
	v = 0;
	while (s[i] != '\0' && l < g)
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			tab[l][v] = s[i];
			i++;
			v++;
		}
		tab[l][v] = '\0';
		l++;
		v = 0;
	}
	tab[l] = 0;
	return (tab);
}
