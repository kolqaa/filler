#include "filler.h"

void	analyze_fig(t_fig *fig, t_map *map, t_check *test)
{
	ft_putstr_fd("ANALYZE FIG\n", test->fd);
	int i;
	int j;
	int countj;
	int counti;

	i = 0;
	while (fig->figmap[i])
	{
		j = 0;
		countj = 0;
		while (fig->figmap[i][j])
		{
			if (fig->figmap[i][j] == '*')
				countj++;
			j++;
		}
		if (countj > map->hor)
			map->hor = countj;
		i++;
	}
	i = 0;
	j = 0;
	while (fig->figmap[i][j])
	{

		counti = 0;
		while (fig->figmap[i])
		{
			if (fig->figmap[i][j] == '*')
				counti++;
			i++;
			if (i == fig->fcol)
				break;
		}
		if (counti > map->ver)
			map->ver = counti;
		i = 0;
		j++;
	}
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("vertical ", test->fd);
	ft_putnbr_fd(map->ver, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("horizont ", test->fd);
	ft_putnbr_fd(map->hor, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("EXIT ANALYZ\n", test->fd);
}