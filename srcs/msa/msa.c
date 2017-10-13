/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:56:31 by adenis            #+#    #+#             */
/*   Updated: 2017/10/13 20:01:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"
#include "op.c"

t_oct		*jump(t_oct *lst, int n)
{
	while (n)
	{
		lst = lst->next;
		n--;
	}
	return (lst);
}

void		ft_msa(int fd)
{
	t_oct	*lst;

	lst = get_input(fd);
	if (check_magic(&lst))
		get_header(lst);
	else
		ft_error();
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	ft_msa(fd);
	if (close(fd) == -1)
		return (ft_error());

}
