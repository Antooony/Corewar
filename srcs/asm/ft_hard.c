/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:32:24 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/12 19:39:46 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_acc(char *str, t_list *line)
{
	int i;
	int count;

	i = 0;
	while (str[i])
		i++;
	count = i;
	i = 0;
	while (line)
	{
		while (line->content[i] && line->content[i] != '"')
			i++;
		count = count + i + 1;
		if (line->content[i] == '"')
			return (count);
		line = line->next;
		i = 0;
	}
	return (count)
}

static void	ft_fill(char *str, t_list *line, char *buffer)
{
	int i;
	int a;

	a = -1;
	i = -1;
	while (str[++i])
		buffer[++a] = str[i];
	i = 0;
	while (line)
	{
		if (line->content[0] == '\0')
			buffer[++a] = '\n';
		while (line->content[i] && line->content[i] != '"')
		{
			buffer[++a] = str[i];
			i++;
		}
		if (line->content[i] == '"')
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

	buff = NULL;
	temp = *line;
	i = 0;
	a = 0;
	while (temp->content[i] && temp->content[i] != '"')
		i++;
	a = ft_acc(&temp->content[i], (*line)->next);
	buff = malloc(sizeof(char) * a + 1);
	ft_fill(&temp->content[i], temp->next, buff);
	ft_push_token(tok, buff, i, b);
}


void	ft_hard(t_token **tok, t_list **line, int b)
{
	int i;

	i = 0;
	while ((*line)->content[i])
	{
		while ((*line)->content[i] == ' ' || (*line)->content[i] == '\t')
			i++;
		if ((*line)->content[i] == ';' || (*line)->content[i] == '#')
			break ;
		if ((*line)->content[i] == '"')
		{
			ft_quote(tok, line, b, &i);
			break ;
		}
		else
			ft_naco(tok, &(*line)->content[i], &i, b);
		if ((*line)->content[i] == ';' || (*line)->content[i] == '#')
			break ;
		i++;
	}
}
