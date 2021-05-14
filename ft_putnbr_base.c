#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr_base(unsigned long long n, size_t b_len, char *base)
{
	if (n < b_len)
		return (ft_putchar_return_nbr(base[n], 1));
	return (ft_putnbr_base(n / b_len, b_len, base)
		+ ft_putchar_return_nbr(base[n % b_len], 1));
}
