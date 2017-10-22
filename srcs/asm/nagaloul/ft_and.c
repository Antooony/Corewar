/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:37:47 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/20 21:25:14 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_sti(t_token *tok, int i, t_token *lab, t_list *sep)
{
	if (!ft_virgule(i, sep, 3))
	{
		ft_puterrorsep(i);
		return (0);
	}
	if (!ft_reg(tok, i))
	{
		ft_puterror(tok->next, 1, i, tok);
		return (0);
	}
	if (!ft_reg(tok->next, i) && !ft_dir(tok->next, i, lab) && !ft_indir(tok->next, i, lab))
	{
		ft_puterror(tok->next->next, 2, i, tok);
		return (0);
	}
	if (!ft_reg(tok->next->next, i) && !ft_dir(tok->next->next, i, lab))
	{
		ft_puterror(tok->next->next->next, 2, i, tok);
		return (0);
	}
	if (ft_tomuch(tok->next->next->next, i))
		return (0);
	return (1);
}

int		ft_ldi(t_token *tok, int i, t_token *lab, t_list *sep)
{
	if (!ft_virgule(i, sep, 3))
	{
		ft_puterrorsep(i);
		return (0);
	}
	if (!ft_reg(tok, i) && !ft_dir(tok, i, lab) && !ft_indir(tok, i, lab))
	{
		ft_puterror(tok->next, 1, i, tok);
		return (0);
	}
	if (!ft_reg(tok->next, i) && !ft_dir(tok->next, i, lab))
	{
		ft_puterror(tok->next->next, 2, i, tok);
		return (0);
	}
	if (!ft_reg(tok->next->next, i))
	{
		ft_puterror(tok->next->next->next, 2, i, tok);
		return (0);
	}
	if (ft_tomuch(tok->next->next->next, i))
		return (0);
	return (1);
}

int		ft_or(t_token *tok, int i, t_token *lab, t_list *sep)
{
	if (!ft_virgule(i, sep, 3))
	{
		ft_puterrorsep(i);
		return (0);
	}
	if (!ft_reg(tok, i) && !ft_dir(tok, i, lab) && !ft_indir(tok, i, lab))
	{
		ft_puterror(tok->next, 1, i, tok);
		return (0);
	}
	if (!ft_reg(tok->next, i) && !ft_dir(tok->next, i, lab) && !ft_indir(tok->next, i, lab))
	{
		ft_puterror(tok->next->next, 2, i, tok);
		return (0);
	}
	if (!ft_reg(tok->next->next, i))
	{
		ft_puterror(tok->next->next->next, 2, i, tok);
		return (0);
	}
	if (ft_tomuch(tok->next->next->next, i))
		return (0);
	return (1);
}

int		ft_aff(t_token *tok, int i, t_token *lab, t_list *sep)
{
	if (!ft_virgule(i, sep, 1))
	{
		ft_puterrorsep(i);
		return (0);
	}
	if (!ft_reg(tok, i))
	{
		ft_puterror(tok->next, 1, i, tok);
		return (0);
	}
	if (ft_tomuch(tok->next, i))
		return (0);
	return (1);
}
