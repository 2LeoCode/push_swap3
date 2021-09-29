#include <stack_int.h>

t_value	stkpop(t_stack *stack_ptr)
{
	if (!stack_ptr->size)
		return ((t_value){0, false, false, true});
	--stack_ptr->size;
	return (*stack_ptr->begin++);
}
