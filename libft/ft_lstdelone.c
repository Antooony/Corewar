/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:18:14 by adenis            #+#    #+#             */
/*   Updated: 2016/11/14 12:11:56 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (alst)
	{
		tmp = *alst;
		del(tmp->content, tmp->content_size);
		free(*alst);
		*alst = NULL;
	}
}
