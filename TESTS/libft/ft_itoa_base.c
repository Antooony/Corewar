/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:01:08 by adenis            #+#    #+#             */
/*   Updated: 2017/01/26 23:16:45 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_poweru(uintmax_t n, uintmax_t base)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

char			*ft_itoa_base(uintmax_t n, char *s, int base)
{
	uintmax_t		len;
	char			*str;
	uintmax_t		i;

	i = 0;
	if (!s || !base)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_poweru(n, base);
	len = i;
	str = ft_strnew(len);
	while (len)
	{
		str[len - 1] = s[(n % base)];
		n = n / base;
		len--;
	}
	return (str);
}
