#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_normilize(struct s_specifier *flags, long num)
{
	int	k;

	if (flags->zero && flags->minus)
		flags->zero = 0;
	if (flags->is_accur && flags->accur >= 0)
		flags->zero = 0;
	k = len_nbr_base(num, 16);
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
	if (!flags->width)
		flags->minus = 0;
}

static void	print_if_zero_flag(struct s_specifier *flags, int *i,
								  long num, char *b)
{
	*i += print_char_len_times('0', flags->width - len_nbr_base(num, 16));
	*i += ft_putnbr_base(num, 16, b);
}

static void	print_if_minus_flag(struct s_specifier *flags, int
*i, long num, char *b)
{
	int		k;

	k = 0;
	if (flags->accur >= len_nbr_base(num, 16))
	{
		*i += print_char_len_times('0', flags->accur - len_nbr_base(num, 16));
		k = (flags->accur - len_nbr_base(num, 16));
	}
	*i += ft_putnbr_base(num, 16, b);
	*i += print_char_len_times(' ', flags->width - len_nbr_base(num, 16) - k);
}

static void	print_else(struct s_specifier *flags, int
*i, long num, char *b)
{
	if (flags->accur >= len_nbr_base(num, 16))
	{
		*i += print_char_len_times(' ', flags->width - flags->accur);
		*i += print_char_len_times('0', flags->accur - len_nbr_base(num, 16));
	}
	else
	{
		*i += print_char_len_times(' ', flags->width - len_nbr_base(num, 16));
	}
	*i += ft_putnbr_base(num, 16, b);
}

void	ft_print_x(struct s_specifier *flags, va_list ap, int *i, char *base)
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
		print_if_zero_flag(flags, i, num, base);
	else if (flags->minus)
		print_if_minus_flag(flags, i, num, base);
	else
		print_else(flags, i, num, base);
}
