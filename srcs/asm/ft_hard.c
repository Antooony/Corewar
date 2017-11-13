/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <nagaloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:32:24 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/13 15:21:38 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_acc(char *str, t_list *line)
{
	int		i;
	int		count;
	char	*s;

	i = 0;
	while (str[i])
		i++;
	count = i;
	i = 0;
	while (line && (s = (char *)line->content))
	{
		while (s[i] && s[i] != '"')
			i++;
		count = count + i + 1;
		if (s[i] == '"')
			return (count);
		line = line->next;
		i = 0;
	}
	return (count);
}

static void	ft_fill(char *str, t_list *line, char *buffer)
{
	int		i;
	int		a;
	char	*s;

	a = -1;
	i = -1;
	while (str[++i])
		buffer[++a] = str[i];
	i = 0;
	while (line && (s = (char *)line->content))
	{
		if (s[0] == '\0')
			buffer[++a] = '\n';
		while (s[i] && s[i] != '"')
		{
			buffer[++a] = str[i];
			i++;
		}
		if (s[i] == '"')
		{
			buffer[++a] = str[i];
			break ;
		}
		buffer[++a] = '\n';
		line = line->next;
		i = 0;
	}
}

static void	ft_quote(t_token **tok, t_list **line, int b)
{
	t_list *temp;
	int i;
	int a;
	char *buff;
	char	*s;

	buff = NULL;
	temp = *line;
	i = 0;
	a = 0;
	s = (char *)temp->content;
	while (s && s[i] && s[i] != '"')
		i++;
	a = ft_acc(&s[i], (*line)->next);
	buff = malloc(sizeof(char) * a + 1);
	ft_fill(&s[i], temp->next, buff);
	ft_push_token(tok, buff, i, b);
}


void	ft_hard(t_token **tok, t_list **line, int b)
{
	int i;
	char	*s;

	i = 0;
	s = (*line)->content;
	while (s && s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] == ';' || s[i] == '#')
			break ;
		if (s[i] == '"')
		{
			ft_quote(tok, line, b);
			break ;
		}
		else
			ft_naco(tok, &s[i], &i, b);
		if (s[i] == ';' || s[i] == '#')
			break ;
		i++;
	}
}
