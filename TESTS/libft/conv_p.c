/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:43:18 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:25:06 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lenp(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (g_arg.len < (int)ft_strlen(*str))
		return ;
	else
		tmp = ft_strnew(g_arg.len - ft_strlen(*str));
	ft_memset(tmp, ' ', (g_arg.len - ft_strlen(*str)));
	if (ft_strchr(g_arg.opt, '0') && !ft_strchr(g_arg.opt, '-')
		&& !g_arg.vacc)
		ft_memset(tmp, '0', (g_arg.len - ft_strlen(*str)));
	if (ft_strchr(g_arg.opt, '-'))
		*str = ft_strjoinfree(*str, tmp);
	else
		*str = ft_strjoinfree(tmp, *str);
}

static void		ft_optp(char **str)
{
	if (ft_strchr(g_arg.opt, '0') && (g_arg.len -= 2))
	{
		ft_lenp(str);
		g_arg.len = 0;
	}
	*str = ft_strjoinfree(ft_strdup("0x"), *str);
}

static void		ft_accp(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (g_arg.acc > (int)ft_strlen(*str))
	{
		tmp = ft_strnew(g_arg.acc - ft_strlen(*str));
		ft_memset(tmp, '0', (g_arg.acc - ft_strlen(*str)));
		*str = ft_strjoinfree(tmp, *str);
	}
}

void			ft_convp(va_list ap)
{
	char	*str;

	str = ft_itoa_base((uintmax_t)va_arg(ap, long), HEXA, 16);
	if (!ft_strcmp(str, "0") && g_arg.vacc && !g_arg.acc)
		str[0] = '\0';
	if (g_arg.vacc)
		ft_accp(&str);
	if (g_arg.opt)
		ft_optp(&str);
	if (g_arg.len)
		ft_lenp(&str);
	g_arg.ret += ft_strlen(str);
	ft_putstr_fd(str, g_arg.fd);
	ft_strdel(&str);
}

void			ft_sconvp(va_list ap)
{
	char	*str;

	str = ft_itoa_base((uintmax_t)va_arg(ap, long), HEXA, 16);
	if (!ft_strcmp(str, "0") && g_arg.vacc && !g_arg.acc)
		str[0] = '\0';
	if (g_arg.vacc)
		ft_accp(&str);
	if (g_arg.opt)
		ft_optp(&str);
	if (g_arg.len)
		ft_lenp(&str);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
