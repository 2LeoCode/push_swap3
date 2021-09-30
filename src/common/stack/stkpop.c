/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/29 19:33:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	stkpop(t_stack *stack_ptr)
{
	if (!stack_ptr->size)
		return (STACK_EMPTY);
	--stack_ptr->size;
	return (*stack_ptr->begin++);
}
