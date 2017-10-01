/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/09/28 16:52:17 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.c"

void	token_assign(t_token token)
{
	if (token->unknow[ft_strlen(token->unknow)] == LABEL_CHAR)
		token->label = token->unknow;
	else if (ft_strstr(token->unknow, COMMENT_CMD_STRING))
		token->comment = token->unknow;
	else if (ft_strstr(token->unknow, NAME_CMD_STRING))
		token->name = token->unknow;
	else if (token->unknow[0] == DIRECT_CHAR && token->unknow[1] == LABEL_CHAR)
			token->dir = token->unknow;
	else if (token->unknow[0] == DIRECT_CHAR)
		token->dir = token->unknow;
}

t_token	*new_token(char *s)
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

void token_add(t_token *split, t_token *new)
{
	if (split->next)
	{
		token_add(split->next, new);
		return ;
	}
	split->next = new;
}

void	tokenize_line(char *s, t_token *split)
{
	if (ft_strstr(s, NAME_CMD_STRING) || ft_strstr(s, COMMENT_CMD_STRING))
		split->unknow ? token_add(split, new_token(s))
			: (split->unknow = ft_strdup(s));
	else
	{
		while (s && ft_strchr(s, ' '))
		{
			split->unknow ? token_add(split, new_token(ft_strsub(s,
				0, ft_strchr(s, ' ') - s)))
				: (split->unknow = ft_strsub(s, 0, ft_strchr(s, ' ') - s));
			s = ft_strchr(s, ' ') + 1;
		}
	}
}

void	tokenize_lst(t_list *lst, t_token *split)
{
	while (lst)
	{
		tokenize_line(lst->content, split);
		lst = lst->next;
	}
}

void	ft_asm(int fd)
{
	t_list	*lst;
	t_token	*split;

	split = new_token(NULL);
	lst = get_input(fd);
	tokenize_lst(lst, split);
	while (split->next)
	{
		ft_printf("%s\n", split->unknow);
		split = split->next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	ft_asm(fd);
	if (close(fd) == -1)
		return (ft_error());
}
