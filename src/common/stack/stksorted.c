/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stksorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:29:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/29 19:34:03 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

bool	stksorted(t_stack *stack_ptr)
{
	int	*ptr;

	ptr = stkrend(stack_ptr);
	while (++ptr != stkrbegin(stack_ptr))
		if (*ptr > *(ptr + 1))
			return (false);
	return (true);
}
