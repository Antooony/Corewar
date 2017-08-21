/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:00:57 by nolivier          #+#    #+#             */
/*   Updated: 2017/08/21 15:42:48 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "assembler.h"

int				ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int             ft_usage(void)
{
	ft_putstr("usage: asm input_file\n");
	return (0);
}

t_list	*get_input(int	fd)
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

int		main(int argc, char **argv)
{
	int             fd;
	t_list			*lst;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	lst = get_input(fd);
	int i =0;
	while (i < 16)
	{
		ft_printf("%s\n",g_op_tab[i].label);
		i++;
	}
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	if (close(fd) == -1)
		return (ft_error());
}
