/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:57:56 by adenis            #+#    #+#             */
/*   Updated: 2017/10/02 19:02:21 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_token			*new_token(char *s)
{
	t_token		*new;

	new = (t_token *)malloc(sizeof(t_token));
	new->next = NULL;
	new->lan = 0;
	new->col = 0;
	new->lab = NULL;
	new->comment = NULL;
	new->dirlab = NULL;
	new->indirlab = NULL;
	new->dir = NULL;
	new->name = NULL;
	new->ncom = NULL;
	new->indir = NULL;
	new->inst = NULL;
	new->reg = NULL;
	new->unknow = NULL;
	if (s)
		new->unknow = ft_strdup(s);
	return (new);
}

void			token_add(t_token *split, t_token *new)
{
	if (split->next)
	{
		token_add(split->next, new);
		return ;
	}
	split->next = new;
}

static void		tokenize_line(char *s, t_token *split)
{
	if (ft_strstr(s, NAME_CMD_STRING) || ft_strstr(s, COMMENT_CMD_STRING))
		split->unknow ? token_add(split, new_token(s))
			: (split->unknow = ft_strdup(s));
	else
	{
		while (s)
		{
			if (ft_strchr(s, ' '))
			{
				split->unknow ? token_add(split, new_token(ft_strsub(s,
					0, ft_strchr(s, ' ') - s)))
					: (split->unknow = ft_strsub(s, 0, ft_strchr(s, ' ') - s));
				s = ft_strchr(s, ' ') + 1;
			}
			else
			{
				split->unknow ? token_add(split, new_token(ft_strdup(s)))
					: (split->unknow = ft_strdup(s));
				s = NULL;
			}
		}
	}
}

void			tokenize_lst(t_list *lst, t_token *split)
{
	while (lst)
	{
		if (lst->content)
			tokenize_line(lst->content, split);
		lst = lst->next;
	}
}
