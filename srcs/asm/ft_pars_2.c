/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:37:59 by adenis            #+#    #+#             */
/*   Updated: 2017/10/30 14:41:02 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		onlysep(t_token **tok)
{
	int i;

	i = 0;
	while ((*tok)->unknow[i])
	{
		if ((*tok)->unknow[i] == ',' || (*tok)->unknow[i] == ':'
			|| (*tok)->unknow[i] == '%')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_comment(t_token *tok)
{
	if (ft_countchar(tok->unknow, '"') == 2)
		tok->comment = tok->unknow;
}

void	ft_lab(t_token *tok)
{
	int i;

	i = 0;
	if (onlysep(&tok))
	{
		while (tok->unknow[i])
			i++;
		i--;
		if (tok->unknow[i] == ':')
		{
			tok->unknow[i] = '\0';
			tok->lab = tok->unknow;
		}
	}
}

void	ft_pindirlab(t_token *tok)
{
	int	i;

	i = 0;
	if (onlysep(&tok))
	{
		if (tok->unknow[0] == ',')
			i++;
		if (tok->unknow[i] == ':')
		{
			tok->indirlab = &tok->unknow[i + 1];
			if (ft_strchr(tok->indirlab, ','))
				*ft_strchr(tok->indirlab, ',') = '\0';
		}
	}
}

void	ft_pdirlab(t_token *tok)
{
	int	i;

	i = 0;
	if (onlysep(&tok))
	{
		if (tok->unknow[0] == ',')
			i++;
		if (tok->unknow[i] == '%' && tok->unknow[i + 1] == ':')
		{
			tok->dirlab = &tok->unknow[i + 2];
			if (ft_strchr(tok->dirlab, ','))
				*ft_strchr(tok->dirlab, ',') = '\0';
		}
	}
}
