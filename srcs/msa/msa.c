/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:56:31 by adenis            #+#    #+#             */
/*   Updated: 2017/11/10 17:05:00 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"

int			isop(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s || ft_strlen(s) <= 1)
		return (0);
	(tmp = ft_strsub(s, 0, ft_strlen(s) - 1)) ? 0 : ft_error("error");
	while (i < 16)
	{
		if (!ft_strcmp(tmp, g_op_tab[i].label))
		{
			tmp ? ft_strdel(&tmp) : 0;
			return (1);
		}
		i++;
	}
	tmp ? ft_strdel(&tmp) : 0;
	return (0);
}

void		ft_msa(int fd)
{
	t_oct	*lst;

	lst = get_input(fd);
	LST = lst;
	LINE = NULL;
	OUT = NULL;
	LAB = 1;
	lst = input_checks();
	get_header(&lst);
	lst_val(lst);
	get_values(lst);
	out_val();
	handle_label();
	handle_last();
	display_out();
	clean();
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error("can't open the file"));
	ft_msa(fd);
	if (close(fd) == -1)
		return (ft_error("close fd failed"));
}
