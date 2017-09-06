/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:10:14 by adenis            #+#    #+#             */
/*   Updated: 2017/09/06 17:18:24 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	print_optab(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < 16)
	{
		ft_printf("%-2d-", g_op_tab[i].op_code);
		ft_printf(" %-5s", g_op_tab[i].label);
		ft_printf(" - nb params = %d [", g_op_tab[i].num_params);
		j = 0;
		while (j < g_op_tab[i].num_params)
		{
			ft_printf("%d", g_op_tab[i].params[j]);
			j++;
			if (j < g_op_tab[i].num_params)
				ft_printf(" - ");
		}
		ft_printf("]\n");
		i++;
	}
}

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
	return (0);
}

int		ft_usage(void)
{
	ft_putstr("usage: asm input_file\n");
	return (0);
}

t_list	*get_input(int fd)
{
	t_list	*lst;
	t_list	*tmp;

	lst = ft_lstnew(NULL, 0);
	tmp = ft_lstnew(NULL, 0);
	while (get_next_line(fd, lst->content ? (char **)&tmp->content :
		(char **)&lst->content) > 0)
	{
		if (tmp->content)
		{
			ft_lstadd_end(lst, tmp);
			tmp = tmp->next;
			tmp = ft_lstnew(NULL, 0);
		}
	}
	if (tmp)
		free(tmp);
	return (lst);
}
