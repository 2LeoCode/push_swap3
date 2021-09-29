#include <checker.h>
#include <stdlib.h>
#include <stack.h>

int	ft_failure(void (*except), t_stack **sa_ptr, t_stack **sb_ptr)
{
	if (*sa_ptr)
	{
		free(*sa_ptr);
		*sa_ptr = NULL;
	}
	if (*sb_ptr)
	{
		free(*sb_ptr);
		*sb_ptr = NULL;
	}
	return (ft_exception(except));
}
