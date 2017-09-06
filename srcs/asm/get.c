/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:38:12 by adenis            #+#    #+#             */
/*   Updated: 2017/09/06 18:01:03 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	get_name(char *s)
{
	char	*out;

	if (!ft_strchr(s, '"') || !ft_strrchr(s, '"')
		|| ft_strchr(s, '"') == ft_strrchr(s, '"'))
		exit(write(1, "fail name", 9));
	out = ft_strsub(s, ft_strchr(s, '"') - s + 1,
		ft_strrchr(s, '"') - ft_strchr(s, '"') - 1);
	g_infos.name = out;
}

void	get_comment(char *s)
{
	char	*out;

	if (!ft_strchr(s, '"') || !ft_strrchr(s, '"')
		|| ft_strchr(s, '"') == ft_strrchr(s, '"'))
		exit(write(1, "fail comment", 12));
	out = ft_strsub(s, ft_strchr(s, '"') - s + 1,
		ft_strrchr(s, '"') - ft_strchr(s, '"') - 1);
	g_infos.comment = out;
}

void	get_header(t_list *lst)
{
	while (lst)
	{
		if (ft_strstr(lst->content, ".name"))
			get_name(lst->content);
		if (ft_strstr(lst->content, ".comment"))
			get_comment(lst->content);
		lst = lst->next;
	}
}

void	get_op(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (g_op_tab[i].label)
	{
		fill_op(i, s);
		i++;
	}
}

void	get_labels(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != ':')
	{
		if (!ft_isalnum(s[i]))
			return ;
		i++;
	}
	if (LABEL && (LABEL->next = ft_newlabel()))
		LABEL = LABEL->next;
	if (!LABEL)
		init_label();
	LABEL->name = ft_strsub(s, 0, i);
}
