#include "ft_printf.h"
#include "libft/libft.h"

void	ft_print_char(struct s_specifier *flags, va_list ap, int *i)
{
	if (flags->accur > 0 || flags->zero > 0)
		*i = -1;
	else if (flags->width && flags->minus)
	{
		*i +=ft_putchar_return_nbr(va_arg(ap, int), 1);
		*i +=print_char_len_times(' ', flags->width -1);
	}
	else if (flags->width)
	{
		*i +=print_char_len_times(' ', flags->width -1);
		*i +=ft_putchar_return_nbr(va_arg(ap, int), 1);
	}
	else
		*i +=ft_putchar_return_nbr(va_arg(ap, int), 1);
}

void	ft_print_procent(struct s_specifier *flags, int *i)
{
	if (flags->accur > 0)
		*i = -1;
	else if (flags->width && flags->minus)
	{
		*i +=ft_putchar_return_nbr('%', 1);
		*i +=print_char_len_times(' ', flags->width -1);
	}
	else if (flags->width && flags->zero)
	{
		*i +=print_char_len_times('0', flags->width -1);
		*i +=ft_putchar_return_nbr('%', 1);
	}
	else if (flags->width)
	{
		*i +=print_char_len_times(' ', flags->width -1);
		*i +=ft_putchar_return_nbr('%', 1);
	}
	else
		*i +=ft_putchar_return_nbr('%', 1);
}
