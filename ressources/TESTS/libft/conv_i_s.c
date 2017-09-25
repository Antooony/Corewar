/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:58:20 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 15:50:02 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_sizei(va_list ap, char **str)
{
	if (ft_strlen(g_arg.size) == 1 && ft_strchr(SIZE, g_arg.size[0]))
		g_size_i[ft_strchr(SIZE, g_arg.size[0]) - SIZE](ap, str);
	else if (!ft_strcmp(g_arg.size, "ll"))
		g_size_i[3](ap, str);
	else if (!ft_strcmp(g_arg.size, "hh"))
		g_size_i[4](ap, str);
	else
		*str = ft_itoa(va_arg(ap, int));
}

static void		ft_opti(char **str)
{
	if (!g_arg.opt || ft_strchr(*str, '-'))
		return ;
	if (ft_strchr(g_arg.opt, '+'))
		*str = ft_strjoinfree(ft_strdup("+"), *str);
	else if (ft_strchr(g_arg.opt, ' ') && ft_strchr(g_arg.opt, '-'))
		*str = ft_strjoinfree(ft_strdup(" "), *str);
	else if (ft_strchr(g_arg.opt, ' ') && !g_arg.len)
		*str = ft_strjoinfree(ft_strdup(" "), *str);
}

static void		ft_leni(char **str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if (ft_strlen(*str) && g_arg.len < (int)ft_strlen(*str))
		return ;
	else
		tmp = ft_strnew(g_arg.len - ft_strlen(*str));
	if (ft_strchr(g_arg.opt, '0') && !ft_strchr(g_arg.opt, '-') && !g_arg.vacc)
	{
		ft_memset(tmp, '0', (g_arg.len - ft_strlen(*str)));
		if (ft_strchr(g_arg.opt, ' ') && !ft_strchr(*str, '-'))
			tmp[0] = ' ';
	}
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

static void		ft_acci(char **str)
{
	char	*tmp;

	if (!g_arg.vacc)
		return ;
	tmp = NULL;
	if (g_arg.acc > (int)ft_strlen(*str))
	{
		tmp = ft_strnew(g_arg.acc - ft_strlen(*str));
		ft_memset(tmp, '0', (g_arg.acc - ft_strlen(*str)));
		if (ft_strchr(g_arg.opt, ' '))
			tmp = ft_strjoinfree(ft_strdup(" "), tmp);
		*str = ft_strjoinfree(tmp, *str);
	}
}

void			ft_sconvi(va_list ap)
{
	char	*str;

	if (g_arg.conv == 'D')
		ft_int_l(ap, &str);
	else
		ft_sizei(ap, &str);
	if (!ft_strcmp(str, "0"))
		g_arg.zero = 1;
	if (str[0] == '-')
		g_arg.acc += 1;
	if (g_arg.vacc && !g_arg.acc && !ft_strcmp(str, "0"))
		str[0] = '\0';
	ft_acci(&str);
	ft_opti(&str);
	if (g_arg.len)
		ft_leni(&str);
	g_arg.ret += ft_strlen(str);
	if (ft_strchr(str, '+') || ft_strchr(str, '-'))
		str = ft_checksign(str);
	join_out(str);
}
