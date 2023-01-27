
#include "push_swap_utils.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	while (++i && (-10 <= nbr || nbr <= 10))
		nbr /= 10;
	return (i);
}