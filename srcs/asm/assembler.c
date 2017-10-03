/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/10/03 16:04:46 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.c"

void	init_ft_tab(void)
{
	g_ft_tab[0] = &ft_lab;
	g_ft_tab[1] = &ft_comment;
	g_ft_tab[2] = &ft_dirlab;
	g_ft_tab[3] = &ft_indirlab;
	g_ft_tab[4] = &ft_dir;
	g_ft_tab[5] = &ft_name;
	g_ft_tab[6] = &ft_ncom;
	g_ft_tab[7] = &ft_indir;
	g_ft_tab[8] = &ft_inst;
	g_ft_tab[9] = &ft_reg;
	OUT = NULL;
};

void	ft_asm(int fd)
{
	t_list		*lst;
	t_token		*split;
	int			val;

	val =0;
	split = new_token(NULL);
	lst = get_input(fd);
	tokenize_lst(lst, split);
	specify_tokens(split);
	create_output(split);
	print_output();
	while (OUT)
	{
		val += OUT->size;
		OUT = OUT->next;
	}
	ft_printf("TOTAL = %d\n", val);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	init_ft_tab();
	ft_asm(fd);
	if (close(fd) == -1)
		return (ft_error());
}
