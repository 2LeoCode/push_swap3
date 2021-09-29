#include <stdbool.h>

bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\b' && c <= '\r'));
}
