/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:02:53 by adenis            #+#    #+#             */
/*   Updated: 2017/10/19 17:48:56 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSA_H
# define MSA_H
# include "op.h"
# include "libft.h"
# define LST g_lst
# define OUT g_out
# define LINE g_line
# define LAB g_lab

typedef	struct	s_oct
{
	char			content;
	int				val;
	struct s_oct	*next;
}				t_oct;

void			ft_octadd_end(t_oct *alst, t_oct *new);
int				ft_error(void);
int				ft_usage(void);
void			display_lst(t_oct *lst);
void			display_out(void);

int				check_magic(t_oct **lst);
void			print_cor(t_oct *tmp, t_oct	*lst);
int				noct(int opc, t_oct *lst);
t_oct			*jump(t_oct *lst, int n);

t_oct			*get_input(int fd);
char			*get_name(char *s, t_oct **lst);
char			*get_comment(char *s, t_oct **lst);
int				get_prog_size(t_oct **lst);
void			get_header(t_oct **lst);
int				get_type(int opc, t_oct *lst);
void			get_arg(t_oct **lst, int size, int type);
void			get_opc(t_oct **lst);
void			get_values(t_oct *lst);

void			handle_args(t_oct **lst);
void			handle_opc(t_oct **lst, int a1, int a2, int a3);

void			lst_val(t_oct *lst);
void			write_output(char *line, int val, char *suf);
void			out_val(void);

t_oct			*g_lst;
t_list			*g_out;
char			*g_line;
int				g_lab;
#endif
