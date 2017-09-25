/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:23:42 by adenis            #+#    #+#             */
/*   Updated: 2017/06/29 10:41:56 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "libft.h"

int		isop(char *s);
int		islabel(char *s);
void	dispop(void);
void	displst(t_list *lst);
void	getop(char *s);
void	init_op_tab(void);
int		isspace(char c);

#endif
