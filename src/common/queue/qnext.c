#include <queue_int.h>

const char	*qnext(const t_queue *queue_ptr)
{
	if (!queue_ptr->size)
		return (QUEUE_EMPTY);
	return (queue_ptr->data[queue_ptr->head]);
}
