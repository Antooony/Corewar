/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <nagaloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:43:00 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/16 19:12:07 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int only_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_header(t_token **tok, t_list **head, int *i)
{
	if (ft_countchar((*head)->content, '"') >= 2)
		ft_medium(tok, (*head)->content, i);
	if (ft_countchar((*head)->content, '"') == 1)
	{
		ft_hard(tok, head, i);
		if (*head)
			ft_naco2(tok, (*head)->content, i);
	}
}

void	split_head(t_token **tok, t_list **head, int *i)
{
	ft_header(tok, head, i);
}
