#ifndef QUEUE_INT_H
# define QUEUE_INT_H

# include <stdint.h>
# include <sys/types.h>

# include <queue.h>

struct s_queue
{
	unsigned int	head;
	unsigned int	tail;
	size_t			size;
	size_t			capacity;
	const char		*data[];
};

#endif
