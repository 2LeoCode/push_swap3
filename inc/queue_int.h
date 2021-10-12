/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:16:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_INT_H
# define QUEUE_INT_H

# include <stdint.h>
# include <sys/types.h>

# include <queue.h>

struct s_queue
{
	unsigned int	head;
	unsigned int	tail;
	size_t			size;
	size_t			capacity;
	const char		*data[];
};

#endif
