/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:43 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/11 19:16:09 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <sys/types.h>
# include <stdbool.h>

size_t			ft_strlen(const char *s);
int				ft_putstr_fd(int fd, const char *s);
int				ft_atoi(const char *s);
bool			ft_isspace(int c);
bool			ft_isdigit(int c);
void			*ft_memcpy(void *dst, const void *src, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
size_t			number_size(int nb);
void			ft_itostr(int n, char str[12]);
void			*ft_cmemset(void *dst, const void *src, size_t size,
					size_t nmemb);
char			*ft_strdup(const char *s);
void			ft_bzero(void *m, size_t n);
unsigned int	ft_abs(int n);
int				ft_nbcount(const char *s);
int				ft_memcmp(const void *a, const void *b, size_t size);

#endif
