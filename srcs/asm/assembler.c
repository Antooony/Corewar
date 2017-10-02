/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:54 by adenis            #+#    #+#             */
/*   Updated: 2017/10/02 11:23:32 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "op.c"

int		isop(char *s)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(s, g_op_tab[i].label))
			return (1);
		i++;
	}
	return (0);
}

void	token_assign(t_token *token)
{
	if (token->unknow[ft_strlen(token->unknow) - 1] == LABEL_CHAR)
		token->lab = token->unknow;
	else if (ft_strstr(token->unknow, COMMENT_CMD_STRING))
		token->comment = token->unknow;
	else if (ft_strstr(token->unknow, NAME_CMD_STRING))
		token->name = token->unknow;
	else if (token->unknow[0] == DIRECT_CHAR && token->unknow[1] == LABEL_CHAR)
		token->dirlab = token->unknow;
	else if (token->unknow[0] == DIRECT_CHAR)
		token->dir = token->unknow;
	else if (token->unknow[0] == 'r')
		token->reg = token->unknow;
	else if (isop(token->unknow))
		token->inst = token->unknow;
}

void	specify_tokens(t_token *token)
{
	while (token)
	{
		token_assign(token);
		token = token->next;
	}
}

char	*what_is_it(t_token *token)
{
	if (token->lab)
		return ("lab");
	if (token->comment)
		return ("comment");
	if (token->dirlab)
		return ("dirlab");
	if (token->indirlab)
		return ("indirlab");
	if (token->dir)
		return ("dir");
	if (token->name)
		return ("name");
	if (token->ncom)
		return ("ncom");
	if (token->indir)
		return ("indir");
	if (token->inst)
		return ("inst");
	if (token->reg)
		return ("reg");
	if (token->unknow)
		return ("unknow");
	return (NULL);
}

void	ft_asm(int fd)
{
	t_list	*lst;
	t_token	*split;

	split = new_token(NULL);
	lst = get_input(fd);
	tokenize_lst(lst, split);
	specify_tokens(split);
	while (split->next)
	{
		ft_printf("'%s' -- %s\n", split->unknow, what_is_it(split));
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
