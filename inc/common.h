#ifndef COMMON_H
# define COMMON_H

# include <sys/types.h>
# include <stdint.h>

# include "stack.h"
# include "instructions.h"
# include "utils.h"

# define INVALID_INPUT ((size_t)-1)

size_t	get_stack_size(int ac, const char **av);
int		fill_stack(t_stack *sa, int ac, const char **av);
int		alloc_stacks(t_stack **sa_ptr, t_stack **sb_ptr, size_t size);

int		ft_failure(void (*except), t_stack **sa_ptr, t_stack **sb_ptr);
int		ft_exception(void (*except)());
void	invalid_arguments(void);
void	out_of_memory(void);
void	duplicate_element(void);

#endif
