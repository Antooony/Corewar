/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 21:50:05 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 17:30:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

int			ft_checkop(t_op g_op_tab, t_token *tok, t_token *temp, t_list *sep)
{
	int	(*tab[16])(t_token*, int, t_token*, t_list*);
	int i;
	int op;

	i = tok->lan;
	tab[0] = ft_live;
	tab[1] = ft_ld;
	tab[2] = ft_st;
	tab[3] = ft_sub;
	tab[4] = ft_sub;
	tab[5] = ft_or;
	tab[6] = ft_or;
	tab[7] = ft_or;
	tab[8] = ft_live;
	tab[9] = ft_ldi;
	tab[10] = ft_sti;
	tab[11] = ft_live;
	tab[12] = ft_ld;
	tab[13] = ft_ldi;
	tab[14] = ft_live;
	tab[15] = ft_aff;
	if (!tab[g_op_tab.op_code - 1](tok, i, temp, sep))
		return (0);
	return (1);
}

int			ft_real(t_token *tok, t_token *temp, t_list *sep)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!strcmp(g_op_tab[i].label, tok->inst))
		{
			if (!ft_checkop(g_op_tab[i], tok, temp, sep))
				return (0);
			return (1);
		}
		i++;
	}
	ft_puterror(tok, 0, tok->lan, tok);
	return (0);
}

int			ft_instruc(t_token **tok, t_token *temp, t_list *sep)
{
	int	i;

	i = (*tok)->lan;
	if (!ft_real(*tok, temp, sep))
	{
		while (*tok && (*tok)->lan == i)
			*tok = (*tok)->next;
		return (0);
	}
	while (*tok && (*tok)->lan == i)
		*tok = (*tok)->next;
	return (1);
}

int			ft_label(t_token **tok)
{
	*tok = (*tok)->next;
	return (1);
}


int			ft_check_every(t_token *tok, t_list *sep)
{
	t_token *temp;
	int		i;

	i = 0;
	temp = tok;
	while (tok)
	{
		if (tok && tok->lab)
			ft_label(&tok);
		if (tok)
			if (!ft_instruc(&tok, temp, sep))
				i++;
	}
	return (i ? 0 : 1);
}

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
