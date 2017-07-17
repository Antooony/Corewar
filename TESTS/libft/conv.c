/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:54:24 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:20:52 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conv(va_list ap, char *s, int *i)
{
	int		val;

	if (!g_arg.conv)
		ft_noconv(s, i);
	else
	{
		val = (ft_strchr(CONV, g_arg.conv) - CONV);
		if (val == 14)
			ft_convper();
		else
			g_ft[val](ap);
	}
}

void	ft_sconv(va_list ap, char *s, int *i)
{
	int		val;

	if (!g_arg.conv)
		ft_snoconv(s, i);
	else
	{
		val = (ft_strchr(CONV, g_arg.conv) - CONV);
		if (val == 14)
			ft_sconvper();
		else
			g_sft[val](ap);
	}
}
