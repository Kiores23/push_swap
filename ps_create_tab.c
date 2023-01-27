
#include "push_swap.h"

int free_tab(t_tab ab)
{
	if (ab.a)
		free(ab.a);
	if (ab.b)
		free(ab.b);
	return (0);
}

#include <stdio.h>

int *create_a(char **tab, int size)
{
	int *a;
	int i;

	a = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		a[i] = ft_atoi(tab[i]);
	return (a);
}

int *create_b(int size)
{
	int *b;

	b = malloc(sizeof(int) * size);
	ft_bzero(b, size);
	return (b);
}