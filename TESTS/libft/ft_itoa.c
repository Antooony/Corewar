/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:04:50 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:38:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		ft_size(intmax_t *n, intmax_t *min)
{
	intmax_t		i;
	intmax_t		len;

	len = 1;
	i = 1;
	if (*n < 0)
	{
		*min = *min + 1;
		*n *= -1;
		len++;
	}
	while ((*n / i) >= 10)
	{
		i *= 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(intmax_t n)
{
	intmax_t		len;
	intmax_t		min;
	char			*str;

	min = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_size(&n, &min);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (min == 1)
		str[0] = '-';
	while (len-- > min)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
