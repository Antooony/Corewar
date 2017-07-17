/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:52:42 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:25:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lenper(char **str)
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

static void		ft_accper(char **str)
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

void			ft_convper(void)
{
	char	*str;

	str = ft_strdup("%");
	if (g_arg.acc)
		ft_accper(&str);
	if (g_arg.len)
		ft_lenper(&str);
	g_arg.ret += ft_strlen(str);
	ft_putstr_fd(str, g_arg.fd);
	ft_strdel(&str);
}

void			ft_sconvper(void)
{
	char	*str;

	str = ft_strdup("%");
	if (g_arg.acc)
		ft_accper(&str);
	if (g_arg.len)
		ft_lenper(&str);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
