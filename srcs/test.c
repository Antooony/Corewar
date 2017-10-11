/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:29:39 by adenis            #+#    #+#             */
/*   Updated: 2017/10/11 15:15:00 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		main(int ac, char **av)
{
	char	buffer[2];

	buffer[1] = '\0';
	if (ac != 2)
		return (0);
	int		fd;
	int		i = 0;
	int		count = 0;
	fd = open(av[1], O_RDONLY);
	while (read(fd, buffer, 1))
	{
		// if (count < 2180)
		// {
		// 	count++;
		// 	continue;
		// }
		if (i == 16 && (ft_printf("\n")))
			i = 0;
		ft_printf("%02hhx ", buffer[0]);
		i++;
	}
}