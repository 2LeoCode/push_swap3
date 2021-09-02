#include <stack_int.h>

t_stack	*stkdup(const t_stack *stack_ptr)
{
	t_stack		*new_ptr;
	const int	*it_src = (const int *)stack_ptr->begin;
	int			*it_dst;

	new_ptr = malloc(sizeof(t_stack) + sizeof(int) * stack_ptr->capacity);
	if (!new_ptr)
		return (NULL);
	new_ptr->size = stack_ptr->size;
	new_ptr->capacity = stack_ptr->capacity;
	new_ptr->end = (int *)new_ptr->data + new_ptr->capacity;
	new_ptr->begin = new_ptr->end - new_ptr->size;
	it_dst = new_ptr->begin;
	while (it_dst != new_ptr->end)
		*it_dst++ = *it_src++;
	return (new_ptr);
}
