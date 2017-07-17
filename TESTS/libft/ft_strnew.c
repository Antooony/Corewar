/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:20:07 by adenis            #+#    #+#             */
/*   Updated: 2017/06/02 12:38:33 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size + 1)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
