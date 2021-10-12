/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:19:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/05 11:29:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	stkmax(const t_stack *stack_ptr)
{
	const int	*ptr = stack_ptr->begin;
	int			max;

	if (!stack_ptr->size)
		return (INT_MIN);
	max = *ptr;
	while (++ptr != stack_ptr->end)
	{
		if (*ptr > max)
			max = *ptr;
	}
	return (max);
}
