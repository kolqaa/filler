#include "filler.h"

int	ft_sqrt(int nb)
{
	int i;
	int b;

	i = 1;
	while (i <= nb / 2)
	{
		b = i * i;
		if (b >= nb)
			return (i);
		i++;
	}
	return (0);
}