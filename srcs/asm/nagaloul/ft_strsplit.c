/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:01:06 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 17:20:15 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

char		**ft_taille(char **tab, char const *s, int g)
{
	int		i;
	int		k;
	int		l;

	l = 0;
	k = 0;
	i = 0;
	while (s[i] != '\0' && l < g)
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			i++;
			k++;
		}
		if (!(tab[l] = (char*)malloc(sizeof(char) * (k + 1))))
			return (NULL);
		l++;
		k = 0;
	}
	return (tab);
}

char		**ft_strsplit(char const *s)
{
	char	**str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_decoupe(s);
	if (!(str = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	ft_taille(str, s, i);
	ft_remp(str, s, i);
	return (str);
}
