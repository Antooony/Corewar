/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:43:00 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:34:48 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_l(va_list ap, char **str)
{
	intmax_t n;

	n = (intmax_t)va_arg(ap, long);
	if (n < 0)
	{
		g_arg.sign = 1;
		n *= -1;
		*str = ft_strjoinfree(ft_strdup("-"), ft_uitoa(n));
	}
	else
		*str = ft_uitoa((uintmax_t)n);
}

void	ft_int_ll(va_list ap, char **str)
{
	intmax_t	n;

	n = (intmax_t)va_arg(ap, long long);
	if (n < 0)
	{
		g_arg.sign = 1;
		n *= -1;
		*str = ft_strjoinfree(ft_strdup("-"), ft_uitoa(n));
	}
	else
		*str = ft_uitoa((uintmax_t)n);
}

void	ft_int_h(va_list ap, char **str)
{
	intmax_t	n;

	n = (intmax_t)(short)va_arg(ap, int);
	if (n < 0)
	{
		g_arg.sign = 1;
		n *= -1;
		*str = ft_strjoinfree(ft_strdup("-"), ft_uitoa(n));
	}
	else
		*str = ft_uitoa((uintmax_t)n);
}

void	ft_int_hh(va_list ap, char **str)
{
	intmax_t	n;

	n = (intmax_t)(signed char)va_arg(ap, int);
	if (n < 0)
	{
		g_arg.sign = 1;
		n *= -1;
		*str = ft_strjoinfree(ft_strdup("-"), ft_uitoa(n));
	}
	else
		*str = ft_uitoa((uintmax_t)n);
}

void	ft_int_j(va_list ap, char **str)
{
	intmax_t	n;

	n = va_arg(ap, intmax_t);
	if (n < 0)
	{
		g_arg.sign = 1;
		n *= -1;
		*str = ft_strjoinfree(ft_strdup("-"), ft_uitoa(n));
	}
	else
		*str = ft_uitoa((uintmax_t)n);
}
