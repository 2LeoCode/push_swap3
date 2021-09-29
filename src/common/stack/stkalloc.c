#include <stack_int.h>

t_stack	*stkalloc(size_t size)
{
	t_stack	*stack_ptr;

	stack_ptr = malloc(sizeof(t_stack) + sizeof(t_value) * size);
	if (!stack_ptr)
		return (NULL);
	stack_ptr->size = 0;
	stack_ptr->capacity = size;
	stack_ptr->end = (t_value *)stack_ptr->data + size;
	stack_ptr->begin = stack_ptr->end;
	return (stack_ptr);
}
