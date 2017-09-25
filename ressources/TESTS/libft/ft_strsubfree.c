/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:29:59 by adenis            #+#    #+#             */
/*   Updated: 2017/06/02 12:36:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		begin;

	i = 0;
	if (s == NULL)
		return (NULL);
	begin = (size_t)start;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[begin + i];
		i++;
	}
	str[i] = '\0';
	ft_strdel(&s);
	return (str);
}
