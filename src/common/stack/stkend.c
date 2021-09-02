#include <stack_int.h>

int	*stkend(t_stack *stack_ptr)
{
	return (stack_ptr->end);
}

const int	*stkcend(const t_stack *stack_ptr)
{
	return ((const int *)stack_ptr->end);
}

int	*stkrend(t_stack *stack_ptr)
{
	return (stack_ptr->begin - 1);
}

const int	*stkrcend(const t_stack *stack_ptr)
{
	return ((const int *)(stack_ptr->begin - 1));
}
