/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:59:34 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/04 16:32:12 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# define LINE_SIZE 32 * 2
# define HEADER_SIZE sizeof(t_header)

typedef struct	s_settings
{
	unsigned int			nb_champs;
	unsigned int			options;
}				t_settings;

typedef struct	s_process
{
	unsigned int			player;
	unsigned int			position;
	unsigned int			turns_count;
	unsigned char			registers[REG_NUMBER][REG_SIZE];
	struct s_process		*next;
}				t_process;

#endif
