/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qclear.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue_int.h>

void	qclear(t_queue *queue_ptr)
{
	while (queue_ptr->head != queue_ptr->tail)
	{
		queue_ptr->data[queue_ptr->head] = NULL;
		queue_ptr->head = (queue_ptr->head + 1) % queue_ptr->capacity;
	}
	queue_ptr->size = 0;
	queue_ptr->head = 0;
	queue_ptr->tail = queue_ptr->capacity;
}
