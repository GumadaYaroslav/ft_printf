#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_specifier
{
	char	*str;
	int		width;
	int		minus;
	int		zero;
	int		is_accur;
	int		accur;
}				t_specifier;

int		ft_printf(const char *str, ...);
int		print_it(const char *str, struct s_specifier *flags, va_list ap,
			int *i);
int		ft_atoi(const char *str);
int		ft_putstr_fd_len(char *s, int fd, int len);
int		ft_putnbr_base(unsigned long long n, size_t b_len, char *base);
int		ft_putchar_return_nbr(char c, int fd);
int		ft_parser(const char **str, int *i, va_list ap, t_specifier *flags);
void	ft_sketch(const char *str, int *i, va_list ap);
int		ft_pars_tipe_deff(const char str);
int		ft_pars_accur(const char *str, struct s_specifier *flags, va_list ap);
int		ft_pars_width(const char *str, struct s_specifier *flags, va_list ap);
int		ft_pars_flags(const char *str, struct s_specifier *flags);
void	ft_print_char(struct s_specifier *flags, va_list ap, int *i);
int		print_char_len_times(char c, int len);
void	ft_print_procent(struct s_specifier *flags, int *i);
void	ft_print_string(struct s_specifier *flags, va_list ap, int *i);
void	ft_print_int(struct s_specifier *flags, va_list ap, int *i);
void	ft_print_unsign(struct s_specifier *flags, va_list ap, int *i);
char	*long_itoa(long long n);
void	ft_print_x(struct s_specifier *flags, va_list ap, int *i, char *base);
void	ft_print_p(struct s_specifier *flags, va_list ap, int *i, char *base);
int		len_nbr_base(long long n, int base);
void	ft_print_o(struct s_specifier *flags, va_list ap, int *i, char *base);
void	ft_print_n(struct s_specifier *flags, va_list ap, int *i);
void	ft_zeroing_struct(t_specifier *flags);
int		ft_pars_accur_helper(const char *str, struct s_specifier *flags,
			 va_list ap, int i);
#endif