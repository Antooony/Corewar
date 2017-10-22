/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterrorsep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:09:31 by nagaloul          #+#    #+#             */
/*   Updated: 2017/10/19 16:54:51 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_puterrorsep(int i)
{
	if (i < 10)
		printf("Syntax error at token [TOKEN][00%i] SEPARATOR \",\"\n", i);
	else if (i < 100)
		printf("Syntax error at token [TOKEN][0%i] SEPARATOR \",\"\n", i);
	else 
		printf("Syntax error at token [TOKEN][%i] SEPARATOR \",\"\n", i);
}
