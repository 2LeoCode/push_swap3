#include <stack_int.h>

bool	stkfull(const t_stack *stack_ptr)
{
	return (stack_ptr->size == stack_ptr->capacity);
}
