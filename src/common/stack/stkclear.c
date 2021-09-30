/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/29 19:33:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

void	stkclear(t_stack *stack_ptr)
{
	stack_ptr->size = 0;
	stack_ptr->begin = stack_ptr->end;
}
