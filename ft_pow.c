#include "filler.h"

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
	{
		nb = 1;
		return (nb);
	}
	else
	{
		return (nb * ft_pow(nb, power - 1));
	}
}