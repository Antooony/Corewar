/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:50:54 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:36:52 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_wcharlen(int nb)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb = nb / 2;
		i++;
	}
	return (i);
}

static char		*ft_o4(int nb)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;
	char	*str;

	o1 = 240;
	o2 = 128;
	o3 = 128;
	o4 = 128;
	str = ft_strnew(4);
	o4 = o4 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o3 = o3 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o2 = o2 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o1 = o1 | nb;
	str[0] = o1;
	str[1] = o2;
	str[2] = o3;
	str[3] = o4;
	return (str);
}

static char		*ft_o3(int nb)
{
	int		o1;
	int		o2;
	int		o3;
	char	*str;

	o1 = 224;
	o2 = 128;
	o3 = 128;
	str = ft_strnew(3);
	o3 = o3 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o2 = o2 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o1 = o1 | nb;
	str[0] = o1;
	str[1] = o2;
	str[2] = o3;
	return (str);
}

static char		*ft_o2(int nb)
{
	int		o1;
	int		o2;
	char	*str;

	o1 = 192;
	o2 = 128;
	str = ft_strnew(2);
	o2 = o2 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o1 = o1 | nb;
	str[0] = o1;
	str[1] = o2;
	return (str);
}

char			*wtoa(wchar_t c)
{
	int		len;
	char	*str;

	len = get_wcharlen((int)c);
	if (len <= 7)
	{
		str = ft_strnew(1);
		str[0] = c;
		return (str);
	}
	else if (len > 7 && len <= 11)
		return (ft_o2(c));
	else if (len > 11 && len <= 16)
		return (ft_o3(c));
	else
		return (ft_o4(c));
}
