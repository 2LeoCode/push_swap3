#ifndef STACK_H
# define STACK_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# define STACK_FULL 1
# define STACK_DUPLICATE 2

typedef struct s_stack	t_stack;
typedef struct s_value
{
	int		val;
	bool	sorted;
	bool	head;
	bool	error;
}	t_value;

t_stack		*stkalloc(size_t size);

int			stkpush(t_stack *stack_ptr, int value, bool sorted, bool head);
t_value		stkpop(t_stack *stack_ptr);
void		stkclear(t_stack *stack_ptr);

bool		stkempty(const t_stack *stack_ptr);
bool		stkfull(const t_stack *stack_ptr);
size_t		stksize(const t_stack *stack_ptr);
t_value		stktop(const t_stack *stack_ptr);

t_value			*stkbegin(t_stack *stack_ptr);
const t_value	*stkcbegin(const t_stack *stack_ptr);
t_value			*stkend(t_stack *stack_ptr);
const t_value	*stkcend(const t_stack *stack_ptr);
t_value			*stkrbegin(t_stack *stack_ptr);
const t_value	*stkcrbegin(t_stack *stack_ptr);
t_value			*stkrend(t_stack *stack_ptr);
const t_value	*stkcrend(t_stack *stack_ptr);

#endif
