/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:49:01 by adenis            #+#    #+#             */
/*   Updated: 2017/06/29 11:14:52 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

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

void	del(void *content, size_t size)
{
	if (content)
		free(content);
	content = NULL;
	size = 0;
}

int		count_spaces(char *s)
{
	int		i;
	int		count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (isspace(s[i]))
			count++;
		i++;
	}
	return (count);
}

char	*fill_tmp(char *tmp, char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (!isspace(s[i]))
		{
			tmp[j] = s[i];
			j++;
		}
		i++;
	}
	return (tmp);
}
char	*clean_content(char **s)
{
	int		spaces;
	char	*tmp;

	if (!*s)
		return (NULL);
	spaces = count_spaces(*s);
	if (spaces == (int)ft_strlen(*s))
	{
		ft_strdel(s);
		return (NULL);
	}
	if (!spaces)
		return (*s);
	if (!(tmp = ft_strnew(ft_strlen(*s) - spaces)))
		exit(0);
	tmp = fill_tmp(tmp, *s);
	*s ? ft_strdel(s) : NULL;
	return (tmp);
}

t_list	*del_empty(t_list *lst)
{
	t_list	*tmp;
	t_list	*first;

	first = lst;
	tmp = NULL;
	while (lst)
	{
		if (lst->next)
		{
			tmp = lst->next;
			lst->next = tmp->next;
			ft_lstdelone(&tmp, &del);
			tmp = NULL;
		}
		lst = lst->next;
	}
	return (first);
}

t_list	*clean_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		lst->content = clean_content((char **)&lst->content);
		lst = lst->next;
	}
	// tmp = del_empty(tmp);
	return (tmp);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	t_list	*lst;

	i = 0;
	fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	lst = get_input(fd);
	lst = clean_list(lst);
	displst(lst);
}
