/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:02:57 by adenis            #+#    #+#             */
/*   Updated: 2017/09/13 13:33:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	show_error(int max, int spot)
{
	int		i;

	i = 0;
	if (max < spot || max < i || spot < i)
		return ;
	while (i < max)
	{
		if (i == spot)
			ft_printf("\e[31m%c\e[0m", '^');
		else
			ft_printf("\e[31m%c\e[0m", '~');
		i++;
	}
	ft_putchar('\n');
}

void	leave(char *message, int i, char *s)
{
	if (message)
		ft_printf("%s\n", message);
	if (s)
	{
		ft_printf("%s\n", s);
		if (i)
			show_error(ft_strlen(s), i);
	}
	leave_free();
}
