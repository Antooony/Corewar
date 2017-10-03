/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:35:23 by adenis            #+#    #+#             */
/*   Updated: 2017/10/03 16:09:12 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	print_token(t_token *split)
{
	while (split)
	{
		ft_printf("%s | %d\n", split->unknow, get_value(split));
		split = split->next;
	}
}

void	print_output(void)
{
	t_output	*pop;

	pop = OUT;
	while (pop)
	{
		ft_printf("%-6s | size: %d | %#04x\n", pop->name, pop->size,
			pop->val);
		pop = pop->next;
	}
}
