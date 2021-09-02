#include <stack_int.h>

void	stkclear(t_stack *stack)
{
	stack->size = 0;
	stack->begin = stack->end;
}
