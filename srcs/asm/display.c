/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:35:23 by adenis            #+#    #+#             */
/*   Updated: 2017/10/10 14:53:42 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	print_output(void)
{
	t_output	*pop;

	pop = OUT;
	while (pop)
	{
		ft_printf("%-6s | type: %d | size: %d | %d -- val: %d\n",
			pop->name, pop->type, pop->size, pop->pos, pop->val);
		pop = pop->next;
	}
}

void	printop(int val, int size)
{
	if (size >= 4)
		ft_putchar_fd((val >> 24), FD);
	if (size >= 3)
		ft_putchar_fd((val >> 16), FD);
	if (size >= 2)
		ft_putchar_fd((val >> 8), FD);
	if (size >= 1)
		ft_putchar_fd(val, FD);
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
