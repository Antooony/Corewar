/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_cc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:49:17 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:24:13 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lencc(char **str)
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

static void		ft_acccc(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (!g_arg.acc)
		*str[0] = '\0';
	if (g_arg.acc < (int)ft_strlen(*str))
	{
		tmp = ft_strsub(*str, 0, g_arg.acc);
		ft_strdel(str);
		*str = tmp;
	}
}

void			ft_convcc(va_list ap)
{
	char	*str;
	wchar_t	c;

	if ((c = va_arg(ap, wchar_t)))
		str = wtoa(c);
	else
	{
		g_arg.len -= 1;
		g_arg.ret += 1;
		str = ft_strnew(0);
	}
	if (g_arg.vacc)
		ft_acccc(&str);
	if (g_arg.len)
		ft_lencc(&str);
	g_arg.ret += ft_strlen(str);
	if (ft_strchr(g_arg.opt, '-') && !c)
		ft_putwchar_fd(c, g_arg.fd);
	ft_putstr_fd(str, g_arg.fd);
	if (!ft_strchr(g_arg.opt, '-') && !c)
		ft_putwchar_fd(c, g_arg.fd);
	ft_strdel(&str);
}

void			ft_sconvcc(va_list ap)
{
	char	*str;
	wchar_t	c;

	if ((c = va_arg(ap, wchar_t)))
		str = wtoa(c);
	else
	{
		g_arg.len -= 1;
		g_arg.ret += 1;
		str = ft_strnew(0);
	}
	if (g_arg.vacc)
		ft_acccc(&str);
	if (g_arg.len)
		ft_lencc(&str);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
