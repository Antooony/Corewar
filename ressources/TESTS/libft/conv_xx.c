/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:43:41 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:28:35 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_sizexx(va_list ap, char **str, char *base, int val)
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

static void			ft_lenxx(char **str)
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

static void			ft_optxx(char **str)
{
	if (g_arg.zero)
		return ;
	if (ft_strchr(g_arg.opt, '#') && *str[0])
	{
		if (ft_strchr(g_arg.opt, '0') && (g_arg.len -= 2))
		{
			ft_lenxx(str);
			g_arg.len = 0;
		}
		*str = ft_strjoinfree(ft_strdup("0X"), *str);
	}
}

static void			ft_accxx(char **str)
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

void				ft_convxx(va_list ap)
{
	char	*str;

	ft_sizexx(ap, &str, HEXAM, 16);
	if (ft_strlen(str) == 1 && str[0] == '0')
		g_arg.zero = 1;
	if (g_arg.vacc && !g_arg.acc && str[0] == '0')
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	if (g_arg.vacc && g_arg.acc)
		ft_accxx(&str);
	if (g_arg.opt)
		ft_optxx(&str);
	if (g_arg.len)
		ft_lenxx(&str);
	g_arg.ret += ft_strlen(str);
	ft_putstr_fd(str, g_arg.fd);
	ft_strdel(&str);
}
