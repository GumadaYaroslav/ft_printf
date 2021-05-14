#include "ft_printf.h"

int	ft_putstr_fd_len(char *s, int fd, int len)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
