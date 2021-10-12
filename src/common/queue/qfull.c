/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qfull.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue_int.h>

bool	qfull(const t_queue *queue_ptr)
{
	return (queue_ptr->size == queue_ptr->capacity);
}
