/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:14:19 by adenis            #+#    #+#             */
/*   Updated: 2017/01/02 12:54:25 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_end(t_list *alst, t_list *new)
{
	t_list	*tmp;

	if (alst->start)
		tmp = alst->start;
	else
		tmp = alst;
	alst->start = alst;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
	new->start = tmp;
}
