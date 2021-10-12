/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:19:58 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

const char	*pa(t_stack *a, t_stack *b)
{
	int	x;

	if (!a || !b)
		return ("pa");
	x = stkpop(b);
	if (x != STACK_EMPTY)
		stkpush(a, x);
	return (NULL);
}

const char	*pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("pb");
	return (pa(b, a));
}
