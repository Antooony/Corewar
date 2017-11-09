/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:15:13 by adenis            #+#    #+#             */
/*   Updated: 2017/11/09 14:34:17 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"

int		lstlen(t_oct *lst)
{
	int		i;
	t_oct	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		check_len(t_oct *lst)
{
	int		len;

	len = PROG_NAME_LENGTH + COMMENT_LENGTH + 12;
	ft_printf("lst %d, needed %d\n", lstlen(lst), len);
	if (lstlen(lst) <= len)
	{
		ft_error("bad header length");
		return (0);
	}
	return (1);
}

t_oct	*input_checks(void)
{
	t_oct	*lst;

	lst = LST;
	if (!check_magic(&lst))
		ft_error("invalid magic number");
	check_len(lst);
	return (lst);
}