/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:36:20 by adenis            #+#    #+#             */
/*   Updated: 2016/11/27 16:11:04 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (t_src[i] == (unsigned char)c)
		{
			t_dst[i] = t_src[i];
			return ((unsigned char *)&t_dst[i + 1]);
		}
		t_dst[i] = t_src[i];
		i++;
	}
	return (NULL);
}
