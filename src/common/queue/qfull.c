#include <queue_int.h>

bool	qfull(const t_queue *queue_ptr)
{
	return (queue_ptr->size == queue_ptr->capacity);
}
