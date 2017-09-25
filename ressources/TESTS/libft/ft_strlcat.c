/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:29:29 by adenis            #+#    #+#             */
/*   Updated: 2016/11/09 16:02:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int			i;
	size_t		j;
	int			max;

	i = 0;
	j = ft_strlen(dst);
	max = size - 1 - j;
	while ((i < max) && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (size < j)
		return (size + ft_strlen(src));
	else
		return (j + ft_strlen(src));
}
