/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:45:38 by adenis            #+#    #+#             */
/*   Updated: 2017/02/09 13:52:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			add_end(t_list *alst, t_list *new)
{
	if (alst && new && alst->next)
		add_end(alst->next, new);
	else
		alst->next = new;
}

static int			ft_length(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char			*ft_fill_tab(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_length(s, c));
	if (!str)
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

t_list				*ft_lstsplit(char const *s, char c)
{
	t_list	*lst;
	t_list	*new;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	lst = ft_lstnew(NULL, 0);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			new = ft_lstnew(ft_fill_tab(&s[i], c), ft_length(&s[i], c));
			add_end(lst, new);
		}
		i++;
	}
	return (lst);
}
