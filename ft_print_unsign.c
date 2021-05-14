#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_normilize(struct s_specifier *flags, long num)
{
	int	k;

	if (flags->zero && flags->minus)
	{
		flags->zero = 0;
	}
	if (flags->is_accur && flags->accur >= 0)
	{
		flags->zero = 0;
	}
	k = len_nbr_base(num, 10);
	if (flags->accur < k)
		flags->accur = 0;
	if (flags->width <= k)
	{
		flags->width = 0;
		flags->zero = 0;
	}
	if (flags->accur >= flags->width)
	{
		flags->width = 0;
		flags->zero = 0;
	}
}

static void	print_if_zero_flag(struct s_specifier *flags, int *i,
								  long long num)
{
	*i += print_char_len_times('0', flags->width - len_nbr_base(num, 10));
	*i += ft_putnbr_base(num, 10, "0123456789");
}

static void	print_if_minus_flag(struct s_specifier *flags, int
*i, long long num)
{
	char	*s;

	s = long_itoa(num);
	if (flags->accur >= (int)ft_strlen(s))
	{
		*i += print_char_len_times('0', flags->accur - ft_strlen(s));
		*i += ft_putstr_fd_len(s, 1, ft_strlen(s));
		*i += print_char_len_times(' ', flags->width - (int) ft_strlen(s)
				 - (flags->accur - ft_strlen(s)));
		free (s);
		return ;
	}
	*i += ft_putstr_fd_len(s, 1, ft_strlen(s));
	*i += print_char_len_times(' ', flags->width - (int) ft_strlen(s));
	free (s);
}

static void	print_else(struct s_specifier *flags, int
*i, long num)
{
	char	*s;

	s = long_itoa(num);
	if (flags->accur >= (int)ft_strlen(s))
	{
		*i += print_char_len_times(' ', flags->width - flags->accur);
		*i += print_char_len_times('0', flags->accur - ft_strlen(s));
	}
	else
	{
		*i += print_char_len_times(' ', flags->width - (int) ft_strlen
				(s));
	}
	*i += ft_putstr_fd_len(s, 1, ft_strlen(s));
	free (s);
}

void	ft_print_unsign(struct s_specifier *flags, va_list ap, int *i)
{
	long long	num;

	num = (long long)va_arg(ap, unsigned int);
	if (num == 0 && flags->is_accur == 1 && flags->accur == 0)
	{
		*i += print_char_len_times(' ', flags->width);
		return ;
	}
	ft_normilize(flags, num);
	if (flags->zero)
		print_if_zero_flag(flags, i, num);
	else if (flags->minus)
		print_if_minus_flag(flags, i, num);
	else
		print_else(flags, i, num);
}
