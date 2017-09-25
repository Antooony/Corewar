/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:26:21 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:35:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_acc(char *str, int *i, va_list ap)
{
	int		j;

	if (str[0] == '*')
	{
		(*i)++;
		j = va_arg(ap, int);
		if (j < 0)
		{
			g_arg.vacc = 0;
			return (0);
		}
		return (j);
	}
	return (ft_get_nbr(str, i));
}

int			ft_get_len(char *str, int *i, va_list ap)
{
	int		j;

	if (str[0] == '*')
	{
		(*i)++;
		j = va_arg(ap, int);
		if (j < 0)
		{
			if (ft_strlen(g_arg.opt) >= 1)
				g_arg.opt = ft_strjoinfree(g_arg.opt, ft_strdup("-"));
			else
				g_arg.opt = ft_strdup("-");
			return ((j *= -1));
		}
		return (j);
	}
	return (ft_get_nbr(str, i));
}

char		*ft_get_opt(char *str, int *i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strnew(0);
	while (ft_strchr(OPT, str[j]))
	{
		if (!strchr(tmp, str[j]))
			tmp = ft_strjoinfree(tmp, ft_strsub(&str[j], 0, 1));
		j++;
	}
	if (g_arg.opt)
		tmp = ft_strjoinfree(g_arg.opt, tmp);
	if (j <= 0)
		return (0);
	if ((*i + j) > g_arg.max)
		*i = g_arg.max;
	else
		*i += j;
	return (tmp);
}

char		*get_wstr(va_list ap)
{
	wchar_t		*s;
	char		*str;
	char		*tmp;
	char		*tmp2;
	int			i;

	if (!(s = va_arg(ap, wchar_t *)))
		return (NULL);
	str = ft_strnew(0);
	i = 0;
	while (s[i])
	{
		tmp = wtoa(s[i]);
		tmp2 = ft_strnew(ft_strlen(tmp));
		tmp2 = ft_strcpy(tmp2, tmp);
		str = ft_strjoinfree(str, tmp2);
		free(tmp);
		i++;
	}
	return (str);
}
