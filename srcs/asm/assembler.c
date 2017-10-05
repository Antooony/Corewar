/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/10/05 16:44:16 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.c"

void	init_ft_tab(void)
{
	g_ft_tab[0] = &ft_lab;
	g_ft_tab[1] = &ft_reg;
	g_ft_tab[2] = &ft_dir;
	g_ft_tab[3] = &ft_comment;
	g_ft_tab[4] = &ft_indir;
	g_ft_tab[5] = &ft_dirlab;
	g_ft_tab[6] = &ft_indirlab;
	g_ft_tab[7] = &ft_name;
	g_ft_tab[8] = &ft_ncom;
	g_ft_tab[9] = &ft_inst;
	OUT = NULL;
};

t_output	*get_dirlab(char *s)
{
	t_output	*pop;
	char		*tmp;

	pop = OUT;
	tmp = NULL;
	while (pop)
	{
		tmp ? free(tmp) : NULL;
		tmp = ft_strsub(pop->name, 0, ft_strlen(pop->name) - 1);
		if (pop->type == 0 && ft_strstr(s, tmp))
		{
			tmp ? free(tmp) : NULL;
			return (pop);
		}
		pop = pop->next;
	}
	return (NULL);
}

int		calc_dirlab(char a, char b)
{
	char 	res;

	res = b - a;
	return (res);
}

void	fill_dirlab(void)
{
	t_output	*tmp;

	tmp = OUT;
	while (tmp)
	{
		if (tmp->type == 5 && get_dirlab(tmp->name))
			tmp->val = calc_dirlab(tmp->link->pos, get_dirlab(tmp->name)->pos);
		tmp = tmp->next;
	}
}

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
	fill_dirlab();
	// print_output();
	print_val();
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
