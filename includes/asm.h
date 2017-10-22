/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:11:19 by adenis            #+#    #+#             */
/*   Updated: 2017/10/22 18:37:34 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "assembler.h"
# include <stdio.h>
int		ft_sti(t_token *tok, int i, t_token *lab, t_list *sep);
int		ft_ldi(t_token *tok, int i, t_token *lab, t_list *sep);
int		ft_or(t_token *tok, int i, t_token *lab, t_list *sep);
int		ft_aff(t_token *tok, int i, t_token *lab, t_list *sep);

int			ft_checkop(t_op g_op_tab, t_token *tok, t_token *temp, t_list *sep);
int			ft_real(t_token *tok, t_token *temp, t_list *sep);
int			ft_instruc(t_token **tok, t_token *temp, t_list *sep);
int			ft_label(t_token **tok);
int			ft_check_every(t_token *tok, t_list *sep);
int			ft_check_commands(t_token **tok, t_list *sep);
int			ft_check(t_token *tok, t_list *sep);

void		ft_commands(t_list *ops, int i);

t_list		*ft_create_elem(char *data);

t_token		*ft_create_token(char *data, int i, int b);

void		ft_freetab(char **tab);

int		ft_sub(t_token *tok, int i, t_token *lab, t_list *sep);
int		ft_st(t_token *tok, int i, t_token *lab, t_list *sep);
int		ft_ld(t_token *tok, int i, t_token *lab, t_list *sep);
int		ft_live(t_token *tok, int i, t_token *temp, t_list *sep);


int			onlysep(t_token **tok);
void		ft_comment(t_token *tok);
void		ft_lab(t_token *tok);
void		ft_pindirlab(t_token *tok);
void		ft_pdirlab(t_token *tok);
void		ft_pindir(t_token *tok);
void		ft_name(t_token *tok);
void		ft_ncom(t_token *tok);
void		ft_pdir(t_token *tok);
void		ft_inst(t_token *tok);
void		ft_preg(t_token *tok);
void		ft_pars(t_token *tok);

void	ft_push_back(t_list **begin_list, char *data);

void	ft_push_token(t_token **begin_list, char *data, int i, int b);

static int		ft_howmany(t_token *tok, int i, int a, t_token *temp);
void			ft_puterror(t_token *tok, int i, int a, t_token *temp);

void	ft_puterrorsep(int i);

int	ft_indir(t_token *tok, int i, t_token *temp);
int ft_indirlab(char *tok, t_token *temp);
int ft_dirlab(char *tok, t_token *temp);
int	ft_dir(t_token *tok, int i, t_token *temp);
int ft_reg(t_token *tok, int i);

int		ft_tomuch(t_token *tok, int i);

int		ft_finishim(char **tab);
int		ft_finish(char **tab);
int		ft_virgule(int i, t_list *sep, int c);

int			count_l(char *str);
void		filltab(char *tab, char *str);
void		counttab(char **tab, char *str);
int			count_w(char *str);
char		**split_space(char *str);

int			ft_sep(char *str);
void		ft_guill(t_token **tok, char *str, int *count, int b);
void		ft_try(t_token **tok, char *str, int *count, int b);
void		split_tok(t_token **tok, char *str, int b);

int		ft_countchar(char *str, char c);
int		ft_decoupe(char const *s);
char	ft_lastchar(char *str);
char		**ft_remp(char **tab, char const *s, int g);
char		**ft_strsplit(char const *s);

void	display_lst(t_list *lst);
int		ft_error(void);
int		ft_usage(void);

#endif