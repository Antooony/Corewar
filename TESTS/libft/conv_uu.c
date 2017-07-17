/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:44:12 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:26:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lenu(char **str)
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

static void		ft_accu(char **str)
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

void			ft_convuu(va_list ap)
{
	char	*str;

	ft_u_l(ap, &str);
	if (g_arg.vacc && !g_arg.acc && !ft_strcmp(str, "0"))
		str[0] = '\0';
	if (g_arg.vacc)
		ft_accu(&str);
	if (g_arg.len)
		ft_lenu(&str);
	g_arg.ret += ft_strlen(str);
	ft_putstr_fd(str, g_arg.fd);
	ft_strdel(&str);
}

void			ft_sconvuu(va_list ap)
{
	char	*str;

	ft_u_l(ap, &str);
	if (g_arg.vacc && !g_arg.acc && !ft_strcmp(str, "0"))
		str[0] = '\0';
	if (g_arg.vacc)
		ft_accu(&str);
	if (g_arg.len)
		ft_lenu(&str);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
