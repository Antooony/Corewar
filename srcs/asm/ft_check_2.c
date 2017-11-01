/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:37:00 by adenis            #+#    #+#             */
/*   Updated: 2017/11/01 14:04:58 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_check_commands(t_token **tok, t_list *sep)
{
	int	i;

	i = (*tok)->lan;
	if (!(*tok)->name)
		return (0);
	*tok = (*tok)->next;
	if (!(*tok)->comment || i != (*tok)->lan)
		return (0);
	*tok = (*tok)->next;
	i = (*tok)->lan;
	if (!(*tok)->ncom)
		return (0);
	*tok = (*tok)->next;
	if (!(*tok)->comment || i != (*tok)->lan)
		return (0);
	*tok = (*tok)->next;
	return (1);
}

int			ft_check(t_token *tok, t_list *sep)
{
	if (!ft_check_commands(&tok, sep))
	{
		ft_putstr("humm");
		return (0);
	}
	if (!ft_check_every(tok, sep))
		return (0);
	return (1);
}
