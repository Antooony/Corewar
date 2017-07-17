/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:32:36 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:23:59 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lenc(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (!g_arg.len || g_arg.len < (int)ft_strlen(*str))
		return ;
	else
		tmp = ft_strnew(g_arg.len - ft_strlen(*str));
	if (ft_strchr(g_arg.opt, '0') && !ft_strchr(g_arg.opt, '-'))
		ft_memset(tmp, '0', (g_arg.len - ft_strlen(*str)));
	else
		ft_memset(tmp, ' ', (g_arg.len - ft_strlen(*str)));
	if (ft_strchr(g_arg.opt, '-'))
		*str = ft_strjoinfree(*str, tmp);
	else
		*str = ft_strjoinfree(tmp, *str);
}

void			ft_convc(va_list ap)
{
	char	*str;
	char	c;

	if (ft_strchr(g_arg.size, 'l'))
	{
		ft_convcc(ap);
		return ;
	}
	str = ft_strnew(1);
	c = va_arg(ap, int);
	str[0] = c;
	if (c == 0)
	{
		if (ft_strchr(g_arg.opt, '-'))
			ft_putchar_fd('\0', g_arg.fd);
		g_arg.len -= 1;
		g_arg.ret += 1;
	}
	ft_lenc(&str);
	ft_putstr_fd(str, g_arg.fd);
	if (!ft_strchr(g_arg.opt, '-') && !c)
		ft_putchar_fd('\0', g_arg.fd);
	g_arg.ret += ft_strlen(str);
	ft_strdel(&str);
}

void			ft_sconvc(va_list ap)
{
	char	*str;
	char	c;

	if (ft_strchr(g_arg.size, 'l'))
	{
		ft_convcc(ap);
		return ;
	}
	str = ft_strnew(1);
	c = va_arg(ap, int);
	str[0] = c;
	if (c == 0)
	{
		g_arg.len -= 1;
		g_arg.ret += 1;
	}
	ft_lenc(&str);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
