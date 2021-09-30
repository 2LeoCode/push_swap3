/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkfull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/29 19:33:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

bool	stkfull(const t_stack *stack_ptr)
{
	return (stack_ptr->size == stack_ptr->capacity);
}
