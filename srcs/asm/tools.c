/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:56:25 by adenis            #+#    #+#             */
/*   Updated: 2017/11/11 20:00:31 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

unsigned int	endian_int(unsigned int n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) | ((n & 0xff00) << 8) |
					((n & 0xff) << 24));
}

int		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
	return (0);
}

int		ft_usage(void)
{
	ft_putstr("usage: asm input_file\n");
	return (0);
}

void	init_ft_tab(void)
{
	g_ft_tab[0] = &out_lab;
	g_ft_tab[1] = &out_reg;
	g_ft_tab[2] = &out_comment;
	g_ft_tab[3] = &out_dirlab;
	g_ft_tab[4] = &out_dir;
	g_ft_tab[5] = &out_indirlab;
	g_ft_tab[6] = &out_indir;
	g_ft_tab[7] = &out_name;
	g_ft_tab[8] = &out_ncom;
	g_ft_tab[9] = &out_inst;
	OUT = NULL;
}

int		handle_file(char *s)
{
	char	*s2;
	char	*name;
	int		i;

	if (!s)
		exit(0);
	if (!ft_strrchr(s, '.'))
		return (ft_error());
	if (ft_strrchr(s, '.')[1] != 's')
		return (ft_error());
	if (!(s2 = ft_strdup(s)))
		exit(0);
	s2[ft_strlen(s2) - 1] = 0;
	if (!(name = ft_strjoin(s2, "cor")))
		exit(0);
	FD = open(name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_printf("Writing output program to %s\n", name);
	free(s2);
	free(name);
	return (0);
}
