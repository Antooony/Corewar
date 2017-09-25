/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:13:53 by adenis            #+#    #+#             */
/*   Updated: 2017/06/06 18:35:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	getop(char *s)
{
	int		i;
	int		j;
	int		x;
	char	*tmp;

	j = 0;
	x = 0;
	i = 0;
	while (s[j] && (s[j] == ' ' || s[j] == '\t'))
		j++;
	while (s[j + i] && s[j + i] != ' ' && s[j + i] != '\t')
		i++;
	if (!i)
		return ;
	tmp = ft_strsub(s, j, i);
	if ((x = isop(tmp)) != -1)
	{
		ft_printf("OP   : %s -", op_tab[x].name);
		j = 0;
		while (j < op_tab[x].nargs)
		{
			ft_printf("%d ", op_tab[x].args[j]);
			j++;
		}
		ft_putchar('\n');
	}
	tmp ? ft_strdel(&tmp) : NULL;
	if (s[i])
		getop(&s[i + 1]);
}
