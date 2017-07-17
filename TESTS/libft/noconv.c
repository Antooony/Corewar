/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:03:13 by adenis            #+#    #+#             */
/*   Updated: 2017/06/02 12:37:38 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lenno(char **str)
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

void			ft_noconv(char *s, int *i)
{
	char	*str;

	if (*i == g_arg.max)
		return ;
	if (!(str = ft_strnew(1)))
		return ;
	str[0] = s[*i];
	if (g_arg.len)
		ft_lenno(&str);
	g_arg.ret += ft_strlen(str);
	(*i)++;
	ft_putstr(str);
	ft_strdel(&str);
}

void			ft_snoconv(char *s, int *i)
{
	char	*str;

	if (*i == g_arg.max)
		return ;
	str = ft_strnew(1);
	str[0] = s[*i];
	if (g_arg.len)
		ft_lenno(&str);
	g_arg.ret += ft_strlen(str);
	(*i)++;
	join_out(str);
}
