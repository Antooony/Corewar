/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <nolivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:17:53 by nolivier          #+#    #+#             */
/*   Updated: 2017/10/02 11:03:56 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H
# include "op.h"
# include "libft.h"

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

void			del(void *content, size_t size);
void			display_lst(t_list *lst);
int				ft_error(void);
int				ft_usage(void);
t_list			*get_input(int fd);
int				isop(char *s);

t_token			*new_token(char *s);
void			token_add(t_token *split, t_token *new);
void			tokenize_lst(t_list *lst, t_token *split);

int			*ft_lab(char *s);
int			*ft_comment(char *s);
int			*ft_dirlab(char *s);
int			*ft_indirlab(char *s);
int			*ft_dir(char *s);
int			*ft_name(char *s);
int			*ft_ncom(char *s);
int			*ft_indir(char *s);
int			*ft_inst(char *s);
int			*ft_reg(char *s);

typedef int		*(*t_ftype) (char *);

#endif
