/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:36:45 by adenis            #+#    #+#             */
/*   Updated: 2017/10/10 16:03:31 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	token_assign(t_token *token)
{
	if (ft_strstr(token->unknow, COMMENT_CMD_STRING))
		token->comment = token->unknow;
	else if (ft_strstr(token->unknow, NAME_CMD_STRING))
		token->name = token->unknow;
	else if (token->unknow[ft_strlen(token->unknow) - 1] == LABEL_CHAR)
		token->lab = token->unknow;
	else if (token->unknow[0] == DIRECT_CHAR && token->unknow[1] == LABEL_CHAR)
		token->dirlab = token->unknow;
	else if (token->unknow[0] == DIRECT_CHAR)
		token->dir = token->unknow;
	else if (token->unknow[0] == 'r')
		token->reg = token->unknow;
	else if (isop(token->unknow))
		token->inst = token->unknow;
	else
		token->indir = token->unknow;
}

void	specify_tokens(t_token *token)
{
	while (token)
	{
		token_assign(token);
		token = token->next;
	}
}
