#ifndef STACK_INT_H
# define STACK_INT_H

# include <stack.h>

struct s_stack
{
	t_value		*begin;
	t_value		*end;
	size_t		size;
	size_t		capacity;
	t_value		data[];
};

#endif
