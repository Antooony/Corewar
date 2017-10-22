/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 11:29:56 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 19:10:54 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "op.c"

void	display_lst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
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
	short 	res;

	res =  b - a;
	return (res);
}

void	fill_dirlab(void)
{
	t_output	*tmp;

	tmp = OUT;
	while (tmp)
	{
		if ((tmp->type == 3 || tmp->type == 5 ) && get_dirlab(tmp->name))
		{
			ft_printf("DIRLAB : %s\n", tmp->name);
			tmp->val = (short)calc_dirlab(tmp->link->pos, get_dirlab(tmp->name)->pos);
			ft_printf("%d\n", tmp->val);
		}
		tmp = tmp->next;
	}
}

static void		ft_split(t_list **temp, t_token *tok)
{
	t_list	*ops;
	int		b;

	b = 1;
	ops = *temp;
	while (ops)
	{
		split_tok(&tok ,ops->content, b);
		ops = ops->next;
		b++;
	}
	ft_pars(tok);
	ft_check(tok, *temp);
	create_output(tok);
	fill_dirlab();
	print_header();
	print_val();
}

static int	ft_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
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


int main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_list	*ops;
	t_token	*tok;
	int i;

	g_name = 0;
	i = 0;
	(void)av;
	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		return (0);
	init_ft_tab();
	FD = 1;
	handle_file(av[1]);
	while (get_next_line(fd, &line))
	{
		ft_push_back(&ops, line);
		ft_strdel(&line);
	}
	ft_split(&ops, tok);
	return (0);
}
