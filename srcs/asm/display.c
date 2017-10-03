/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:35:23 by adenis            #+#    #+#             */
/*   Updated: 2017/10/03 19:38:28 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	print_output(void)
{
	t_output	*pop;

	pop = OUT;
	while (pop)
	{
		ft_printf("%-6s | size: %d | %d -- val: %d\n", pop->name, pop->size, pop->pos, pop->val);
		pop = pop->next;
	}
}

void	printop(int val, int size)
{
	if (size >= 4)
		ft_printf("%0#4x\n", (char)(val >> 24));
	if (size >= 3)
		ft_printf("%0#4x\n", (char)(val >> 16));
	if (size >= 2)
		ft_printf("%0#4x\n", (char)(val >> 8));
	if (size >= 1)
		ft_printf("%0#4x\n", (char)val);
}

void	print_val(void)
{
	t_output	*pop;

	pop = OUT;
	while (pop)
	{
		printop(pop->val, pop->size);
		pop = pop->next;
	}
}
