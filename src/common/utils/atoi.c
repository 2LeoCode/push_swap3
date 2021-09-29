#include <utils.h>

int	ft_atoi(const char *s)
{
	int	ret;
	int	ng;

	ng = 1;
	if (*s == '-' || *s == '+')
		ng -= 2 * (*s++ == '-');
	ret = 0;
	while (ft_isdigit(*s))
		ret = 10 * ret + *s++ - '0';
	return (ng * ret);
}
