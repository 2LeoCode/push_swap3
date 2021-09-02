#include <stack_int.h>

int	*stkbegin(t_stack *stack_ptr)
{
	return (stack_ptr->begin);
}

const int	*stkcbegin(const t_stack *stack_ptr)
{
	return ((const int *)stack_ptr->begin);
}

int	*stkrbegin(t_stack *stack_ptr)
{
	return (stack_ptr->end - 1);
}

const int	*stkrcbegin(const t_stack *stack_ptr)
{
	return ((const int *)(stack_ptr->end - 1));
}
