#include "ft_printf.h"
#include "libft/libft.h"

int	ft_pars_flags(const char *str, struct s_specifier *flags)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '0' || str[i] == '-'))
	{
		if (str[i] == '0')
			flags->zero = 1;
		if (str[i] == '-')
			flags->minus = 1;
		i++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	return (i);
}

int	ft_pars_width(const char *str, struct s_specifier *flags, va_list ap)
{
	int	i;

	i = 0;
	if ((str[i] >= '0' && str[i] <= '9'))
	{
		flags->width = ft_atoi(&str[i]);
		i = len_nbr_base(flags->width, 10);
	}
	if (str[i] == '*' && i != 0)
	{
		flags->width = -1;
		return (i + 1);
	}
	if (str[i] == '*' && i == 0)
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		i = 1;
	}
	return (i);
}

int	ft_pars_accur(const char *str, struct s_specifier *flags, va_list ap)
{
	int	i;

	i = 0;
	if (*str == '.')
	{
		return (ft_pars_accur_helper(str, flags, ap, i));
	}
	else
		return (0);
}

int	ft_pars_tipe_deff(const char str)
{
	char	*gcc;
	int		i;

	gcc = "cspdiuxXno%";
	i = 0;
	while (gcc[i])
	{
		if (str == gcc[i])
			return (1);
		i++;
	}
	return (0);
}
