#include "push_swap_utils.h"

void	ft_bzero(int *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}