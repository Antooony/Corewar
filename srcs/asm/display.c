/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:35:23 by adenis            #+#    #+#             */
/*   Updated: 2017/10/02 18:30:05 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	print_it(t_token *token)
{
	int		*out;
	int		i;

	i = get_value(token);
	if (i > 9)
		return ;
	out = (int *)g_ft_tab[i](token->unknow);
	if (!out)
	{
		ft_putchar('\n');
		return ;
	}
	ft_printf("size = %d | val = %d\n", out[0], out[1]);
}

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
		ft_printf("%s -- %d\n", pop->name, pop->size);
		pop = pop->next;
	}
}
