#include "ft_printf.h"
#include "libft/libft.h"

int	ft_pars_accur_helper(const char *str, struct s_specifier *flags,
		 va_list ap, int i)
{
	flags->is_accur = 1;
	str++;
	if ((str[i] >= '0' && str[i] <= '9'))
	{
		while (str[i] == '0' && str[i])
			i++;
		if (ft_atoi(&str[i]) > 0)
		{
			flags->accur = ft_atoi(&str[i]);
			i = i + len_nbr_base(flags->accur, 10);
		}
		else
			return (i + 1);
	}
	if (str[i] == '*' && i != 0)
		return (-1);
	if (str[i] == '*' && i == 0)
	{
		flags->accur = va_arg(ap, int);
		if (flags->accur < 0)
			return (i + 2);
		i = 1;
	}
	return (i + 1);
}

int	ft_parser(const char **str, int *i, va_list ap, t_specifier *flags)
{
	int	j[4];

	(*str)++;
	if (**str)
	{
		j[1] = ft_pars_flags(*str, flags);
		*str = *str + j[1];
		j[2] = ft_pars_width(*str, flags, ap);
		if (flags->width == -1)
			return (-1);
		j[0] = j[1] + j[2];
		*str = *str + j[2];
		j[2] = ft_pars_accur(*str, flags, ap);
		j[0] = j[0] + j[2];
		*str = *str + j[2];
		if (ft_pars_tipe_deff(**str))
		{
			j[0] = j[0] + 1;
			parce_data_type(*str, flags, ap, i);
		}
		else
			return (-1);
	}
	return (j[0]);
}
