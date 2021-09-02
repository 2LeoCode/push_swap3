#include <queue_int.h>

const char	*dequeue(t_queue *queue_ptr)
{
	const char	*value;

	if (!queue_ptr->size)
		return (QUEUE_EMPTY);
	--queue_ptr->size;
	value = queue_ptr->data[queue_ptr->head];
	queue_ptr->data[queue_ptr->head] = NULL;
	queue_ptr->head = (queue_ptr->head + 1) % queue_ptr->capacity;
	return (value);
}
