/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:17:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/10/03 15:56:16 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H
# include "op.h"
# include "libft.h"
# define OUT g_out

typedef	struct		s_token
{
	struct s_token	*next;
	int				lan;
	int				col;
	char			*lab;
	char			*comment;
	char			*dirlab;
	char			*indirlab;
	char			*dir;
	char			*name;
	char			*ncom;
	char			*indir;
	char			*inst;
	char			*reg;
	char			*unknow;
}					t_token;

typedef	struct		s_output
{
	struct s_output	*next;
	struct s_output	*link;
	int				type;
	char			*name;
	int				val;
	int				size;
}					t_output;

t_output		*new_output(char *name, int type);
void			fill_output(void);
void			create_output(t_token *token);
void			link_op(t_output *op, int narg);
void			link_output(void);

void			print_it(t_token *token);
void			print_token(t_token *split);
void			print_output(void);

void			del(void *content, size_t size);
void			display_lst(t_list *lst);
int				ft_error(void);
int				ft_usage(void);
t_list			*get_input(int fd);
int				isop(char *s);

t_token			*new_token(char *s);
void			token_add(t_token *split, t_token *new);
void			tokenize_lst(t_list *lst, t_token *split);
void			token_assign(t_token *token);
void			specify_tokens(t_token *token);

int				whichop(char *s);
int				isop(char *s);
int				get_value(t_token *token);

void			ft_lab(t_output *pop);
void			ft_comment(t_output *pop);
void			ft_dirlab(t_output *pop);
void			ft_indirlab(t_output *pop);
void			ft_dir(t_output *pop);
void			ft_name(t_output *pop);
void			ft_ncom(t_output *pop);
void			ft_indir(t_output *pop);
void			ft_inst(t_output *pop);
void			ft_reg(t_output *pop);

typedef void	(*t_ftype) (t_output *);

t_ftype			g_ft_tab[10];
t_output		*g_out;

#endif
