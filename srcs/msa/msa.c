/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:56:31 by adenis            #+#    #+#             */
/*   Updated: 2017/10/20 17:22:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"
#include "op.c"

int		isop(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s || ft_strlen(s) <= 1)
		return (0);
	tmp = ft_strsub(s, 0, ft_strlen(s) - 1);
	while (i < 16)
	{
		if (!ft_strcmp(tmp, g_op_tab[i].label))
		{
			ft_strdel(&tmp);
			return (1);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

void		get_values(t_oct *lst)
{
	t_oct	*tmp;

	while (lst)
	{
		if (tmp == lst)
			break;
		tmp = lst;
		write_output(g_op_tab[lst->content - 1].label, lst->val, " ");
		if (g_op_tab[lst->content - 1].coding_param)
			get_opc(&lst);
		else
			handle_args(&lst);
		print_cor(tmp, lst);
	}
}

t_list		*check_goto(t_list *lst, int val)
{
	t_list	*tmp;

	tmp = OUT;
	while (tmp->next)
	{
		if (tmp->next->content_size == val)
		{
			if (ft_strstr(tmp->next->content, "LABEL"))
				return (tmp);
			if (isop(tmp->next->content))
				return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void		lab_insert(t_list *lst)
{
	t_list	*tmp;
	char	*s1;
	char	*s2;

	s1 = ft_itoa(LAB++);
	s2 = ft_strjoin(s1, ":\n");
	tmp = ft_lstnew(NULL, 0);
	tmp->content = ft_strjoin("LABEL", s2);
	tmp->content_size = lst->next->content_size;
	tmp->next = lst->next;
	lst->next = tmp;
	ft_strdel(&s1);
	ft_strdel(&s2);
}

void		handle_goto(t_list *lst)
{
	int		val;
	char	*s;
	t_list	*tmp;

	val = (char)ft_atoi(lst->content);
	if (val > IDX_MOD || -val > IDX_MOD)
		return ;
	if (val)
		val += lst->content_size;
	if ((tmp = check_goto(lst->content, val)))
	{
		if (!ft_strstr(tmp->next->content, "LABEL"))
			lab_insert(tmp);
		ft_strdel((char **)&lst->content);
		s = ft_strjoin(":", tmp->next->content);
		s[ft_strlen(s) - 1] = ' ';
		s[ft_strlen(s) - 2] = ',';
		lst->content = s;
	}
}

void		handle_label(void)
{
	t_list	*lst;

	lst = OUT;
	while (lst)
	{
		if (ft_strchr(lst->content, DIRECT_CHAR))
			handle_goto(lst->next);
		lst = lst->next;
	}
}

void		ft_msa(int fd)
{
	t_oct	*lst;

	lst = get_input(fd);
	LST = lst;
	LINE = NULL;
	OUT = ft_lstnew(NULL, 0);
	LAB = 1;
	if (!check_magic(&lst))
		ft_error();
	get_header(&lst);
	lst_val(lst);
	get_values(lst);
	out_val();
	handle_label();
	display_out();
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	ft_msa(fd);
	if (close(fd) == -1)
		return (ft_error());

}
