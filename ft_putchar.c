#include <unistd.h>
#include "ft_printf.h"
int	ft_putchar_return_nbr(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	print_char_len_times(char c, int len)
{
	int	i;

	i = 0;
	if (len <= 0)
		return (0);
	while (i != len)
	{
		ft_putchar_return_nbr(c, 1);
		i++;
	}
	return (i);
}
