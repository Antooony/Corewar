/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:30:19 by adenis            #+#    #+#             */
/*   Updated: 2017/02/15 16:53:45 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_init(char *str)
{
	g_arg.ret = 0;
	g_arg.max = ft_strlen(str);
}

static void		s_to_out(char *str, int i)
{
	g_arg.ret += 1;
	if (!g_arg.out)
		g_arg.out = ft_strsub(str, i, 1);
	else
		g_arg.out = ft_strjoinfree(g_arg.out, ft_strsub(str, i, 1));
}

static void		ft_smanage(va_list ap, char *str, int *i)
{
	init_args();
	ft_getargs(str, i, ap);
	ft_sconv(ap, str, i);
	clean_args();
}

void			join_out(char *str)
{
	g_arg.ret += 1;
	if (!g_arg.out)
		g_arg.out = ft_strdup(str);
	else
		g_arg.out = ft_strjoinfree(g_arg.out, str);
}

int				ft_sprintf(char **dest, char *str, ...)
{
	va_list		ap;
	int			i;

	if (!str)
		exit(0);
	va_start(ap, str);
	i = 0;
	ft_init(str);
	while (str[i])
	{
		if (str[i] == '%' && (i += 1))
		{
			if (!str[i])
				break ;
			ft_smanage(ap, str, &i);
		}
		else
		{
			s_to_out(str, i);
			i++;
		}
	}
	va_end(ap);
	*dest = ft_strdup(g_arg.out);
	return (g_arg.ret);
}
