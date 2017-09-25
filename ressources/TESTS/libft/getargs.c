/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getargs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:56:29 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:35:21 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_handle_size(char *s)
{
	char	*s2;

	s2 = NULL;
	if (ft_strchr(s, 'j'))
		s2 = ft_strdup("j");
	else if (ft_strstr(s, "ll"))
		s2 = ft_strdup("ll");
	else if (ft_strchr(s, 'l'))
		s2 = ft_strdup("l");
	else if (ft_strchr(s, 'z'))
		s2 = ft_strdup("z");
	else if (ft_strcmp(s, "hh") && ft_strchr(s, 'h'))
		s2 = ft_strdup("h");
	else if (ft_strstr(s, "hh"))
		s2 = ft_strdup("hh");
	ft_strdel(&s);
	return (s2);
}

int			ft_get_nbr(char *str, int *i)
{
	int		j;
	char	*tmp;
	int		ret;

	j = 0;
	while (ft_isdigit(str[j]))
		j++;
	if (j == 0)
		return (0);
	tmp = ft_strsub(str, 0, j);
	ret = ft_atoi(tmp);
	*i += ft_strlen(tmp);
	ft_strdel(&tmp);
	return (ret);
}

char		*ft_get_size(char *str, int *i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (ft_strchr(SIZE, str[j]))
		j++;
	if ((*i + j) > g_arg.max)
		*i = g_arg.max;
	else
		*i += j;
	tmp = ft_strsub(str, 0, j);
	return (ft_handle_size(tmp));
}

void		ft_getargs(char *str, int *i, va_list ap)
{
	while (str[*i] && !g_arg.conv && *i < g_arg.max)
	{
		if (ft_strchr(OPT, str[*i]))
			g_arg.opt = ft_get_opt(&str[*i], i);
		else if (ft_isdigit(str[*i]) || str[*i] == '*')
			g_arg.len = ft_get_len(&str[*i], i, ap);
		else if (str[*i] == '.')
		{
			*i += 1;
			g_arg.vacc = 1;
			g_arg.acc = ft_get_acc(&str[*i], i, ap);
		}
		else if (ft_strchr(SIZE, str[*i]))
		{
			ft_strdel(&g_arg.size);
			g_arg.size = ft_get_size(&str[*i], i);
		}
		else if (ft_strchr(CONV, str[*i]))
		{
			g_arg.conv = str[*i];
			*i += 1;
		}
		else
			break ;
	}
}
