/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:20:09 by adenis            #+#    #+#             */
/*   Updated: 2017/10/20 17:23:53 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"

void		display_out(void)
{
	t_list	*tmp;
	int		val;

	val = 0;
	tmp = OUT;
	while (tmp)
	{
		ft_printf("%s", tmp->content);
		tmp = tmp->next;
	}
}

void		out_val(void)
{
	t_list	*tmp;
	int		val;

	val = 0;
	tmp = OUT;
	while (tmp)
	{
		if (tmp->content_size)
			val = tmp->content_size;
		else
			tmp->content_size = val;
		tmp = tmp->next;
	}
}

void		write_output(char *line, int val, char *suf)
{
	t_list	*tmp;

	if (!OUT->content)
	{
		OUT->content = ft_strdup(line);
		OUT->content_size = val;
	}
	else
	{
		tmp = ft_lstnew(NULL, 0);
		tmp->content_size = val;
		if (suf)
			tmp->content = ft_strjoin(line, suf);
		else
			tmp->content = ft_strdup(line);
		ft_lstadd_end(OUT, tmp);
	}
}