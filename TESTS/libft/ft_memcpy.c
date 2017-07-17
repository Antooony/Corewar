/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:15:04 by adenis            #+#    #+#             */
/*   Updated: 2016/11/09 12:48:56 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*t_dst;
	char		*t_src;

	t_dst = (char *)dst;
	t_src = (char *)src;
	i = 0;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
