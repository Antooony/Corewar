/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:00:57 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/27 15:15:32 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "assembler.h"

int				ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int				ft_usage(void)
{
	ft_putstr("usage: asm input_file\n");
	return (0);
}

int				main(int argc, char **argv)
{
	int				fd;
	char			*line;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (ft_usage());
	if (fd == -1)
		return (ft_error());
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (line)
			free(line);
	}
	if (close(fd) == -1)
		return (ft_error());
	return (1);
}
