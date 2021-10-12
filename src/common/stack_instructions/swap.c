/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:18:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:18:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

const char	*sa(t_stack *a, t_stack *b)
{
	int	*begin;
	int	x;

	if (!a || !b)
		return ("sa");
	(void)b;
	if (stksize(a) < 2)
		return (NULL);
	begin = stkbegin(a);
	x = *begin;
	*begin = *(begin + 1);
	*(begin + 1) = x;
	return (NULL);
}

const char	*sb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("sb");
	return (sa(b, a));
}

const char	*ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ("ss");
	sa(a, b);
	sb(a, b);
	return (NULL);
}
