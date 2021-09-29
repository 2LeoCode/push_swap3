#include <stack.h>

const char	*pa(t_stack *a, t_stack *b)
{
	t_value	x;

	if (!a || !b)
		return ("pa");
	x = stkpop(b);
	if (!x.error)
		stkpush(a, x.val, x.sorted, x.head);
	return (NULL);
}

const char	*pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("pb");
	return (pa(b, a));
}
