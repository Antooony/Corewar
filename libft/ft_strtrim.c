/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:23:57 by adenis            #+#    #+#             */
/*   Updated: 2017/01/04 16:45:00 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	if (c == 32 || c == 9 || c == 10)
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	int		begin;
	int		end;
	int		size;

	if (s == NULL)
		return (NULL);
	begin = 0;
	end = ft_strlen(s) - 1;
	while (ft_is_space(s[begin]) && begin <= end)
		begin++;
	while (ft_is_space(s[end]) && end >= begin)
		end--;
	if (begin == end)
		return (NULL);
	size = end - begin;
	str = ft_strsub(s, begin, size + 1);
	return (str);
}
