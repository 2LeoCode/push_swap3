/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <stdlib.h>

int	alloc_stacks(t_stack **sa_ptr, t_stack **sb_ptr, size_t size)
{
	*sa_ptr = stkalloc(size);
	if (!*sa_ptr)
		return (-1);
	*sb_ptr = stkalloc(size);
	if (*sb_ptr)
		return (0);
	free(*sa_ptr);
	*sa_ptr = NULL;
	return (-1);
}
