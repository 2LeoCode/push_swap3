/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qnext.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue_int.h>

const char	*qnext(const t_queue *queue_ptr)
{
	if (!queue_ptr->size)
		return (QUEUE_EMPTY);
	return (queue_ptr->data[queue_ptr->head]);
}
