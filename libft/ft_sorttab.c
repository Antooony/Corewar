/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:07:12 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:33:53 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_issort(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void			ft_sort_tab(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
		}
		i++;
		if (!tab[i + 1] && !ft_issort(tab))
			i = 0;
	}
	i = 0;
}
