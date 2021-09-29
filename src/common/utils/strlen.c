#include <utils.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		++ptr;
	return ((uintptr_t)ptr - (uintptr_t)s);
}
