/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:02:53 by adenis            #+#    #+#             */
/*   Updated: 2017/10/13 19:51:46 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSA_H
# define MSA_H
# include "op.h"
# include "libft.h"

typedef	struct	s_oct
{
	char			content;
	struct s_oct	*next;
}				t_oct;

void			ft_octadd_end(t_oct *alst, t_oct *new);
int				ft_error(void);
int				ft_usage(void);
void			display_lst(t_oct *lst);
t_oct			*get_input(int fd);
int				check_magic(t_oct **lst);
char			*get_name(char *s, t_oct **lst);
char			*get_comment(char *s, t_oct **lst);
int				get_prog_size(t_oct **lst);
void			get_header(t_oct *lst);

#endif
