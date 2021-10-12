/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/12 21:39:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stack.h>
#include <stdlib.h>

int	checker_ok(t_stack **a_ptr, t_stack **b_ptr)
{
	write(1, "OK\n", 3);
	free(*a_ptr);
	*a_ptr = NULL;
	free(*b_ptr);
	*b_ptr = NULL;
	return (0);
}

int	checker_ko(t_stack **a_ptr, t_stack **b_ptr)
{
	write(1, "KO\n", 3);
	free(*a_ptr);
	*a_ptr = NULL;
	free(*b_ptr);
	*b_ptr = NULL;
	return (0);
}
