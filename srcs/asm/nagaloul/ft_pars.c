/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:05:07 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 18:19:29 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

int		onlysep(t_token **tok)
{
	int i;

	i = 0;
	while ((*tok)->unknow[i])
	{
		if ((*tok)->unknow[i] == ',' || (*tok)->unknow[i] == ':' || (*tok)->unknow[i] == '%')
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

void	ft_pindir(t_token *tok)
{
	int i;
	int a;

	a = 0;
	i = 0;
	if (onlysep(&tok))
	{
		if (tok->unknow[0] == ',')
			i++;
		a = i;
		if (ft_isdigit(tok->unknow[i]))
		{
			while (ft_isdigit(tok->unknow[i]))
				i++;
			if (tok->unknow[i]  == '\0' || tok->unknow[i] == ',')
			{
				tok->indir = &tok->unknow[a];
				if (ft_strchr(tok->indir, ','))
					*ft_strchr(tok->indir, ',') = '\0';
			}
		}
	}
}

void	ft_name(t_token *tok)
{
	if (!ft_strcmp(tok->unknow, NAME_CMD_STRING))
		tok->name = tok->unknow;
}

void	ft_ncom(t_token *tok)
{
	if (!ft_strcmp(tok->unknow, COMMENT_CMD_STRING))
		tok->ncom = tok->unknow;
}

void	ft_pdir(t_token *tok)
{
	int i;

	i = 0;
	if (onlysep(&tok))
	{
		if (tok->unknow[0] == ',')
			i++;
		if (!tok->dirlab)
			if (tok->unknow[i] == '%')
			{
				tok->dir = &tok->unknow[i];
				if (ft_strchr(tok->dir, ','))
					*ft_strchr(tok->dir, ',') = '\0';
			}
	}
}

void	ft_inst(t_token *tok)
{
	int i;

	i = 0;
	if (!tok->lab)
	{
		if (!onlysep(&tok))
			tok->inst = tok->unknow;
		else
		{
			if (tok->unknow[0] == ',')
				i++;
			tok->inst = &tok->unknow[i];
			if (ft_strchr(tok->inst, ','))
				*ft_strchr(tok->inst, ',') = '\0';
		}
	}
}

void	ft_preg(t_token *tok)
{
	int i;

	i = 0;
	if (tok->unknow[0] == ',')
		i++;
	if (!tok->lab)
	{
		if (tok->unknow[i] == 'r')
		{
			i++;
			while (ft_isdigit(tok->unknow[i]))
				i++;
			if (i > 1 && (tok->unknow[i] == '\0' || tok->unknow[i] == ','))
				tok->reg = tok->unknow;
		}
	}
}

void	ft_pars(t_token *tok)
{
	while (tok)
	{
		ft_comment(tok);
		ft_lab(tok);
		ft_pdirlab(tok);
		ft_pindirlab(tok);
		ft_pdir(tok);
		ft_name(tok);
		ft_ncom(tok);
		ft_pindir(tok);
		ft_preg(tok);
		ft_inst(tok);
		tok = tok->next;
	}
}
