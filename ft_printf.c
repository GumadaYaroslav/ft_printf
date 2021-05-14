#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_zeroing_struct(t_specifier *flags)
{
	flags->accur = 0;
	flags->width = 0;
	flags->is_accur = 0;
	flags->minus = 0;
	flags->zero = 0;
}

void	ft_sketch(const char *str, int *i, va_list ap)
{
	int			g;
	t_specifier	flags;

	flags.str = (char *)str;
	ft_zeroing_struct(&flags);
	while (*str)
	{
		if (*str != '%')
			*i = *i + ft_putchar_return_nbr((char)*str, 1);
		else
		{
			g = ft_parser(&str, i, ap, &flags);
			if (g == -1)
			{
				*i = -1;
				break ;
			}
			ft_zeroing_struct(&flags);
		}
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	ft_sketch(str, &i, ap);
	va_end(ap);
	return (i);
}
