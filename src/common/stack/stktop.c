/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stktop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:17:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

int	stktop(const t_stack *stack_ptr)
{
	if (!stack_ptr->size)
		return (STACK_EMPTY);
	return (*stack_ptr->begin);
}
