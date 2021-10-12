/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qdup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue_int.h>

t_queue	*qdup(const t_queue *queue_ptr)
{
	t_queue			*new_ptr;
	unsigned int	i;

	new_ptr = malloc(sizeof(t_queue) + sizeof(char *) * queue_ptr->capacity);
	if (!new_ptr)
		return (NULL);
	new_ptr->size = queue_ptr->size;
	new_ptr->capacity = queue_ptr->capacity;
	new_ptr->head = queue_ptr->head;
	new_ptr->tail = queue_ptr->tail;
	i = -1;
	while (++i < new_ptr->capacity)
		new_ptr->data[i] = NULL;
	i = new_ptr->head;
	while (i != new_ptr->tail)
	{
		new_ptr->data[i] = queue_ptr->data[i];
		i = (i + 1) % new_ptr->capacity;
	}
	new_ptr->data[i] = queue_ptr->data[i];
	return (new_ptr);
}
