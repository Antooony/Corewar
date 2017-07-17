/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:09:05 by adenis            #+#    #+#             */
/*   Updated: 2016/11/14 11:05:21 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		bigi;
	size_t		i;

	bigi = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[bigi] && bigi < len)
	{
		if (big[bigi] == little[0])
		{
			while (big[bigi + i] == little[i] && (bigi + i) < len)
			{
				if (i == ft_strlen(little) - 1)
					return ((char *)&big[bigi]);
				i++;
			}
		}
		bigi++;
	}
	return (NULL);
}
