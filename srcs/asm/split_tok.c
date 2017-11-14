/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:44:10 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/14 19:59:14 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

int		ft_sep(char *str)
{
	int	i;

	i = 0;
	while ((str[i]) && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] == ';' || str[i] == '#')
			break ;
		if (i > 0 && str[i] == ':' && str[i - 1] != '%' && str[i - 1] != ',')
		{
			i++;
			break ;
		}
		if (i > 0 && str[i] == ',')
		{
			i++;
			break ;
		}
		if (str[i] == '"')
			break ;
		i++;
	}
	return (i);
}

void	ft_guill(t_token **tok, char *str, int *count, int b)
{
	int i;

	i = 0;
	while ((str[i]) && str[i] != '#')
		i++;
	str[i] = '\0';
	ft_push_token(tok, str, *count + 1, b);
	*count = *count + i;
}

void	ft_try(t_token **tok, char *str, int *count, int b)
{
	int		i;
	char	temp;

	temp = 0;
	i = ft_sep(str);
	temp = str[i];
	str[i] = '\0';
	if (ft_strcmp(str, ","))
		ft_push_token(tok, str, *count + 1, b);
	str[i] = temp;
	if (temp == '"')
		ft_guill(tok, &str[i], &i, b);
	if (str[i - 1] == ':' || str[i - 1] == ',')
		i--;
	*count = *count + i;
}

int		only(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == ',')
		return (0);
	return (1);
}

void	split_tok(t_token **tok, char *str, int b)
{
	int		 i;
	char	tab[2];


	i = 0;
	tab[0] = SEPARATOR_CHAR;
	tab[1] = 0;
	if (!only(str))
		ft_push_token(tok, tab, 1, b);
	else
		while (str[i])
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] == '"')
				ft_guill(tok, &str[i], &i, b);
			if (str[i] == '\0' || str[i] == '#' || str[i] == ';')
				break ;
			ft_try(tok, &str[i], &i, b);
			if (str[i] == ';' || str[i] == '#' || str[i] == '"')
				break ;
			if (str[i] != '\0')
				i++;
		}
}
