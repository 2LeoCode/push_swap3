/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:23:15 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/05 14:53:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	stkmin(const t_stack *stack_ptr)
{
	const int	*ptr = stack_ptr->begin;
	int			min;

	if (!stack_ptr->size)
		return (INT_MIN);
	min = *ptr;
	while (++ptr != stack_ptr->end)
	{
		if (*ptr < min)
			min = *ptr;
	}
	return (min);
}
