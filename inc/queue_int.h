#ifndef QUEUE_INT_H
# define QUEUE_INT_H

struct s_queue
{
	unsigned int	head;
	unsigned int	tail;
	size_t			size;
	size_t			capacity;
	const char		*data[];
}

#endif
