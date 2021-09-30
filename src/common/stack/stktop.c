#include <stack_int.h>

int	stktop(const t_stack *stack_ptr)
{
	if (!stack_ptr->size)
		return (STACK_EMPTY);
	return (*stack_ptr->begin);
}
