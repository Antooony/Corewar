/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:36:21 by adenis            #+#    #+#             */
/*   Updated: 2016/11/08 16:47:26 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*t_s;

	t_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (t_s[i] == (unsigned char)c)
			return (&t_s[i]);
		i++;
	}
	return (NULL);
}
