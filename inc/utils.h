#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <sys/types.h>
# include <stdbool.h>

size_t	ft_strlen(const char *s);
int		ft_putstr_fd(int fd, const char *s);
int		ft_atoi(const char *s);
bool	ft_isspace(int c);
bool	ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
size_t	number_size(int nb);
void	ft_itostr(int n, char str[12]);

#endif
