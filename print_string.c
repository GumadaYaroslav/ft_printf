#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_normolize_this_flags(struct s_specifier *flags, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (flags->is_accur && !flags->accur)
		len = 0;
	if (flags->accur > (int)len)
	{
		flags->accur = 0;
		flags->is_accur = 0;
	}
	if (flags->width <= (int)len && !flags->accur)
	{
		flags->width = 0;
	}
	if (flags->accur < len && flags->accur > flags->width)
	{
		flags->width = 0;
	}
	if (flags->accur < 0)
	{
		flags->accur = 0;
		flags->is_accur = 0;
	}
}

static void	ft_if_minus(char *s, struct s_specifier *flags, int *i)
{
	if (flags->accur)
		*i += ft_putstr_fd_len(s, 1, flags->accur);
	else
		*i += ft_putstr_fd_len(s, 1, ft_strlen(s));
	if (flags->width && flags->accur)
		*i += print_char_len_times(' ', flags->width - flags->accur);
	else if (flags->width)
		*i += print_char_len_times(' ', flags->width - ft_strlen(s));
}

static void	ft_not_minus(char *s, struct s_specifier *flags, int *i)
{
	if (flags->width && flags->accur)
		*i += print_char_len_times(' ', flags->width - flags->accur);
	else if (flags->width)
		*i += print_char_len_times(' ', flags->width - ft_strlen(s));
	if (flags->accur)
		*i += ft_putstr_fd_len(s, 1, flags->accur);
	else
		*i += ft_putstr_fd_len(s, 1, ft_strlen(s));
}

void	ft_print_string(struct s_specifier *flags, va_list ap, int *i)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	ft_normolize_this_flags(flags, s);
	if (flags->zero)
		*i = -1;
	if (flags->is_accur && !flags->accur)
	{
		*i += print_char_len_times(' ', flags->width);
	}
	else if (flags->minus)
		ft_if_minus(s, flags, i);
	else
		ft_not_minus(s, flags, i);
}
