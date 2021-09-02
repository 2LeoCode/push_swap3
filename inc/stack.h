#ifndef STACK_H
# define STACK_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# define STACK_FULL 1
# define STACK_DUPLICATE 2
# define STACK_EMPTY INT_MIN

typedef struct s_stack	t_stack;

t_stack		*stkalloc(size_t size);

int			stkpush(t_stack *stack_ptr, int value);
int			stkpop(t_stack *stack_ptr);
void		stkclear(t_stack *stack_ptr);

bool		stkempty(const t_stack *stack_ptr);
bool		stkfull(const t_stack *stack_ptr);
size_t		stksize(const t_stack *stack_ptr);
int			stktop(const t_stack *stack_ptr);

t_stack		*stkdup(const t_stack *stack_ptr);

int			*stkbegin(t_stack *stack_ptr);
const int	*stkcbegin(const t_stack *stack_ptr);
int			*stkend(t_stack *stack_ptr);
const int	*stkcend(const t_stack *stack_ptr);
int			*stkrbegin(t_stack *stack_ptr);
const int	*stkcrbegin(t_stack *stack_ptr);
int			*stkrend(t_stack *stack_ptr);
const int	*stkcrend(t_stack *stack_ptr);
#endif
