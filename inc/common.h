/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:27:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/05 16:17:03 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <sys/types.h>
# include <stdint.h>

# include "stack.h"
# include "instructions.h"
# include "utils.h"

# define INVALID_INPUT ~0UL

typedef void	(*t_errfun)(void);

size_t		get_stack_size(int ac, const char **av);
t_errfun	fill_stack(t_stack *sa, int ac, const char **av);
int			alloc_stacks(t_stack **sa_ptr, t_stack **sb_ptr, size_t size);

int			ft_failure(void (*except), t_stack **sa_ptr, t_stack **sb_ptr);
int			ft_exception(void (*except)());
void		invalid_arguments(void);
void		out_of_memory(void);
void		duplicate_element(void);

#endif
