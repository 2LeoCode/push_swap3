#include <stack.h>
#include <utils.h>
#include <stdio.h>
const char	*ra(t_stack *a, t_stack *b)
{
	size_t		size;
	t_value		*begin;
	t_value		x;

	if (!a || !b)
		return ("ra");
	(void)b;
	size = stksize(a);
	if (size < 2)
		return (NULL);
	begin = stkbegin(a);
	x = *begin;
	ft_memmove(begin, begin + 1, (size - 1) * sizeof(t_value));
	begin = stkbegin(a);
	*stkrbegin(a) = x;
	return (NULL);
}

const char	*rb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rb");
	return (ra(b, a));
}

const char	*rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rr");
	ra(a, b);
	rb(a, b);
	return (NULL);
}

const char	*rra(t_stack *a, t_stack *b)
{
	size_t		size;
	t_value		*begin;
	t_value		x;

	if (!a || !b)
		return ("rra");
	(void)b;
	size = stksize(a);
	if (size < 2)
		return (NULL);
	begin = stkbegin(a);
	x = *stkrbegin(a);
	ft_memmove(begin + 1, begin, (size - 1) * sizeof(t_value));
	*begin = x;
	return (NULL);
}

const char	*rrb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rrb");
	return (rra(b, a));
}

const char	*rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("rrr");
	rra(a, b);
	rrb(a, b);
	return (NULL);
}