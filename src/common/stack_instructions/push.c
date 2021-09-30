#include <stack.h>

const char	*pa(t_stack *a, t_stack *b)
{
	int x;

	if (!a || !b)
		return ("pa");
	x = stkpop(b);
	if (x != STACK_EMPTY)
		stkpush(a, x);
	return (NULL);
}

const char	*pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("pb");
	return (pa(b, a));
}
