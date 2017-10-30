/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 19:22:01 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/30 18:02:25 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

t_list		*ft_create_elem(char *data)
{
	t_list	*elem;

	elem = NULL;
	if (!(elem = malloc(sizeof(t_list))))
		exit(0);
	elem->content = ft_strdup(data);
	elem->next = NULL;
	return (elem);
}
