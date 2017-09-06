/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:09:30 by adenis            #+#    #+#             */
/*   Updated: 2017/09/06 17:33:47 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	parsing(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		ft_strchr(lst->content, ':') ? get_labels(lst->content) : NULL;
		get_op(lst->content);
		lst = lst->next;
	}
	lst = tmp;
	get_header(lst);
}

int		ft_op_delim(char *s, int i, int len)
{
	char	*delim;

	delim = "%:, \t";
	if ((!s[i + len] || ft_strchr(&delim[2], s[i + len]))
		&& (!i || ft_strchr(delim, s[i - 1])))
		return (1);
	return (0);
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
			&& ft_op_delim(s, tmp - s, ft_strlen(g_op_tab[i].label)))
		{
			OP->name = ft_strdup(g_op_tab[i].label);
			fill
			OP->args = (char **)malloc(sizeof(char*) * g_op_tab[i].num_params + 1);
			OP->args[g_op_tab[i].num_params] = NULL;
		}
		s = tmp + ft_strlen(g_op_tab[i].label);
	}
}
