/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:20 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue_int.h>

t_queue	*qalloc(size_t size)
{
	t_queue			*queue_ptr;
	unsigned int	i;

	queue_ptr = malloc(sizeof(t_queue) + size * sizeof(char *));
	if (!queue_ptr)
		return (NULL);
	i = -1;
	while (++i < size)
		queue_ptr->data[i] = NULL;
	queue_ptr->size = 0;
	queue_ptr->capacity = size;
	queue_ptr->head = 0;
	queue_ptr->tail = size - 1;
	return (queue_ptr);
}
