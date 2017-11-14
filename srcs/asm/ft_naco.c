/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_naco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:43:39 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/14 15:52:45 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_sip(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '"'
			&& str[i] != ';' && str[i] != '#')
		i++;
	return (i);
}

void	ft_naco(t_token **tok, char *str, int *count, int *b)
{
	int i;
	char temp;

	i = ft_sip(str);
	temp = str[i];
	str[i] = '\0';
	ft_push_token(tok, str, *count, *b);
	str[i] = temp;
	if (temp == '"')
		i--;
	*count = *count + i;
}
