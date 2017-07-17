/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:46 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:34:52 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_u_l(va_list ap, char **str)
{
	*str = ft_uitoa((uintmax_t)va_arg(ap, unsigned long));
}

void	ft_u_ll(va_list ap, char **str)
{
	*str = ft_uitoa((uintmax_t)va_arg(ap, unsigned long long));
}

void	ft_u_h(va_list ap, char **str)
{
	*str = ft_uitoa((uintmax_t)(unsigned short)va_arg(ap, unsigned int));
}

void	ft_u_hh(va_list ap, char **str)
{
	*str = ft_uitoa((uintmax_t)(unsigned char)va_arg(ap, unsigned int));
}

void	ft_u_j(va_list ap, char **str)
{
	*str = ft_uitoa(va_arg(ap, uintmax_t));
}
