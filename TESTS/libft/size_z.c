/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:49:40 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:34:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_x_z(va_list ap, char **str, char *base, int val)
{
	*str = ft_itoa_base(((uintmax_t)va_arg(ap, size_t)), base, val);
}

void	ft_int_z(va_list ap, char **str)
{
	intmax_t n;

	n = (intmax_t)va_arg(ap, size_t);
	*str = ft_uitoa(n);
}

void	ft_u_z(va_list ap, char **str)
{
	*str = ft_uitoa((uintmax_t)va_arg(ap, size_t));
}
