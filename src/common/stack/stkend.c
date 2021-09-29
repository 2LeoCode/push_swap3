#include <stack_int.h>

t_value	*stkend(t_stack *stack_ptr)
{
	return (stack_ptr->end);
}

const t_value	*stkcend(const t_stack *stack_ptr)
{
	return ((const t_value *)stack_ptr->end);
}

t_value	*stkrend(t_stack *stack_ptr)
{
	return (stack_ptr->begin - 1);
}

const t_value	*stkrcend(const t_stack *stack_ptr)
{
	return ((const t_value *)(stack_ptr->begin - 1));
}
