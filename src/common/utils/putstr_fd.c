#include <utils.h>
#include <unistd.h>

int	ft_putstr_fd(int fd, const char *s)
{
	return (write(fd, s, ft_strlen(s)));
}
