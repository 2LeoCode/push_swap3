/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
