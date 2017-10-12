/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:35:23 by adenis            #+#    #+#             */
/*   Updated: 2017/10/12 16:00:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	printop(int val, int size)
{
	if (size >= 4)
		ft_putchar_fd((val >> 24), FD);
	if (size >= 3)
		ft_putchar_fd((val >> 16), FD);
	if (size >= 2)
		ft_putchar_fd((val >> 8), FD);
	if (size >= 1)
		ft_putchar_fd(val, FD);
}

void	print_val(void)
{
	t_output	*pop;

	pop = OUT;
	while (pop)
	{
		printop(pop->val, pop->size);
		pop = pop->next;
	}
}

void	print_name(t_header *header, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		header->prog_name[i] = s[i];
		i++;
	}
	i = 0;
	while (i < PROG_NAME_LENGTH + 1)
	{
		ft_putchar_fd(header->prog_name[i], FD);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		ft_putchar_fd(0, FD);
		i++;
	}
	print_magic(PROG_SIZE);
}

void	print_comment(t_header *header, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		header->comment[i] = s[i];
		i++;
	}
	i = 0;
	while (i < COMMENT_LENGTH + 1)
	{
		ft_putchar_fd(header->comment[i], FD);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		ft_putchar_fd(0, FD);
		i++;
	}
}

void	print_header(void)
{
	t_output	*tmp;
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	tmp = OUT;
	print_magic(header->magic);
	while (tmp)
	{
		if (tmp->type == 7)
			print_name(header, tmp->name);
		if (tmp->type == 2)
			print_comment(header, tmp->name);
		tmp = tmp->next;
	}
}