/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:39:04 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:25:33 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lens(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (g_arg.len < (int)ft_strlen(*str))
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

static void		ft_accs(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (!g_arg.acc)
		*str[0] = '\0';
	if (g_arg.acc < (int)ft_strlen(*str))
	{
		tmp = *str;
		tmp[g_arg.acc] = '\0';
	}
}

void			ft_convs(va_list ap)
{
	char	*str;

	if (ft_strchr(g_arg.size, 'l'))
	{
		ft_convss(ap);
		return ;
	}
	if ((str = va_arg(ap, char *)))
		str = ft_strdup(str);
	else
		str = ft_strdup("(null)");
	if (g_arg.vacc)
		ft_accs(&str);
	if (g_arg.len)
		ft_lens(&str);
	g_arg.ret += ft_strlen(str);
	ft_putstr_fd(str, g_arg.fd);
	ft_strdel(&str);
}

void			ft_sconvs(va_list ap)
{
	char	*str;

	if (ft_strchr(g_arg.size, 'l'))
	{
		ft_convss(ap);
		return ;
	}
	if ((str = va_arg(ap, char *)))
		str = ft_strdup(str);
	else
		str = ft_strdup("(null)");
	if (g_arg.vacc)
		ft_accs(&str);
	if (g_arg.len)
		ft_lens(&str);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
