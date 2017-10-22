/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:23:44 by adenis            #+#    #+#             */
/*   Updated: 2017/10/20 17:04:20 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msa.h"

int		check_magic(t_oct **lst)
{
	t_oct	*tmp;

	tmp = *lst;
	if (tmp->content != (unsigned char)(COREWAR_EXEC_MAGIC >> 24))
		return (0);
	tmp = tmp->next;
	if (tmp->content != (unsigned char)(COREWAR_EXEC_MAGIC >> 16))
		return (0);
	tmp = tmp->next;
	if (tmp->content != (unsigned char)(COREWAR_EXEC_MAGIC >> 8))
		return (0);
	tmp = tmp->next;
	if (tmp->content != (unsigned char)COREWAR_EXEC_MAGIC)
		return (0);
	tmp = tmp->next;
	*lst = tmp;
	return (1);
}
char		*get_name(char *s, t_oct **lst)
{
	int			i;
	t_oct		*tmp;

	tmp = *lst;
	i = 0;
	while (i < PROG_NAME_LENGTH + 1)
	{
		s[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	tmp = jump(tmp, 3);
	*lst = tmp;
	return (s);
}

char		*get_comment(char *s, t_oct **lst)
{
	int			i;
	t_oct		*tmp;

	i = 0;
	tmp = *lst;
	while (i < COMMENT_LENGTH + 1)
	{
		s[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	tmp = jump(tmp, 3);
	*lst = tmp;
	return (s);
}

int			get_prog_size(t_oct **lst)
{
	int		res;
	t_oct		*tmp;

	res = 0;
	tmp = *lst;
	res = tmp->content >> 24;
	tmp = tmp->next;
	res = tmp->content >> 16 | res;
	tmp = tmp->next;
	res = tmp->content >> 8 | res;
	tmp = tmp->next;
	res = tmp->content | res;
	tmp = tmp->next;
	*lst = tmp;
	return (res);
}

void		format_name(char **s)
{
	char 	*tmp;
	char 	*tmp2;

	tmp = ft_strjoin("\"", *s);
	tmp2 = ft_strjoin(tmp, "\"");
	free(*s);
	ft_strdel(&tmp);
	*s = tmp2;
}

void		get_header(t_oct **lst)
{
	char 	*name;
	char 	*comment;
	int		prog_size;

	name = ft_strnew(PROG_NAME_LENGTH);
	comment = ft_strnew(COMMENT_LENGTH);
	name = get_name(name, lst);
	prog_size = get_prog_size(lst);
	comment = get_comment(comment, lst);
	format_name(&name);
	format_name(&comment);
	write_output(".name ", 0, NULL);
	write_output(name, 0, "\n");
	write_output(".comment ", 0, NULL);
	write_output(comment, 0, "\n");
	ft_strdel(&name);
	ft_strdel(&comment);
}