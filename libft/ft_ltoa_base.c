/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:57:25 by adenis            #+#    #+#             */
/*   Updated: 2017/01/26 17:56:18 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_powa(long long nb, int power)
{
	long long	carre;
	int			i;

	i = 2;
	carre = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
	{
		while (i <= power)
		{
			carre = carre * nb;
			i++;
		}
		return (carre);
	}
}

char				*ft_ltoa_base(long long n, char *s, int base)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	if (n < 0 || !s || !base)
		return (NULL);
	if (n == 0)
		return ("0");
	while (ft_powa(base, i) <= n)
		i++;
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
