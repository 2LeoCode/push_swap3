#include <stack.h>
#include <stdlib.h>

int	alloc_stacks(t_stack **sa_ptr, t_stack **sb_ptr, size_t size)
{
	*sa_ptr = stkalloc(size);
	if (!*sa_ptr)
		return (-1);
	*sb_ptr = stkalloc(size);
	if (*sb_ptr)
		return (0);
	free(*sa_ptr);
	*sa_ptr = NULL;
	return (-1);
}
