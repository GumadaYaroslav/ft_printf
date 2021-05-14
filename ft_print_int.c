#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_normilize(struct s_specifier *flags, long num)
{
	int	k;

	if (flags->zero && flags->minus)
		flags->zero = 0;
	if (flags->is_accur && flags->accur >= 0)
		flags->zero = 0;
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
	if (!flags->width)
		flags->minus = 0;
}

static void	print_if_zero_flag(struct s_specifier *flags, int *i,
		long num)
{
	int		flag;

	flag = 0;
	if (num < (long) 0)
	{
		*i += print_char_len_times('-', 1);
		num = -num;
		flag = 1;
	}
	*i += print_char_len_times('0', flags->width
			-len_nbr_base(num, 10) - flag);
	*i += ft_putnbr_base(num, 10, "0123456789");
}

static void	print_if_minus_flag(struct s_specifier *flags, int
		*i, long num)
{
	int		flag;

	flag = 0;
	if (num < (long)0)
	{
		*i += print_char_len_times('-', 1);
		num = -num;
		flag = 1;
	}
	if (flags->accur >= len_nbr_base(num, 10))
	{
		*i += print_char_len_times('0', flags->accur - len_nbr_base(num, 10));
		*i += ft_putnbr_base(num, 10, "0123456789");
		*i += print_char_len_times(' ', flags->width - flags->accur - flag);
		return ;
	}
	*i += ft_putnbr_base(num, 10, "0123456789");
	*i += print_char_len_times(' ', flags->width
			- len_nbr_base(num, 10) - flag);
}

static void	print_else(struct s_specifier *flags, int
*i, long num)
{
	int		flag;

	flag = 0;
	if (num < (long)0)
	{
		flag = 1;
		num = -num;
	}
	if (flags->accur >= len_nbr_base(num, 10) + flag)
	{
		*i += print_char_len_times(' ', flags->width - flags->accur - flag);
		if (flag)
			*i += print_char_len_times('-', 1);
		*i += print_char_len_times('0', flags->accur - len_nbr_base(num, 10));
	}
	else
	{
		*i += print_char_len_times(' ', flags->width
				- len_nbr_base(num, 10) - flag);
		if (flag)
			*i += print_char_len_times('-', 1);
	}
	*i += ft_putnbr_base(num, 10, "0123456789");
}

void	ft_print_int(struct s_specifier *flags, va_list ap, int *i)
{
	long	num;

	num = (long)va_arg(ap, int );
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
