/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:51:48 by adenis            #+#    #+#             */
/*   Updated: 2016/12/07 19:45:35 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;

	ret = f(lst);
	if (ret == NULL)
		return (NULL);
	new = ret;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
	}
	return (ret);
}
