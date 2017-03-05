#include "filler.h"

int take_cor_where_to_put(t_fig *fig, t_map *map, t_pla *player, t_check *test)
{
	ft_putstr_fd("in to put\n", test->fd);
	int i;
	int j;

	i = 0;
	if (fig->fcol > map->col || fig->frow > map->row)
		return (0);
	while (i < (map->col - fig->fcol + 1))
	{
		j = 0;
		while (j < (map->row - fig->frow + 1))
		{
				/*ft_putstr_fd("i -->>> ", test->fd);
				ft_putnbr_fd(i, test->fd);
				ft_putchar_fd('\n', test->fd);
				ft_putstr_fd("j -->>> ", test->fd);
				ft_putnbr_fd(j, test->fd);
				ft_putchar_fd('\n', test->fd);*/
			check_put(fig, map, i, j, player, test); //possible to put? and choose best coordin
			j++;
		}
		i++;
	}
	if (map->lst == NULL)
		return (0);
	return (1);
}
