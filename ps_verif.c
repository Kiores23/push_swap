
#include "push_swap.h"

int	ps_verif(char **a, int size)
{
	int i;

	i = 0;
	while (i < size && ft_isnumber(a[i]))
		i++;
	if (i < size)
		return (0);
	return (1);
}