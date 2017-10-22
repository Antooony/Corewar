/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decoupe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:36:20 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/22 16:46:33 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"


int		ft_decoupe(char const *s)
{
	int i;
	int comb;

	comb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i] == '\0')
			return (comb);
		comb++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			i++;
	}
	return (comb);
}
