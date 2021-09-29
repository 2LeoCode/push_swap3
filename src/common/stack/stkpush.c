#include <stack_int.h>

int	stkpush(t_stack *stack_ptr, int value, bool sorted, bool head)
{
	t_value	*it;

	if (stack_ptr->size == stack_ptr->capacity)
		return (STACK_FULL);
	it = stack_ptr->begin - 1;
	while (++it != stack_ptr->end)
		if (it->val == value)
			return (STACK_DUPLICATE);
	(--stack_ptr->begin)->val = value;
	(stack_ptr->begin)->error = false;
	(stack_ptr->begin)->head = head;
	(stack_ptr->begin)->sorted = sorted;
	++stack_ptr->size;
	return (0);
}
