#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

int	print_it(const char *str, struct s_specifier *flags, va_list ap, int *i)
{
	if (*str == (const char) 'c')
		ft_print_char(flags, ap, i);
	else if (*str == (const char) '%')
		ft_print_procent(flags, i);
	else if (*str == (const char) 's')
		ft_print_string(flags, ap, i);
	else if (*str == (const char) 'd' || *str == (const char) 'i')
		ft_print_int(flags, ap, i);
	else if (*str == (const char) 'u')
		ft_print_unsign(flags, ap, i);
	else if (*str == (const char) 'x')
		ft_print_x(flags, ap, i, "0123456789abcdef");
	else if (*str == (const char) 'X')
		ft_print_x(flags, ap, i, "0123456789ABCDEF");
	else if (*str == (const char) 'p')
		ft_print_p(flags, ap, i, "0123456789abcdef");
	else if (*str == (const char) 'o')
		ft_print_o(flags, ap, i, "01234567");
	else if (*str == (const char) 'n')
		ft_print_n(flags, ap, i);
	return (0);
}
