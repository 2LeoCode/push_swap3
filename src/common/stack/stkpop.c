#include <stack_int.h>

int	stkpop(t_stack *stack_ptr)
{
	if (!stack_ptr->size)
		return (STACK_EMPTY);
	--stack_ptr->size;
	return (*stack_ptr->begin++);
}
