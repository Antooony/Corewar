/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/10/22 13:24:03 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.c"

void	init_ft_tab(void)
{
	g_ft_tab[0] = &ft_lab;
	g_ft_tab[1] = &ft_reg;
	g_ft_tab[2] = &ft_comment;
	g_ft_tab[3] = &ft_dirlab;
	g_ft_tab[4] = &ft_dir;
	g_ft_tab[5] = &ft_indirlab;
	g_ft_tab[6] = &ft_indir;
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

int		calc_dirlab(int a, int b)
{
	int 	res;

	res =  b - a;
	return (res);
}

void	fill_dirlab(void)
{
	t_output	*tmp;

	tmp = OUT;
	while (tmp)
	{
		if ((tmp->type == 3 || tmp->type == 5 )&& get_dirlab(tmp->name))
		{
			tmp->val = calc_dirlab(tmp->link->pos, get_dirlab(tmp->name)->pos);
		}
		tmp = tmp->next;
	}
}

void	ft_asm(int fd)
{
	t_list		*lst;
	t_token		*split;

	split = new_token(NULL);
	lst = get_input(fd);
	tokenize_lst(lst, split);
	specify_tokens(split);
	create_output(split);
	fill_dirlab();
	print_header();
	print_val();
}

int		handle_file(char *s)
{
	char	*s2;
	char	*name;
	int		i;

	if (!ft_strchr(s, '.') || ft_strchr(s, '.') != ft_strrchr(s, '.'))
		return (ft_error());
	if (ft_strchr(s, '.')[1] != 's' || ft_strchr(s, '.') + 1 != s + ft_strlen(s) - 1)
		return (ft_error());
	s2 = ft_strdup(s);
	s2[ft_strlen(s2) - 1] = 0;
	name = ft_strjoin(s2, "cor.me");
	free(s2);
	FD = open(name, O_WRONLY | O_CREAT, S_IRWXU);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	init_ft_tab();
	FD = 1;
	handle_file(argv[1]);
	ft_asm(fd);
	close(FD);
	if (close(fd) == -1)
		return (ft_error());
}
