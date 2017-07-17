/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:44 by adenis            #+#    #+#             */
/*   Updated: 2016/11/09 12:56:28 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*t_dst;
	unsigned char		*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	if (t_src == t_dst)
		return (dst);
	if (t_src < t_dst)
	{
		while (len--)
			t_dst[len] = t_src[len];
		return (dst);
	}
	else
	{
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
		return (dst);
	}
}
