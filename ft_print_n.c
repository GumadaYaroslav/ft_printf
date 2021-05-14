#include "ft_printf.h"

void	ft_print_n(struct s_specifier *flags, va_list ap, int *i)
{
	int	*s;

	ft_zeroing_struct(flags);
	s = va_arg(ap, int *);
	*s = *i;
}
