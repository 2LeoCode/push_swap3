/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/30 17:17:55 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	*stkend(t_stack *stack_ptr)
{
	return (stack_ptr->end);
}

const int	*stkcend(const t_stack *stack_ptr)
{
	return ((const int *)stack_ptr->end);
}

int	*stkrend(t_stack *stack_ptr)
{
	return (stack_ptr->begin - 1);
}

const int	*stkrcend(const t_stack *stack_ptr)
{
	return ((const int *)(stack_ptr->begin - 1));
}
