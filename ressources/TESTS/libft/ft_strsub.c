/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:37:33 by adenis            #+#    #+#             */
/*   Updated: 2017/06/02 12:35:55 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		strt;

	i = 0;
	if (s == NULL)
		return (NULL);
	strt = (size_t)start;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[strt + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
