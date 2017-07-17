/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:06:33 by adenis            #+#    #+#             */
/*   Updated: 2016/11/14 14:56:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_pc(int i, char *str)
{
	if (str[i - 1] >= '0' && str[i - 1] <= '9')
		return (1);
	else
		return (0);
}

static int		ft_nc(int i, char *str)
{
	if (str[i + 1] >= '0' && str[i + 1] <= '9')
		return (1);
	else
		return (0);
}

static int		ft_space(int i, char *str)
{
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		return (1);
	else
		return (0);
}

static int		ft_sign(int i, char *str, int sign)
{
	if (str[i] == '-')
		return (sign *= -1);
	else
		return (sign);
}

int				ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && ft_nc(i, str) && !ft_pc(i, str))
		{
			sign = ft_sign(i, str, sign);
			i++;
		}
		else if ((ft_space(i, str) && !ft_pc(i, str)))
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + str[i] - '0';
			i++;
		}
		else
			break ;
	}
	return (sign * nb);
}
