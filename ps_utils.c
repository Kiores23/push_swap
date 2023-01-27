
#include "push_swap.h"

int *get_next_smaller(int *tab, int size)
{
	static int  init = 0;
	static int  n = 0;
	int 		i;
	int 		tmp;
	int			tmp2;

	i = 0;
	tmp2 = n;
	while (!init && ++i < size)
	{
		if (tab[i] > tab[n])
			n = i;
	}
	while (init && i < size && tab[i] >= tab[n])
		i++;
	tmp = i;
	while (init && ++i < size)
	{
		if (tab[i] < tab[n] && tab[tmp] < tab[i])
			tmp = i;
		if (i + 1 == size)
			n = tmp;
	}
	init = 1;
	if (n = tmp2)
		return (NULL);
	return (&tab[n]);
}