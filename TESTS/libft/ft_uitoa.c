/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:34:10 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:38:34 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t		ft_size(uintmax_t *n)
{
	uintmax_t		i;
	uintmax_t		len;

	len = 1;
	i = 1;
	while ((*n / i) >= 10)
	{
		i *= 10;
		len++;
	}
	return (len);
}

char					*ft_uitoa(uintmax_t n)
{
	uintmax_t		len;
	char			*str;

	len = ft_size(&n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
