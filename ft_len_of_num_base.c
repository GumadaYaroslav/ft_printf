#include "ft_printf.h"
#include "libft/libft.h"

int	len_nbr_base(long long n, int base)
{
	int	k;

	k = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		k++;
	}
	return (k);
}
