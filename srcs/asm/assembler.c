/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/09/28 16:52:17 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.c"

void	ft_asm(int fd)
{
	t_list	*lst;

	lst = get_input(fd);
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	ft_asm(fd);
	if (close(fd) == -1)
		return (ft_error());
}
