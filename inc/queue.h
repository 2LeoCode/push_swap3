/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:16:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdbool.h>
# include <stdlib.h>

# define QUEUE_FULL 1
# define QUEUE_EMPTY NULL

typedef struct s_queue	t_queue;

t_queue				*qalloc(size_t size);

int					enqueue(t_queue *queue_ptr, const char *value);
const char			*dequeue(t_queue *queue_ptr);
void				qclear(t_queue *queue_ptr);

bool				qempty(const t_queue *queue_ptr);
bool				qfull(const t_queue *queue_ptr);
size_t				qsize(const t_queue *queue_ptr);
const char			*qnext(const t_queue *queue_ptr);

t_queue				*qdup(const t_queue *queue_ptr);

#endif
