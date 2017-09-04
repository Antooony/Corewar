/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:17:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/04 16:58:49 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "op.h"
# include "libft.h"

void		print_optab(void);
void		display_lst(t_list *lst);
int			ft_error(void);
int			ft_usage(void);
t_list		*get_input(int	fd);

#endif
