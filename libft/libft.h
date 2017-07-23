/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:46:11 by adenis            #+#    #+#             */
/*   Updated: 2017/06/02 12:30:04 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# define OPT "-+0# "
# define SIZE "hljz"
# define CONV "sSpdDioOuUxXcC%"
# define HEXA "0123456789abcdef"
# define HEXAM "0123456789ABCDEF"
# define OCTAL "01234567"
# define BUFF_SIZE 100
# define MAX_LEN_LINE 100000
# define CUR_BUFF current->content
# define CUR_FD current->content_size

typedef struct s_list	t_list;
struct					s_list
{
	void				*content;
	size_t				content_size;
	int					fd;
	t_list				*next;
	t_list				*start;
};

typedef void			(*t_ft) ();

typedef struct			s_args
{
	int		fd;
	char	*opt;
	int		len;
	int		acc;
	int		vacc;
	char	*size;
	char	conv;
	int		ret;
	int		sign;
	int		zero;
	int		max;
	char	*out;
}						t_args;

int						ft_printf(char *str, ...);
int						ft_sprintf(char **dest, char *str, ...);
int						ft_fprintf(int fd, char *str, ...);
int						get_next_line(const int fd, char **line);

char					*ft_checksign(char *str);
int						ft_check_args(void);
void					init_args(void);
void					clean_args(void);
void					print_args(void);
void					ft_getargs(char *str, int *i, va_list ap);
char					*wtoa(wchar_t c);
char					*get_wstr(va_list ap);

void					ft_conv(va_list ap, char *s, int *i);
void					ft_noconv(char *s, int *i);
int						get_wcharlen(int nb);

void					join_out(char *str);
int						ft_get_acc(char *str, int *i, va_list ap);
int						ft_get_len(char *str, int *i, va_list ap);
char					*ft_get_opt(char *str, int *i);

void					ft_convs(va_list ap);
void					ft_convss(va_list ap);
void					ft_convp(va_list ap);
void					ft_convi(va_list ap);
void					ft_convo(va_list ap);
void					ft_convx(va_list ap);
void					ft_convxx(va_list ap);
void					ft_convc(va_list ap);
void					ft_convcc(va_list ap);
void					ft_convper(void);
void					ft_convu(va_list ap);
void					ft_convuu(va_list ap);

void					ft_sconv(va_list ap, char *s, int *i);
void					ft_snoconv(char *s, int *i);
void					ft_sconvs(va_list ap);
void					ft_sconvss(va_list ap);
void					ft_sconvp(va_list ap);
void					ft_sconvi(va_list ap);
void					ft_sconvo(va_list ap);
void					ft_sconvx(va_list ap);
void					ft_sconvxx(va_list ap);
void					ft_sconvc(va_list ap);
void					ft_sconvcc(va_list ap);
void					ft_sconvper(void);
void					ft_sconvu(va_list ap);
void					ft_sconvuu(va_list ap);

char					*ft_get_opt(char *str, int *i);
char					*ft_get_size(char *str, int *i);
int						ft_get_nbr(char *str, int *i);
int						ft_get_conv(char c);

void					ft_int_l(va_list ap, char **str);
void					ft_int_ll(va_list ap, char **str);
void					ft_int_h(va_list ap, char **str);
void					ft_int_hh(va_list ap, char **str);
void					ft_int_j(va_list ap, char **str);
void					ft_int_z(va_list ap, char **str);

void					ft_u_l(va_list ap, char **str);
void					ft_u_ll(va_list ap, char **str);
void					ft_u_h(va_list ap, char **str);
void					ft_u_hh(va_list ap, char **str);
void					ft_u_j(va_list ap, char **str);
void					ft_u_z(va_list ap, char **str);

void					ft_x_l(va_list ap, char **str, char *base, int val);
void					ft_x_ll(va_list ap, char **str, char *base, int val);
void					ft_x_h(va_list ap, char **str, char *base, int val);
void					ft_x_hh(va_list ap, char **str, char *base, int val);
void					ft_x_j(va_list ap, char **str, char *base, int val);
void					ft_x_z(va_list ap, char **str, char *base, int val);

int						ft_nbrlen(int n);
void					ft_lstadd_end(t_list *alst, t_list *new);

void					ft_putchar(int c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putwchar(wchar_t c);
void					ft_putwchar_fd(wchar_t c, int fd);
void					ft_putwstr(wchar_t *s);
void					ft_putwstr_fd(wchar_t *s, int fd);

char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big, const char *little, \
	size_t len);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char(*f)(unsigned int,\
	char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,\
	size_t len);
char					*ft_strsubfree(char *s, unsigned int start, size_t len);

char					*ft_strjoinfree(char *s1, char *s2);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(const char *s);
char					**ft_strsplit(char const *s, char c);

void					ft_sort_tab(char **tab);
int						ft_power(int nb, int power);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_atoi(char *str);
long long				ft_atol(const char *str);
char					*ft_itoa(intmax_t n);
char					*ft_uitoa(uintmax_t n);
char					*ft_itoa_base(uintmax_t n, char *s, int base);
char					*ft_ltoa_base(long long n, char *s, int base);

void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c, \
	size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);

t_list					*ft_lstsplit(char const *s, char c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void *, \
	size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_args g_arg;

static const t_ft g_size_i[] =
{
	&ft_int_h,
	&ft_int_l,
	&ft_int_j,
	&ft_int_ll,
	&ft_int_hh,
	&ft_int_z
};

static const t_ft g_size_x[] =
{
	&ft_x_h,
	&ft_x_l,
	&ft_x_j,
	&ft_x_ll,
	&ft_x_hh,
	&ft_x_z

};

static const t_ft g_size_u[] =
{
	&ft_u_h,
	&ft_u_l,
	&ft_u_j,
	&ft_u_ll,
	&ft_u_hh,
	&ft_u_z
};

static const t_ft g_ft[] =
{
	&ft_convs,
	&ft_convss,
	&ft_convp,
	&ft_convi,
	&ft_convi,
	&ft_convi,
	&ft_convo,
	&ft_convo,
	&ft_convu,
	&ft_convuu,
	&ft_convx,
	&ft_convxx,
	&ft_convc,
	&ft_convcc,
	&ft_convper
};

static const t_ft g_sft[] =
{
	&ft_sconvs,
	&ft_sconvss,
	&ft_sconvp,
	&ft_sconvi,
	&ft_sconvi,
	&ft_sconvi,
	&ft_sconvo,
	&ft_sconvo,
	&ft_sconvu,
	&ft_sconvuu,
	&ft_sconvx,
	&ft_sconvxx,
	&ft_sconvc,
	&ft_sconvcc,
	&ft_sconvper
};

#endif
