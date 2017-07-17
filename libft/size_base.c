/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:27:17 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:34:44 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_x_l(va_list ap, char **str, char *base, int val)
{
	*str = ft_itoa_base(((uintmax_t)va_arg(ap, long)), base, val);
}

void	ft_x_ll(va_list ap, char **str, char *base, int val)
{
	*str = ft_itoa_base(((uintmax_t)va_arg(ap, long long)), base, val);
}

void	ft_x_h(va_list ap, char **str, char *base, int val)
{
	*str = ft_itoa_base(((uintmax_t)\
		(unsigned short)va_arg(ap, int)), base, val);
}

void	ft_x_hh(va_list ap, char **str, char *base, int val)
{
	*str = ft_itoa_base(((uintmax_t)(unsigned char)va_arg(ap, int)), base, val);
}

void	ft_x_j(va_list ap, char **str, char *base, int val)
{
	*str = ft_itoa_base((va_arg(ap, intmax_t)), base, val);
}
