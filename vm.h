/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:59:34 by nolivier          #+#    #+#             */
/*   Updated: 2017/06/01 13:02:34 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "op.h"
//#include "op.c"

# define LINE_SIZE 32*2
# define HEADER_SIZE sizeof(header_t)

struct	s_op
{
	char					*label;
	unsigned int			params_num;
	unsigned int			params[3];
	unsigned int			id;
	unsigned int			turns;
	char					*desc;
	
};

struct	s_settings
{
	unsigned int			nb_champs;
	unsigned int			options;
};

struct	s_process
{
	unsigned int			player;
	unsigned int			position;
	unsigned int			turns_count;
	struct s_process		*next;
};

typedef struct s_op				t_op;
typedef struct s_settings		t_settings;
typedef struct s_process		t_process;



#endif
