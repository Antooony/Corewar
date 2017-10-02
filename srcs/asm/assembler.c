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

int		whichop(char *s)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(s, g_op_tab[i].label))
			return (i);
		i++;
	}
	return (0);
}

t_ftype	g_ft_tab[] =
{
	&ft_lab,
	&ft_comment,
	&ft_dirlab,
	&ft_indirlab,
	&ft_dir,
	&ft_name,
	&ft_ncom,
	&ft_indir,
	&ft_inst,
	&ft_reg
};

int		*ft_lab(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_comment(char *s)
{
	return (NULL);
}

int		*ft_dirlab(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_indirlab(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_dir(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_name(char *s)
{
	return (NULL);
}

int		*ft_ncom(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = 0;
	n = out;
	return (n);
}

int		*ft_indir(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = ft_atoi(&s[1]);
	n = out;
	return (n);
}

int		*ft_inst(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = whichop(s) + 1;
	n = out;
	return (n);
}

int		*ft_reg(char *s)
{
	int		out[2];
	int		*n;
	if (!s)
		return (NULL);
	out[0] = 1;
	out[1] = ft_atoi(&s[1]);
	n = out;
	return (n);
}

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
}

void	specify_tokens(t_token *token)
{
	while (token)
	{
		token_assign(token);
		token = token->next;
	}
}

int		get_value(t_token *token)
{
	int 	i;

	i = 0;
	if (token->lab)
		return (i);
	if ((++i) && token->comment)
		return (i);
	if ((++i) && token->dirlab)
		return (i);
	if ((++i) && token->indirlab)
		return (i);
	if ((++i) && token->dir)
		return (i);
	if ((++i) && token->name)
		return (i);
	if ((++i) && token->ncom)
		return (i);
	if ((++i) && token->indir)
		return (i);
	if ((++i) && token->inst)
		return (i);
	if ((++i) && token->reg)
		return (i);
	return (-1);
}

void	print_it(t_token *token)
{
	int		*out;
	int		i;

	i = get_value(token);
	ft_printf("i = %d | ", i);
	if (i > 9)
		return ;
	out = (int *)g_ft_tab[i](token->unknow);
	if (!out)
	{
		ft_putchar('\n');
		return ;
	}
	ft_printf("out[0] = %d | out[1] = %d\n", out[0], out[1]);
}

void	print_token(t_token *split)
{
	while (split)
	{
		ft_printf("%s | %d\n", split->unknow, get_value(split));
		split = split->next;
	}
}

void	ft_asm(int fd)
{
	t_list	*lst;
	t_token	*split;

	split = new_token(NULL);
	lst = get_input(fd);
	tokenize_lst(lst, split);
	specify_tokens(split);
	print_token(split);
	while (split)
	{
		ft_printf("%s | ", split->unknow);
		print_it(split);
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
