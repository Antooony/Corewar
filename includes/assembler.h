/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:17:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/11/17 16:56:43 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H
# include "op.h"
# include "libft.h"
# define OUT g_out
# define FD g_fd
# define TOK g_tok
# define PROG_SIZE g_prog_size

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
	int				pos;
}					t_output;

void				init_ft_tab(void);

t_output			*new_output(char *name, int type);
void				fill_output(void);
void				create_output(t_token *token);
void				link_op(t_output *op, int narg);
void				link_output(void);

void				print_val(void);
void				print_header(void);
void				print_magic(unsigned int nb);

void				del(void *content, size_t size);
void				display_lst(t_list *lst);
int					ft_error(void);
int					ft_usage(void);
t_list				*get_input(int fd);
int					isop(char *s);
char				*getattribute(t_token *tok);
unsigned int		magic_n_size(unsigned int n);

t_output			*get_dirlab(char *s);
int					calc_dirlab(short a, short b);
void				fill_dirlab(void);

t_token				*new_token(char *s);
void				token_add(t_token *split, t_token *new);
void				tokenize_lst(t_list *lst, t_token *split);
void				token_assign(t_token *token);
void				specify_tokens(t_token *token);

int					handle_file(char *s);

int					whichop(char *s);
int					isop(char *s);
int					get_value(t_token *token);

void				ft_calc(t_token *tok);
int					ft_opc(t_output *pop);

void				out_lab(t_output *pop);
void				out_comment(t_output *pop);
void				out_dirlab(t_output *pop);
void				out_indirlab(t_output *pop);
void				out_dir(t_output *pop);
void				out_name(t_output *pop);
void				out_ncom(t_output *pop);
void				out_indir(t_output *pop);
void				out_inst(t_output *pop);
void				out_reg(t_output *pop);

void				free_tok(t_token *tok);
void				del(void *content, size_t size);
void				free_out(t_output *lst);
void				clean(t_list *lst);

typedef void		(*t_ftype) (t_output *);

t_ftype				g_ft_tab[10];
t_output			*g_out;
t_token				*g_tok;
int					g_fd;
int					g_prog_size;
int					g_name;

#endif
