/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/10/11 15:28:29 by adenis           ###   ########.fr       */
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

void	print_magic(unsigned int nb)
{
	ft_putchar_fd((char)(nb >> 24), FD);
	ft_putchar_fd((char)(nb >> 16), FD);
	ft_putchar_fd((char)(nb >> 8), FD);
	ft_putchar_fd((char)nb, FD);
}

void	print_name(t_header *header, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		header->prog_name[i] = s[i];
		i++;
	}
	i = 0;
	while (i < PROG_NAME_LENGTH + 1)
	{
		ft_putchar_fd(header->prog_name[i], FD);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		ft_putchar_fd(0, FD);
		i++;
	}
	print_magic(PROG_SIZE);
}

void	print_comment(t_header *header, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		header->comment[i] = s[i];
		i++;
	}
	i = 0;
	while (i < COMMENT_LENGTH + 1)
	{
		ft_putchar_fd(header->comment[i], FD);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		ft_putchar_fd(0, FD);
		i++;
	}
}

void	print_header(void)
{
	t_output	*tmp;
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	tmp = OUT;
	print_magic(header->magic);
	while (tmp)
	{
		if (tmp->type == 7)
			print_name(header, tmp->name);
		if (tmp->type == 2)
			print_comment(header, tmp->name);
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

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	init_ft_tab();
	FD = 1;
	ft_asm(fd);
	if (close(fd) == -1)
		return (ft_error());
}
