#include <queue_int.h>

int	enqueue(t_queue *queue_ptr, const char *value)
{
	if (queue_ptr->size == queue_ptr->capacity)
		return (QUEUE_FULL);
	++queue_ptr->size;
	queue_ptr->tail = (queue_ptr->tail + 1) % queue_ptr->capacity;
	queue_ptr->data[queue_ptr->tail] = value;
	return (0);
}
