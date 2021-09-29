#include <stack_int.h>

t_value	*stkbegin(t_stack *stack_ptr)
{
	return (stack_ptr->begin);
}

const t_value	*stkcbegin(const t_stack *stack_ptr)
{
	return ((const t_value *)stack_ptr->begin);
}

t_value	*stkrbegin(t_stack *stack_ptr)
{
	return (stack_ptr->end - 1);
}

const t_value	*stkrcbegin(const t_stack *stack_ptr)
{
	return ((const t_value *)(stack_ptr->end - 1));
}
