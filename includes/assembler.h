/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:17:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/11 16:39:30 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H
# include "op.h"
# include "libft.h"
# define OP g_infos.labels->ops
# define LABEL g_infos.labels
# define FLABEL g_infos.firstlabel
# define FOP g_infos.labels->firstop
# define BLANK "\t\v "

typedef struct		s_ops
{
	char			*name;
	int				nargs;
	char			**args;
	int				op_code;
	int				label_size;
	int				coding_param;
	struct s_ops	*next;
}					t_ops;

typedef struct		s_label
{
	char			*name;
	t_ops			*ops;
	t_ops			*firstop;
	struct s_label	*next;
}					t_label;

typedef struct		s_infos
{
	char			*name;
	char			*comment;
	t_label			*labels;
	t_label			*firstlabel;
}					t_infos;

t_infos				g_infos;

void				print_optab(void);
void				display_lst(t_list *lst);
int					ft_error(void);
int					ft_usage(void);
t_list				*get_input(int	fd);
int					ft_op_delim(char *s, int i, int len);
void				fill_op(int i, char *s);
void				get_op(char *s);
void				get_labels(char *s);
void				get_name(char *s);
void				get_comment(char *s);
void				get_header(t_list *lst);
void				parsing(t_list *lst);
t_label				*ft_newlabel(void);
void				init_ops(void);
void				init_label(void);
void				init_infos(void);
t_ops				*ft_newop(void);
void				clean_spaces(int j);
void				free_ops(t_ops *op);
void				free_labels(t_label *label);
void				del(void *content, size_t size);
void				leave_free(t_list *lst);

#endif
