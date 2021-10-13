/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stksorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:29:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 10:53:00 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack_int.h>

bool	stksorted(const t_stack *stack_ptr)
{
	const int	*ptr = stkcbegin(stack_ptr);
	const int	*end = stkcend(stack_ptr);

	if (ptr != end)
		while (++ptr != end)
			if (*ptr < *(ptr - 1))
				return (false);
	return (true);
}
