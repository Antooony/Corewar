/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:37 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:24:52 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_sizeo(va_list ap, char **str, char *base, int val)
{
	if (ft_strlen(g_arg.size) == 1 && ft_strchr(SIZE, g_arg.size[0]))
		g_size_x[ft_strchr(SIZE, g_arg.size[0]) - SIZE](ap, str, base, val);
	else if (!ft_strcmp(g_arg.size, "ll"))
		g_size_x[3](ap, str, base, val);
	else if (!ft_strcmp(g_arg.size, "hh"))
		g_size_x[4](ap, str, base, val);
	else
		*str = ft_itoa_base((uintmax_t)va_arg(ap, unsigned int), base, val);
}

static void		ft_opto(char **str)
{
	if (ft_strchr(g_arg.opt, '#') && !g_arg.acc && !g_arg.zero)
		*str = ft_strjoinfree(ft_strdup("0"), *str);
}

static void		ft_leno(char **str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if (g_arg.len < (int)ft_strlen(*str))
		return ;
	else
		tmp = ft_strnew(g_arg.len - ft_strlen(*str));
	if (ft_strchr(g_arg.opt, '0') && !ft_strchr(g_arg.opt, '-')
		&& !g_arg.vacc)
		ft_memset(tmp, '0', (g_arg.len - ft_strlen(*str)));
	else
		ft_memset(tmp, ' ', (g_arg.len - ft_strlen(*str)));
	tmp2 = ft_strnew(ft_strlen(tmp));
	tmp2 = ft_strcpy(tmp2, tmp);
	if (ft_strchr(g_arg.opt, '-'))
		*str = ft_strjoinfree(*str, tmp2);
	else
		*str = ft_strjoinfree(tmp2, *str);
	ft_strdel(&tmp);
}

static void		ft_acco(char **str)
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

void			ft_convo(va_list ap)
{
	char	*str;

	if (g_arg.conv == 'O')
		str = ft_itoa_base(((uintmax_t)va_arg(ap, long)), OCTAL, 8);
	else
		ft_sizeo(ap, &str, OCTAL, 8);
	if (!ft_strcmp(str, "0"))
		g_arg.zero = 1;
	if (!ft_strchr(g_arg.opt, '#') && g_arg.vacc && !g_arg.acc
		&& !ft_strcmp(str, "0"))
		str[0] = '\0';
	if (g_arg.vacc)
		ft_acco(&str);
	if (g_arg.opt)
		ft_opto(&str);
	if (g_arg.len)
		ft_leno(&str);
	g_arg.ret += ft_strlen(str);
	ft_putstr_fd(str, g_arg.fd);
	ft_strdel(&str);
}
