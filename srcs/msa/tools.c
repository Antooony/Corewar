/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:59:45 by adenis            #+#    #+#             */
/*   Updated: 2017/11/09 14:42:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"

void	ft_octadd_end(t_oct *alst, t_oct *new)
{
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}

int		ft_error(char *s)
{
	ft_putendl(s);
	exit(0);
	return (0);
}

int		ft_usage(void)
{
	ft_putstr("usage: asm input_file\n");
	exit(0);
	return (0);
}

void	display_lst(t_oct *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (lst)
	{
		if (i == 8)
		{
			ft_putchar('\n');
			i = 0;
		}
		ft_printf("%02hhx", lst->content);
		lst = lst->next;
		j++;
		ft_printf("%02hhx ", lst->content);
		lst = lst->next;
		j++;
		i++;
	}
	ft_printf("\nCOUNT %d\n", j);
}

t_oct	*get_input(int fd)
{
	char	buffer[2];
	t_oct	*lst;
	t_oct	*tmp;

	lst = NULL;
	tmp = (t_oct *)ft_lstnew(NULL, 0);
	buffer[1] = '\0';
	while (read(fd, buffer, 1))
	{
		if (!lst)
		{
			lst = (t_oct *)ft_lstnew(NULL, 0);
			lst->content = buffer[0];
		}
		else
		{
			tmp->content = buffer[0];
			ft_octadd_end(lst, tmp);
			tmp = tmp->next;
			tmp = (t_oct *)ft_lstnew(NULL, 0);
		}
	}
	return (lst);
}