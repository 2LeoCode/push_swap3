/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
