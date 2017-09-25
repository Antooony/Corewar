/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ss_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:11:46 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 15:43:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lens(char **str, char *s)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if (g_arg.len < (int)ft_strlen(*str))
		return ;
	else
		tmp = ft_strnew(g_arg.len - ft_strlen(*str));
	if (ft_strchr(s, '0') && !ft_strchr(s, '-'))
		ft_memset(tmp, '0', (g_arg.len - ft_strlen(*str)));
	else
		ft_memset(tmp, ' ', (g_arg.len - ft_strlen(*str)));
	tmp2 = ft_strdup(*str);
	if (ft_strchr(s, '-'))
		*str = ft_strjoinfree(tmp2, tmp);
	else
		*str = ft_strjoinfree(tmp, tmp2);
}

static void		ft_checkval(unsigned char c, int *j)
{
	if (c <= 127)
		*j = 1;
	else if (c <= 223)
		*j = 2;
	else if (c <= 239)
		*j = 3;
	else if (c <= 247)
		*j = 4;
	return ;
}

static int		get_accss(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		ft_checkval(str[i], &j);
		if (i + j <= g_arg.acc)
			i += j;
		else
			break ;
	}
	return (i);
}

static void		ft_accs(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (!g_arg.acc)
		*str[0] = '\0';
	if (g_arg.acc < (int)ft_strlen(*str))
	{
		tmp = ft_strsub(*str, 0, get_accss(*str));
		ft_strdel(str);
		*str = tmp;
	}
}

void			ft_sconvss(va_list ap)
{
	char	*str;
	char	*s;

	s = ft_strdup(g_arg.opt);
	if (!(str = get_wstr(ap)))
		str = ft_strdup("(null)");
	if (g_arg.vacc)
		ft_accs(&str);
	if (g_arg.len)
		ft_lens(&str, s);
	free(s);
	g_arg.ret += ft_strlen(str);
	join_out(str);
}
