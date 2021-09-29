#include <stdint.h>
#include <sys/types.h>
#include <utils.h>
#include <common.h>

size_t	get_stack_size(int ac, const char **av)
{
	size_t		size;
	const char	*ptr;

	size = 0;
	while (ac--)
	{
		ptr = *av;
		while (*ptr)
		{
			while (ft_isspace(*ptr))
				++ptr;
			if (ft_isdigit(*ptr))
				++size;
			while (ft_isdigit(*ptr))
				++ptr;
			if (*ptr && !ft_isspace(*ptr))
				return (INVALID_INPUT);
		}
		++av;
	}
	return (size);
}
