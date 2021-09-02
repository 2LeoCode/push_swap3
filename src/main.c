#include <stack.h>
#include <queue.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>

#define FAIL_IF(expr);	if (expr)\
						{\
							free(stk);\
							stk = NULL;\
							ft_fputs("Allocation error");\
							return (-1);\
						}

char	*g_strvalues[] =	{"One", "Two", "Three", "Four", "Five",\
							"Six", "Seven", "Eight", "Nine", "Ten",\
							"Eleven", "Twelve", "Thirteen", "Fourteen",\
							"Fifteen", "Sixteen", "Seventeen", "Nineteen",\
							"Twenty"};
char	*g_errmsg[] =		{NULL, "Full", "Duplicate element"};

size_t	ft_strlen(const char *s)
{
	const char  *ptr = s;

	while (*ptr)
		ptr++;
	return ((size_t)ptr - (size_t)s);
}

int	ft_fputs(int fd, const char *s)
{
	int ret;
	
	if (!s)
		return (write(fd, "(null)\n", 7));
	ret = write(fd, s, ft_strlen(s));
	if (ret == -1 || write(fd, "\n", 1) == -1)
		return (-1);
	return (ret + 1);
}

int	test_values(int count)
{
	t_stack		*stk;
	t_queue		*queue;
	int			ret;

	if (count > 20)
	{
		ft_fputs(2, "20 is the maximum");
		return (-1);
	}
	stk = stkalloc(count);
	queue = qalloc(count);
	FAIL_IF(!stk ||!queue);
	for (int i = 0; i < count; i++)
	{
		ret = stkpush(stk, i);
		if (ret)
		{
			ft_fputs(2, "STACK ERROR");
			ft_fputs(2, g_errmsg[ret]);
			return (-1);
		}
		ret = enqueue(queue, g_strvalues[i]);
		if (ret)
		{
			ft_fputs(2, "QUEUE ERROR");
			ft_fputs(2, g_errmsg[ret]);
			return (-1);
		}
	}

	ft_fputs(1, "STACK\nExpected:");
	for (int i = count - 1; i >= 0; --i)
		write(1, (char []){i + 48, ',', ' '}, 1 + 2 * !!i);
	write(1, "\n", 1);
	ft_fputs(1, "Got:");
	for (int i = 0; i < count; ++i)
		printf("%d, ", stkpop(stk));
	printf("\n");
	ft_fputs(1, "QUEUE\nExpected:");
	for (int i = 0; i < count; ++i)
	{
		write(1, g_strvalues[i], ft_strlen(g_strvalues[i]));
		write(1, ", \n" + 2 * (i == count - 1), 2);
	}
	ft_fputs(1, "Got:");
	for (int i = 0; i < count; ++i)
		printf("%s, ", dequeue(queue));
	printf("\n");
	if (stkpop(stk) != STACK_EMPTY)
	{
		ft_fputs(2, "Error: Stack should be empty");
		return (-1);
	}
	if (dequeue(queue) != QUEUE_EMPTY)
	{
		ft_fputs(2, "Error: Queue should be empty");
		return (-1);
	}
	return (0);
}

int main(void)
{
	if (test_values(5) || test_values(10) || test_values(20))
		return (-1);
	return (0);
}
