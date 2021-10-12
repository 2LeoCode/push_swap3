/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 17:16:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <sys/types.h>
# include <stdint.h>

# include "stack.h"
# include "common.h"
# include "get_next_line.h"
# include <stdio.h>

int		ft_exception(void (*except)());
void	invalid_arguments(void);
void	out_of_memory(void);
void	duplicate_element(void);

int		checker_ok(t_stack **sa_ptr, t_stack **sb_ptr);
int		checker_ko(t_stack **sa_ptr, t_stack **sb_ptr);

#endif
