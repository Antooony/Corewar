/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:21:30 by adenis            #+#    #+#             */
/*   Updated: 2017/03/06 11:21:40 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(wchar_t *s)
{
	while (*s)
	{
		ft_putwchar(*s);
		s++;
	}
}

void	ft_putwstr_fd(wchar_t *s, int fd)
{
	while (*s)
	{
		ft_putwchar_fd(*s, fd);
		s++;
	}
}
