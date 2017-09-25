/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:11:52 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:35:09 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int		k;

	k = 0;
	while (n >= 1)
	{
		k++;
		n = n / 10;
	}
	return (k);
}

int		ft_check_args(void)
{
	if (!g_arg.conv)
		return (-1);
	if ((ft_strlen(g_arg.size) > 2))
		return (-1);
	if ((ft_strlen(g_arg.size) == 2) && g_arg.size[0] != g_arg.size[1])
		return (-1);
	return (1);
}

char	*ft_checksign(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 99;
	tmp = ft_strdup(str);
	while (str[i] && str[i] != '-' && str[i] != '+')
		i++;
	if (i != 0 && i < (int)ft_strlen(str))
		j = i - 1;
	if (str[j] != '0')
	{
		ft_strdel(&tmp);
		return (str);
	}
	while (str[j] && str[j] == '0' && j > -1)
		j--;
	j++;
	tmp[j] = str[i];
	tmp[i] = str[j];
	ft_strdel(&str);
	return (tmp);
}
