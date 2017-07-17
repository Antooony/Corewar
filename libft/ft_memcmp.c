/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:48:38 by adenis            #+#    #+#             */
/*   Updated: 2016/11/14 11:26:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*t_s1;
	unsigned char		*t_s2;
	size_t				i;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && t_s1[i] == t_s2[i])
		i++;
	return ((unsigned char)t_s1[i] - (unsigned char)t_s2[i]);
}
