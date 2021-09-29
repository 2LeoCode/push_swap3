#include <stack_int.h>

t_value	stktop(const t_stack *stack_ptr)
{
	if (!stack_ptr->size)
		return ((t_value){0, false, false, true});
	return (*stack_ptr->begin);
}
