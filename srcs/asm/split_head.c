/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:43:00 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/10 18:47:36 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_easy(t_token *tok, char *str, int a)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (*str && *str == ' ' || *str == '\t')
	{
		str++;
		c++;
	}
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	str[i] = '\0';
	ft_push_token(tok, str, a, c);
}

static void	ft_hard(t_token *tok, char *str, int a)
{

}

static int only_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_header(t_token *tok, t_list *head, int i)
{
	if (ft_countchar(head->content, '#') == 0)
		ft_easy(tok, head->content, i);
	if (ft_countchar(head->content, '#') == 2)
		ft_medium(tok, head->content, i);
	if (ft_countchar(head->content, '#') == 1)
		ft_hard(tok, head, i);
}

void	split_head(t_token *tok, t_list *head)
{
	int i;
	int	a;

	a = 0;
	i = 1;
	while (head)
	{
		if (!only_space(head->content))
		{
				ft_header(tok, head, i);
				a++;
				if (a == 2)
					break;
		}
		i++;
		head = head->next;
	}	
}
