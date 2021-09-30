/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkbegin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/29 19:33:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	*stkbegin(t_stack *stack_ptr)
{
	return (stack_ptr->begin);
}

const int	*stkcbegin(const t_stack *stack_ptr)
{
	return ((const int *)stack_ptr->begin);
}

int	*stkrbegin(t_stack *stack_ptr)
{
	return (stack_ptr->end - 1);
}

const int	*stkrcbegin(const t_stack *stack_ptr)
{
	return ((const int *)(stack_ptr->end - 1));
}
