#include <sys/types.h>
#include <stdint.h>
#include <stack.h>
#include <utils.h>

int	fill_stack(t_stack *sa, int ac, const char **av)
{
	const char	*ptr;
	const char	*begin;

	while (--ac)
	{
		begin = av[ac] - 1;
		ptr = av[ac] + ft_strlen(av[ac]) - 1;
		while (ptr != begin)
		{
			while (ft_isspace(*ptr))
				--ptr;
			while (ft_isdigit(*ptr))
				--ptr;
			if (ft_isdigit(*(ptr + 1)))
				if (stkpush(sa, ft_atoi(ptr + 1)) == STACK_DUPLICATE)
					return (-1);
		}
	}
	return (0);
}
