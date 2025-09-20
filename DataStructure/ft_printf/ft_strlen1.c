#include "ft_printf.h"

size_t	ft_strlen1(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}
