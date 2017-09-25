/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:10:43 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:45:18 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_init(char *str, int fd)
{
	g_arg.ret = 0;
	g_arg.fd = fd;
	g_arg.max = ft_strlen(str);
}

static void		ft_manage(va_list ap, char *str, int *i)
{
	init_args();
	ft_getargs(str, i, ap);
	ft_conv(ap, str, i);
	clean_args();
}

int				ft_printf(char *str, ...)
{
	va_list		ap;
	int			i;

	if (!str)
		exit(0);
	va_start(ap, str);
	i = 0;
	ft_init(str, 1);
	while (str[i])
	{
		if (str[i] == '%' && (i += 1))
		{
			if (!str[i])
				break ;
			ft_manage(ap, str, &i);
		}
		else
		{
			g_arg.ret += 1;
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (g_arg.ret);
}

int				ft_fprintf(int fd, char *str, ...)
{
	va_list		ap;
	int			i;

	if (!str)
		exit(0);
	va_start(ap, str);
	i = 0;
	ft_init(str, fd);
	while (str[i])
	{
		if (str[i] == '%' && (i += 1))
		{
			if (!str[i])
				break ;
			ft_manage(ap, str, &i);
		}
		else
		{
			g_arg.ret += 1;
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	va_end(ap);
	return (g_arg.ret);
}
