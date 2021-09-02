#ifndef STACK_INT_H
# define STACK_INT_H

# include <stack.h>

struct s_stack
{
	int		*begin;
	int		*end;
	size_t	size;
	size_t	capacity;
	int		data[];
};

#endif
