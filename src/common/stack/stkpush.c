/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkpush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/29 19:33:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	stkpush(t_stack *stack_ptr, int value)
{
	int	*it;

	if (stack_ptr->size == stack_ptr->capacity)
		return (STACK_FULL);
	it = stack_ptr->begin - 1;
	while (++it != stack_ptr->end)
		if (*it == value)
			return (STACK_DUPLICATE);
	*--stack_ptr->begin = value;
	++stack_ptr->size;
	return (0);
}
