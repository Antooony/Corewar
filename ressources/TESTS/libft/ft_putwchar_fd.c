/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:18:55 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:15:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nblen(int nb)
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

static void		ft_o4(int nb, int fd)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;

	o1 = 240;
	o2 = 128;
	o3 = 128;
	o4 = 128;
	o4 = o4 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o3 = o3 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o2 = o2 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o1 = o1 | nb;
	write(fd, &o1, 1);
	write(fd, &o2, 1);
	write(fd, &o3, 1);
	write(fd, &o4, 1);
}

static void		ft_o3(int nb, int fd)
{
	int		o1;
	int		o2;
	int		o3;

	o1 = 224;
	o2 = 128;
	o3 = 128;
	o3 = o3 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o2 = o2 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o1 = o1 | nb;
	write(fd, &o1, 1);
	write(fd, &o2, 1);
	write(fd, &o3, 1);
}

static void		ft_o2(int nb, int fd)
{
	int		o1;
	int		o2;

	o1 = 224;
	o2 = 128;
	o2 = o2 | ((nb >> 6) << 6 ^ nb);
	nb = nb >> 6;
	o1 = o1 | nb;
	write(fd, &o1, 1);
	write(fd, &o2, 1);
}

void			ft_putwchar_fd(wchar_t c, int fd)
{
	int		len;

	len = get_nblen((int)c);
	if (len <= 7)
		write(fd, &c, 1);
	else if (len > 7 && len <= 11)
		ft_o2(c, fd);
	else if (len > 11 && len <= 16)
		ft_o3(c, fd);
	else
		ft_o4(c, fd);
}
