/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:09:30 by adenis            #+#    #+#             */
/*   Updated: 2017/09/13 13:42:04 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	parsing(t_list *lst)
{
	t_list	*tmp;

	get_header(lst);
	tmp = lst;
	while (lst)
	{
		ft_strchr(lst->content, LABEL_CHAR) ? get_labels(lst->content) : NULL;
		get_op(lst->content);
		lst = lst->next;
	}
	lst = tmp;
}

int		ft_op_blank(char *s, int i, int len)
{
	if ((!s[i + len] || ft_strchr(BLANK, s[i + len]))
		&& (!i || ft_strchr(BLANK, s[i - 1])))
		return (1);
	return (0);
}

char	*ft_jump_blank(char *s)
{
	int		i;

	if (!s)
		return (s);
	i = 0;
	while (ft_strchr(BLANK, s[i]))
		i++;
	return (&s[i]);
}

void	fill_args(char *s)
{
	int		i;

	i = 0;
	s = ft_strstr(s, OP->name) + ft_strlen(OP->name);
	s = ft_jump_blank(s);
	while (i < OP->nargs && s)
	{
		if (ft_strchr(s, SEPARATOR_CHAR))
			OP->args[i] = ft_strsub(s, 0,
				ft_strchr(s, SEPARATOR_CHAR) - s);
		else
		{
			OP->args[i] = ft_strdup(s);
			s = NULL;
		}
		if (s)
			s = ft_strchr(s, SEPARATOR_CHAR) + 1;
		s = ft_jump_blank(s);
		clean_spaces(i);
		i++;
	}
}

void	fill_op(int i, char *s)
{
	char	*tmp;

	if (!LABEL)
		return ;
	if (!OP)
		init_ops();
	while (s && ft_strstr(s, g_op_tab[i].label))
	{
		if (OP->name && (OP->next = ft_newop()))
			OP = OP->next;
		if ((tmp = ft_strstr(s, g_op_tab[i].label))
			&& ft_op_blank(s, tmp - s, ft_strlen(g_op_tab[i].label)))
		{
			OP->name = ft_strdup(g_op_tab[i].label);
			OP->nargs = g_op_tab[i].num_params;
			OP->op_code = g_op_tab[i].op_code;
			OP->label_size = g_op_tab[i].label_size;
			OP->coding_param = g_op_tab[i].coding_param;
			OP->args = (char **)malloc(sizeof(char*)
			* g_op_tab[i].num_params + 1);
			OP->args[g_op_tab[i].num_params] = NULL;
			fill_args(tmp);
		}
		s = tmp + ft_strlen(g_op_tab[i].label);
	}
}
